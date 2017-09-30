#include "memPool_t.h"

memPool_t::memPool_t(size_t _capacity)
{

	if (0 == _capacity)
	{
		m_capacity = 1;
	}
	else
	{
		m_capacity = _capacity;
	}
	
	memPage_t* mPage = new memPage_t(m_capacity);
	if (0 == mPage)
	{
		/*TODO: handle 'new' exception */
	}
	
	m_vec.push_back(mPage); // add new pointer to page to the end of vector ?
	
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



size_t 	memPool_t::GetPosition() const
{
	return 1;
}

bool 	memPool_t::SetPosition(size_t _index)
{
	return 1;
}

bool 	memPool_t::IsEmpty() const
{
	return 1;
}

size_t	memPool_t::GetSize() const
{
	return 1;
}

size_t	memPool_t::Read(void* _data, size_t _dataSize)
{
	return 1;
}

size_t 	memPool_t::Read(void* _data, size_t _dataSize, size_t _position)
{
	return 1;
}

size_t	memPool_t::Write(const void* _data, size_t _dataSize)
{
	return 1;
}

size_t 	memPool_t::Write(const void* _data, size_t _dataSize, size_t _position)
{
	return 1;
}

size_t	memPool_t::GetCapacity() const
{
	return 1;
}

void	memPool_t::SetCapacity(size_t _newPageSize)
{
	return;
}

		





















