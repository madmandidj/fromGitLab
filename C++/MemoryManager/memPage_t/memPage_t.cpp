#include "memPage_t.h"



memPage_t::memPage_t(size_t _capacity)
{
	if (0 == _capacity)
	{
		m_capacity = 1;
	}
	else
	{
		m_capacity = _capacity;
	}
	
	m_buf = new unsigned char[m_capacity];
	if (0 == m_buf)
	{
		/*TODO: handle 'new' exception */
	}
	
	m_size = 0;
	m_curPosition = 0;
}



memPage_t::~memPage_t()
{
	delete[] m_buf;
}



bool memPage_t::Read(void* _data, size_t _dataSize)
{
		size_t index;
		
		if (NULL == _data || 0 == _dataSize || m_size + m_curPosition > m_capacity)
		{
			return false;
		}
		
		for (index = m_curPosition; index < m_curPosition + _dataSize; ++index)
		{
			((unsigned char*)_data)[index - m_curPosition] = m_buf[index];
		}
		
		m_curPosition = index;
		
		return true;
}



bool memPage_t::Read(void* _data, size_t _dataSize, size_t _position)
{
	/*TODO: implement*/
	return true;
}



bool memPage_t::Write(const void* _data, size_t _dataSize)
{
	size_t index;
		
	if (NULL == _data || 0 == _dataSize || m_size + m_curPosition > m_capacity)
	{
		return false;
	}
	
	for (index = m_curPosition; index < m_curPosition + _dataSize; ++index)
	{
		m_buf[index] = ((unsigned char*)_data)[index - m_curPosition];
	}
	
	m_size = index;
	
	m_curPosition = index;
}



bool memPage_t::Write(const void* _data, size_t _dataSize, size_t _position)
{
	/*TODO: implement*/
	return true;
}



size_t memPage_t::GetPosition() const
{
	return m_curPosition;
}



bool memPage_t::SetPosition(size_t _index)
{
	if (_index > m_size || _index >= m_capacity)
	{
		return false;
	}
	
	m_curPosition = _index;
}



size_t memPage_t::GetSize() const
{
	return m_size;
}



bool memPage_t::IsEmpty() const
{
	/*TODO: implement*/
	return true;
}



