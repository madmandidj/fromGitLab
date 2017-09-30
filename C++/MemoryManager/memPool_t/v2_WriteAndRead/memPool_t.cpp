#include "memPool_t.h"



//size_t memPool_t::m_numOfPages = 0;



memPool_t::memPool_t(size_t _capacity)
{

	if (0 == _capacity)
	{
		m_pageCapacity = 1;
	}
	else
	{
		m_pageCapacity = _capacity;
	}
	
	memPage_t* mPage = new memPage_t(m_pageCapacity);
	if (0 == mPage)
	{
		/*TODO: handle 'new' exception */
	}
	
	m_vec.push_back(mPage); // add new pointer to page to the end of vector ?
	
	m_size = 0;
	
	m_position = 0;
	
	m_numOfPages = 1;
	
	m_poolCapacity = m_pageCapacity;
}



memPool_t::~memPool_t()
{
	size_t index;
	
	for (index = m_vec.size();index > 0; --index)
	{
		delete m_vec.at(index - 1);
		
		m_vec.pop_back();
		
		--m_numOfPages;
	}
}



size_t 	memPool_t::GetPosition() const
{
	return m_position;
}



bool 	memPool_t::SetPosition(size_t _index)
{
	if (_index > m_size)
	{
		m_position = m_size; /* this avoids holes in memory */
		 
		return false;
	}
	
	m_position = _index;
	
	return true;
}



bool 	memPool_t::IsEmpty() const
{
	if (0 == m_size)
	{
		return true;
	}	
	
	return false;
}



size_t	memPool_t::GetSize() const
{
	return m_size;
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
	
	size_t curPageNum = 0;
	
	while(_position / (m_pageCapacity - 1) > 0)
	{
		_position -= m_pageCapacity;
		++curPageNum;
	}
	
	memPage_t* mPage;
	
	mPage = m_vec.at(curPageNum);
	
	size_t result = mPage->Read(_data, _dataSize, _position);
	/*
	TODO: handle case when result != _dataSize
	*/
	
	m_position = _position + result;
	
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
	
	size_t curPageNum = 0;
	
	while(_position / (m_pageCapacity - 1) > 0)
	{
		_position -= m_pageCapacity;
		++curPageNum;
	}
	
	memPage_t* mPage;
	
	mPage = m_vec.at(curPageNum);
	
	size_t result = mPage->Write(_data, _dataSize, _position);
	/*
	TODO: handle case when result != _dataSize
	*/
	
	m_position = _position + result;
	
	if (m_position > m_size)
	{
		m_size = m_position;
	}
	
	return result;
	
}



size_t	memPool_t::GetCapacity() const
{
	return 1;
}



void	memPool_t::SetCapacity(size_t _newPageSize)
{
	return;
}

//		
//size_t memPool_t::GetNumOfPages() const
//{
//	return m_numOfPages;
//}




















