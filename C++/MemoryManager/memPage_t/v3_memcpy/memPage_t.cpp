#include "memPage_t.h"
#include <string.h> 	/* memcpy */


//memPage_t::memPage_t(size_t _capacity)
//{
//	if (0 == _capacity)
//	{
//		m_capacity = 1;
//	}
//	else
//	{
//		m_capacity = _capacity;
//	}
//	
//	m_buf = new char[m_capacity];
//	if (0 == m_buf)
//	{
//		/*TODO: handle 'new' exception */
//	}
//	
//	m_size = 0;
//	m_position = 0;
//}

size_t memPage_t::GetCapacity() const
{
	return m_capacity;
}


void memPage_t::SetCapacity(size_t _newPageSize)
{
	if (0 == _newPageSize)
	{
		m_capacity = 1;
	}
	else
	{
		m_capacity == _newPageSize;
	}
	
	return;
}


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
	
	m_buf = new char[m_capacity];
	if (0 == m_buf)
	{
		/*TODO: handle 'new' exception */
	}
	
	m_size = 0;
	m_position = 0;
}



memPage_t::~memPage_t()
{
	delete[] m_buf;
}



size_t memPage_t::Read(void* _data, size_t _dataSize)
{
		size_t index;
		if (NULL == _data || 0 == _dataSize)
		{
			return 0;
		}
		
		
		if (m_position + _dataSize > m_size)
		{
			memcpy(_data, m_buf + m_position, m_size - _dataSize + 1);
			
			return m_size - _dataSize + 1; /* return amount of bytes read */
		}
		
		memcpy(_data, m_buf + m_position, _dataSize);
		
//		for (index = m_position; index < m_position + _dataSize; ++index)
//		{
//			((char*)_data)[index - m_position] = m_buf[index];
//		}
		
		m_position += _dataSize;
		
		return _dataSize; /* return amount of bytes read */
}



size_t memPage_t::Read(void* _data, size_t _dataSize, size_t _position)
{
	/*TODO: implement*/
	return true;
}



size_t memPage_t::Write(const void* _data, size_t _dataSize)
{
	size_t index;
		
	if (NULL == _data || 0 == _dataSize || m_size + m_position > m_capacity)
	{
		return false;
	}
	
	for (index = m_position; index < m_position + _dataSize; ++index)
	{
		m_buf[index] = ((char*)_data)[index - m_position];
	}
	
	m_size = index;
	
	m_position = index;
}



size_t memPage_t::Write(const void* _data, size_t _dataSize, size_t _position)
{
	/*TODO: implement*/
	return true;
}



size_t memPage_t::GetPosition() const
{
	return m_position;
}



bool memPage_t::SetPosition(size_t _index)
{
	if (_index > m_size || _index >= m_capacity)
	{
		return false;
	}
	
	m_position = _index;
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




