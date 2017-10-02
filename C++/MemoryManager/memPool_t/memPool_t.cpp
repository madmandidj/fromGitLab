#include "memPool_t.h"



memPool_t::memPool_t()
{
	memPage_t* mPage = new memPage_t();
	
	if (0 == mPage)
	{
		/*TODO: handle 'new' exception */
	}
	
	m_vec.push_back(mPage);
	
	m_size = 0;
	
	m_position = 0;
}



memPool_t::~memPool_t()
{
	size_t index;
	
	for (index = m_vec.size();index > 0; --index)
	{	
		delete m_vec.at(index - 1);
		
		m_vec.pop_back();
	}
}



size_t	memPool_t::Read(void* _data, size_t _dataSize)
{		
	return Read(_data, _dataSize, m_position);
}



size_t 	memPool_t::Read(void* _data, size_t _dataSize, size_t _position)
{
	if (NULL == _data || 0 == _dataSize || _position >= m_size)
	{
		return 0; /* invalid args or position of out range */
	}
	
	size_t readPageNum = 0;
	
	size_t readOffset = 0; /*TODO: use _position and [] operator for vector */
	
	memPage_t* mPage;
	
	if (0 == _position)
	{
		mPage = m_vec.at(readPageNum);
		readOffset = mPage->GetCapacity();
	}
	
	while(readOffset < _position)
	{
		mPage = m_vec.at(readPageNum);
		readOffset += mPage->GetCapacity();
		++readPageNum;
	}
	
	size_t result = mPage->Read(_data, _dataSize, readOffset - mPage->GetCapacity() + _position);
	
	m_position = _position + result;
	
	/*
	TODO: handle case when result != _dataSize
	*/
	if (result != _dataSize)
	{
		mPage = m_vec.at(readPageNum);
		
		result += mPage->Read((char*)_data + result, _dataSize - result, 0);
		
		m_position = _position + result;
	}
	
	return result;
}



size_t	memPool_t::Write(const void* _data, size_t _dataSize)
{
	return Write(_data, _dataSize, m_position);
}



size_t 	memPool_t::Write(const void* _data, size_t _dataSize, size_t _position)
{
	if (NULL == _data || 0 == _dataSize || _position > m_size)
	{
		return 0;
	}

	size_t writePageNum = 0;
	
	size_t writeOffset = 0;
	
	memPage_t* mPage;
	
	if (0 == _position)
	{
		mPage = m_vec.at(writePageNum);
		writeOffset = mPage->GetCapacity();
	}
	
	while(writeOffset < _position)
	{
		mPage = m_vec.at(writePageNum);
		writeOffset += mPage->GetCapacity();
		++writePageNum;
	}
	
	size_t result = mPage->Write(_data, _dataSize, writeOffset - mPage->GetCapacity() + _position);

	m_position = _position + result;
	
	if (m_position > m_size)
	{
		m_size = m_position;
	}
	
	if (result != _dataSize)
	{
		if (m_vec.size() >= writePageNum)
		{
			memPage_t* mPage2 = new memPage_t();
	
			if (0 == mPage)
			{
				/*TODO: handle 'new' exception */
			}
			
			result += mPage2->Write((char*)_data + result, _dataSize - result, 0);
	
			m_vec.push_back(mPage2);
			
		}
		else
		{
			mPage = m_vec.at(writePageNum);
		
			result += mPage->Write((char*)_data + result, _dataSize - result, 0);
		}
		
		m_position += result;
		m_size = m_position;
	}

	/*TODO: handle overflow */
	
	return result;
	
}




