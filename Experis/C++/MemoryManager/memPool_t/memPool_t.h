#ifndef __MEMPOOL_T_H__
#define __MEMPOOL_T_H__

#include "../memManager_t/memManager_t.h"
#include "../memPage_t/memPage_t.h"
#include <stddef.h>
#include <vector>

using namespace std; /* vector<> */

class memPool_t:public memManager_t
{
	public:
		memPool_t();
		virtual ~memPool_t();
		virtual size_t	Read(void* _data, size_t _dataSize);	/* returns num of bytes read */
		virtual size_t 	Read(void* _data, size_t _dataSize, size_t _position);/* returns num of bytes read */
		virtual size_t	Write(const void* _data, size_t _dataSize);	/* returns num of bytes written */	
		virtual size_t 	Write(const void* _data, size_t _dataSize, size_t _position); /* returns num of bytes written */
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
		memPool_t(const memPool_t& memPool_t); 				//Non-copyable
		memPool_t&	operator= (const memPool_t& _mPool);	//Non-copyable
		vector<memPage_t*> 		m_vec;
};


#endif /* #ifndef __MEMPOOL_T_H__ */





