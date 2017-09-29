#ifndef __MEMORY_MANAGEMENT_H__
#define __MEMORY_MANAGEMENT_H__

#include <stddef.h>



class memManager_t
{
		/* cant be constructed */
		
		public:
			virtual ~memManager() = 0; /* pure virtual so all derived implement this */
			virtual /* return type */ GetCurPosition() const;
			virtual /* return type */ SetCurPosition() const;
			bool IsMemoryEmpty() const;
			size_t GetMemorySize() const;
			bool Write(const char* _data, size_t _dataSize);
			bool Write(const char* _data, size_t _dataSize, int _position);
			bool Read(char* _data, size_t _dataSize) const;
			bool Read(char* _data, size_t _dataSize, int _position) const;
		protected:
			size_t m_pageSize;
			size_t m_numOfPages;
			
		private:
		

};



class memPage_t
{
	public:
		memPage_t(size_t = 1024);
		memPage_t(const memPage_t& _mPage); //Forbidden
		~memPage_t();
		GetCurPosition()
		SetCurPosition()
		IsPageEmpty()
		IsPageFull()
		GetPageSize()
		GetPageCapacity()
		ReadFromPage()
		WriteToPage()
		

};



class memPool_t
{
	public:
		memPool_t();
		memPool_t(const memPool_t& _mPool); //Forbidden
		~memPool_t();
		GetCurPosition()
		SetCurPosition()
		IsPoolEmpty()
		GetPoolSize()
		ReadFromPool()
		WriteToPool()
		GetDefaultPageSize()
		SetDefaultPageSize()
		
};









#endif __MEMORY_MANAGEMENT_H__





