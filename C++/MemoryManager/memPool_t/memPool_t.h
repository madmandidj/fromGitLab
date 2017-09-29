#ifndef __MEMPOOL_T_H__
#define __MEMPOOL_T_H__

#include <stddef.h>




class memPool_t
{
	public:
		memPool_t();
		~memPool_t();
		size_t 	GetPoolPosition();
		bool	SetPoolPosition(size_t _index);
		bool	IsPoolEmpty() const;
		size_t	GetPoolSize() const;
		bool 	ReadFromPool(void* _data, size_t _dataSize);
//		bool 	ReadFromPool(char* _data, size_t _dataSize, size_t _position) const;
		bool 	WriteToPool(void* _data, size_t _dataSize);
//		bool 	WriteToPool(char* _data, size_t _dataSize, size_t _position) const;
		size_t	GetDefaultPageSize() const;
		size_t	SetDefaultPageSize(size_t _newPageSize);
		
	private:
		memPool_t(const memPool_t& memPool_t); //Forbidden so placed in private
		size_t	m_size;
		size_t 	m_capacity;
		size_t	m_curPosition;
};






















#endif /* #ifndef __MEMPOOL_T_H__ */


































































