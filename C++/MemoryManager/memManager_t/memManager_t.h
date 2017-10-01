#ifndef __MEMMANAGER_T_H__
#define __MEMMANAGER_T_H__

#include <stddef.h>

class memManager_t
{
	public:
//		memManager_t();
//		virtual ~memManager_t(); /* TODO: check why when this defined get undefined reference */
		virtual size_t 	GetPosition() const = 0;
		virtual bool 	SetPosition(size_t _index) = 0;
		virtual bool 	IsEmpty() const = 0;
		virtual size_t	GetSize() const = 0;
		virtual size_t	Read(void* _data, size_t _dataSize) = 0;
		virtual size_t 	Read(void* _data, size_t _dataSize, size_t _position) = 0;
		virtual size_t	Write(const void* _data, size_t _dataSize) = 0;		
		virtual size_t 	Write(const void* _data, size_t _dataSize, size_t _position) = 0;
		virtual size_t	GetCapacity() const = 0;
		virtual void	SetCapacity(size_t _newPageSize) = 0;
	
//	private:
//		memManager_t(const memManager_t& _mMngr);//Non-copyable
//		memManager_t& operator=(const memManager_t& _mMngr);//Non-copyable
};



#endif /* #ifndef __MEMMANAGER_T_H__ */


