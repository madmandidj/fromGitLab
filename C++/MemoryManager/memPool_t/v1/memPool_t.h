#ifndef __MEMPOOL_T_H__
#define __MEMPOOL_T_H__

#include "../memManager_t/memManager_t.h"
//class memPage_t;
#include "../memPage_t/memPage_t.h"
#include <stddef.h>
#include <vector>

using namespace std; /* vector<> */




class memPool_t:public memManager_t
{
	public:
		memPool_t(size_t _capacity = 1024);
		~memPool_t();
		
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
		
	private:
		memPool_t(const memPool_t& memPool_t); 				//Forbidden so placed in private
		memPool_t&	operator= (const memPool_t& _mPool);	//Forbidden so placed in private
		vector<memPage_t*> 			m_vec;
		size_t						m_size;
		size_t 						m_capacity;
		size_t						m_position;
};






















#endif /* #ifndef __MEMPOOL_T_H__ */


































































