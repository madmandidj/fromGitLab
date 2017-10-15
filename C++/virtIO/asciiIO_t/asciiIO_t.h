#ifndef __ASCIIIO_H__
#define __ASCIIIO_H__

#include "../virtIO_t/virtIO_t.h"
#include <string>

using namespace std;

class asciiIO_t : public virtIO_t
{
	public:
		/******** Inhertied from virtIO_t
		*********

		FileStatus Open(const string& _fileName, const string& _mode);
		
		void Close();
		
		const string& GetFileName() const;
		
		const string& GetMode() const;
		
		FileStatus GetStatus() const;
		
		size_t GetFileLength();
		
		*********
		********/
		asciiIO_t();
		
		asciiIO_t(const string& _fileName, const string& _mode);
		
		virtual ~asciiIO_t();
		
		virtual asciiIO_t& operator>> (char& _char);
		
		virtual asciiIO_t& operator<< (const char& _char);		
		
	protected:
		/******** Inhertied from virtIO_t
		*********
		
		FILE* m_fp;
	
		void SetFileName(string _fileName);
	
		void SetMode(string _mode);
		
		void SetStatus(FileStatus _status);
		
		void SetDataMembersDefaultValues();
		
		*********
		********/
		
	private:
		asciiIO_t(const asciiIO_t& _asciiIO_t);
		
		asciiIO_t& operator= (const asciiIO_t& _asciiIO_t);
};








#endif /* #ifndef __ASCIIIO_H__ */




