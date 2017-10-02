#ifndef __MEMMANAGER_T_H__
#define __MEMMANAGER_T_H__

#include <stddef.h>

class memManager_t
{
	public:
		memManager_t();
		virtual ~memManager_t();
		virtual size_t	Read(void* _data, size_t _dataSize) = 0;
		virtual size_t 	Read(void* _data, size_t _dataSize, size_t _position) = 0;
		virtual size_t	Write(const void* _data, size_t _dataSize) = 0;		
		virtual size_t 	Write(const void* _data, size_t _dataSize, size_t _position) = 0;
		size_t 	GetPosition() const;
		bool 	SetPosition(size_t _index);
		bool 	IsEmpty() const;
		size_t	GetSize() const;
		
	protected:
		size_t m_size; /*  TODO: can be private and use protected functions to set these */
		size_t m_position;
	
	private:
		memManager_t(const memManager_t& _mMngr);//Non-copyable
		memManager_t& operator=(const memManager_t& _mMngr);//Non-copyable
};

inline memManager_t::memManager_t():m_size(0), m_position(0) {}

inline memManager_t::~memManager_t(){}

#endif /* #ifndef __MEMMANAGER_T_H__ */


