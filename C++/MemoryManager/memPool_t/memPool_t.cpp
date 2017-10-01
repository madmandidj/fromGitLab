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



//mPage* FindPage


size_t 	memPool_t::Read(void* _data, size_t _dataSize, size_t _position)
{
	if (NULL == _data || 0 == _dataSize || _position >= m_size)
	{
		return 0; /* invalid args or position of out range */
	}
	
	size_t readPageNum = 0;
	
	size_t readPosition = 0;
	
	memPage_t* mPage;
	
	if (0 == _position)
	{
		mPage = m_vec.at(readPageNum);
	}
	
	while(readPosition < _position)
	{
		mPage = m_vec.at(readPageNum);
		readPosition += mPage->GetCapacity();
		++readPageNum;
	}
	
	size_t result = mPage->Read(_data, _dataSize, mPage->GetCapacity() - readPosition);
	/*
	TODO: handle case when result != _dataSize
	*/
	
	m_position = readPosition + result;
	
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
	
	size_t writePosition = 0;
	
	memPage_t* mPage;
	
	if (0 == _position)
	{
		mPage = m_vec.at(writePageNum);
	}
	
	while(writePosition < _position)
	{
		mPage = m_vec.at(writePageNum);
		writePosition += mPage->GetCapacity();
		++writePageNum;
	}
	
	size_t result = mPage->Write(_data, _dataSize, _position);

	m_position = writePosition + result;
	
	if (m_position > m_size)
	{
		m_size = m_position;
	}

	/*TODO: handle overflow */
	
	return result;
	
}



//size_t	memPool_t::GetCapacity() const
//{
//	return 1;
//}



//void	memPool_t::SetCapacity(size_t _newPageSize)
//{
//	return;
//}




















