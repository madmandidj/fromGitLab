#ifndef __MEMMANAGER_T_H__
#define __MEMMANAGER_T_H__

#include <stddef.h>
#include <iostream>
using namespace std;



class memManager_t
{
		/* cant be constructed */
		
		
		public:
			/* return type */ GetCurPosition() const;
			/* return type */ SetCurPosition() const;
			bool IsMemoryEmpty() const;
			size_t MemorySize() const;
			bool Write(const char* _data, size_t _dataSize);
			bool Write(const char* _data, size_t _dataSize, int _position);
			bool Read(char* _data, size_t _dataSize) const;
			bool Read(char* _data, size_t _dataSize, int _position) const;
			
			
		private:
		



};






















ostream&	operator<< (ostream& _os, const String_t& _str_t);
istream&	operator>> (istream& _is, String_t& _str_t);


#endif /* #ifndef __MEMMANAGER_T_H__ */















