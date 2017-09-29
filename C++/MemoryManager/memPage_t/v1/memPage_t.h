#ifndef __MEMPAGE_T_H__
#define __MEMPAGE_T_H__

#include <stddef.h>


class memPage_t
{
	public:
		memPage_t(size_t _capacity = 1024);
//		memPage_t(const memPage_t& _mPage); //Forbidden
		~memPage_t();
		size_t 	GetPagePosition() const;
		bool	SetPagePosition(size_t _index);
		bool	IsPageEmpty() const;
		bool 	IsPageFull() const;
		size_t	GetPageSize() const;
		size_t	GetPageCapacity() const;
		bool 	ReadFromPage(void* _data, size_t _dataSize);
//		bool 	ReadFromPage(char* _data, size_t _dataSize, size_t _position) const;
		bool	WriteToPage(const void* _data, size_t _dataSize);
//		bool	WriteToPage(const char* _data, size_t _dataSize, size_t _position);
	
	private:
		memPage_t(const memPage_t& _mPage); //Forbidden so placed in private
		unsigned char* 	m_buf;
		size_t	m_size;
		size_t 	m_capacity;
		size_t	m_curPosition;
};






















#endif /* #ifndef __MEMPAGE_T_H__ */


































































