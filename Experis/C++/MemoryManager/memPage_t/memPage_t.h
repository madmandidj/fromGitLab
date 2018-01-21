#ifndef __MEMPAGE_T_H__
#define __MEMPAGE_T_H__

#include "../memManager_t/memManager_t.h"
#include <stddef.h>


class memPage_t:public memManager_t
{
	public:
		memPage_t();
		virtual ~memPage_t();
		virtual size_t	Read(void* _data, size_t _dataSize);	/* returns num of bytes read */
		virtual size_t 	Read(void* _data, size_t _dataSize, size_t _position);/* returns num of bytes read */
		virtual size_t	Write(const void* _data, size_t _dataSize);	/* returns num of bytes written */	
		virtual size_t 	Write(const void* _data, size_t _dataSize, size_t _position); /* returns num of bytes written */	
		bool 			IsPageFull() const;
		size_t 			GetCapacity();
		static size_t	GetDefaultCapacity();
		static void		SetDefaultCapacity(size_t _newPageSize);
		/* Inherited from memManager_t */
		//		size_t 	GetPosition() const;
		//		bool 	SetPosition(size_t _index);
		//		bool 	IsEmpty() const;
		//		size_t	GetSize() const;
		
/* Inherited from memManager_t */
//	protected:
//		size_t m_size;
//		size_t m_position;
		
	private:
		memPage_t(const memPage_t& _mPage); 			//Non-copyable
		memPage_t&	operator= (const memPage_t& _mPage);//Non-copyable
		char* 			m_buf;
		size_t 			m_capacity;
		static size_t	m_defaultCap;
};



#endif /* #ifndef __MEMPAGE_T_H__ */


