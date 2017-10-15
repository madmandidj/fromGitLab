#ifndef __BINIO_H__
#define __BINIO_H__




#include "../virtIO_t/virtIO_t.h"
#include <string>

using namespace std;

class binIO_t : public virtIO_t
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
		binIO_t();
		
		binIO_t(const string& _fileName, const string& _mode);
		
		virtual ~binIO_t();
		
		virtual binIO_t& operator>> (char& _char);
		
		virtual binIO_t& operator<< (const char& _char);	
		
		/* TODO:
		binIO_t& operator>> (void* _buf);
		binIO_t& operator<< (const void* _buf);	
		void operator, (int _len);
		*/
		
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
		
		void* 	m_buf;
		
		size_t 	m_size;
		
		size_t 	m_count;
		
	private:
		binIO_t(const binIO_t& _binIO_t);
		
		binIO_t& operator= (const binIO_t& _binIO_t);
};












#endif /* #ifndef __BINIO_H__ */














