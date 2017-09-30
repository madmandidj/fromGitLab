#ifndef __MEMPAGE_T_H__
#define __MEMPAGE_T_H__

#include "../memManager_t/memManager_t.h"
#include <stddef.h>


class memPage_t:public memManager_t
{

	public:
		memPage_t(size_t _capacity = 1024);
		~memPage_t();
//		~memManager_t();

		virtual size_t 	GetPosition() const;
		virtual bool 	SetPosition(size_t _index);
		virtual bool 	IsEmpty() const;
		virtual size_t	GetSize() const;
		virtual size_t	Read(void* _data, size_t _dataSize);	/* returns num of bytes read */
		virtual size_t 	Read(void* _data, size_t _dataSize, size_t _position);/* returns num of bytes read */
		virtual size_t	Write(const void* _data, size_t _dataSize);	/* returns num of bytes written */	
		virtual size_t 	Write(const void* _data, size_t _dataSize, size_t _position); /* returns num of bytes written */	
		virtual size_t	GetCapacity() const;
		virtual void	SetCapacity(size_t _newPageSize);
		bool 	IsPageFull() const;
		
	private:
		memPage_t(const memPage_t& _mPage); 			//Forbidden so placed in private
		memPage_t&	operator= (const memPage_t& _mPage);//Forbidden so placed in private
		char* 	m_buf;
		size_t	m_size;
		size_t 	m_capacity;
		size_t	m_position;
};






















#endif /* #ifndef __MEMPAGE_T_H__ */


































































