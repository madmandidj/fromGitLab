#ifndef __MEMPAGE_T_H__
#define __MEMPAGE_T_H__

#include "../memManager_t/memManager_t.h"
#include <stddef.h>


class memPage_t:public memManager_t
{
	public:
		memPage_t(size_t _capacity = 1024);
		~memPage_t();
		
		virtual size_t 	GetPosition() const;
		virtual bool 	SetPosition(size_t _index);
		virtual bool 	IsEmpty() const;
		virtual size_t	GetSize() const;
		virtual bool	Read(void* _data, size_t _dataSize);
		virtual bool 	Read(void* _data, size_t _dataSize, size_t _position);
		virtual bool	Write(const void* _data, size_t _dataSize);		
		virtual bool 	Write(const void* _data, size_t _dataSize, size_t _position);
		bool 	IsPageFull() const;
	private:
		memPage_t(const memPage_t& _mPage); //Forbidden so placed in private
		unsigned char* 	m_buf;
		size_t	m_size;
		size_t 	m_capacity;
		size_t	m_curPosition;
};






















#endif /* #ifndef __MEMPAGE_T_H__ */


































































