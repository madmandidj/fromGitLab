#ifndef __MEMMANAGER_T_H__
#define __MEMMANAGER_T_H__

#include <stddef.h>

class memManager_t
{
	public:
		virtual size_t 	GetPosition() const = 0;
		virtual bool 	SetPosition(size_t _index) = 0;
		virtual bool 	IsEmpty() const = 0;
		virtual size_t	GetSize() const = 0;
		virtual bool	Read(void* _data, size_t _dataSize) = 0;
		virtual bool 	Read(void* _data, size_t _dataSize, size_t _position) = 0;
		virtual bool	Write(const void* _data, size_t _dataSize) = 0;		
		virtual bool 	Write(const void* _data, size_t _dataSize, size_t _position) = 0;
		
		
	protected:
//		size_t m_size;
		size_t m_pageCapacity;
//		size_t m_curPosition;
	
};










#endif /* #ifndef __MEMMANAGER_T_H__ */


