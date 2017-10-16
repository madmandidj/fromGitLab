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
		
		string GetMode() const;
		
		FileStatus GetStatus() const;
		
		size_t GetFileLength() const;
		
		void SetToStartPosition() const;
		
		int GetPosition() const;
		
		*********
		********/
		
		enum CommaMode
		{
			NONE,
			READ,
			WRITE
		};
		
		binIO_t();
		
		binIO_t(const string& _fileName, const string& _mode);
		
		virtual ~binIO_t();
		
		virtual binIO_t& operator>> (char& _char);			
		
		virtual binIO_t& operator<< (const char& _char);
		
		virtual binIO_t& operator>> (int& _int);
		
		virtual binIO_t& operator<< (const int& _int);
		
		virtual binIO_t& operator>> (float& _float);		
		
		virtual binIO_t& operator<< (const float& _float);	
		
		binIO_t& operator>> (void* _buf);
		
		binIO_t& operator<< (const void* _buf);
		
		binIO_t& operator, (int _len);
		
	protected:
		/******** Inherited from virtIO_t
		*********
		
		FILE* m_fp;
	
		void SetFileName(string _fileName);
	
		void SetMode(string _mode);
		
		void SetStatus(FileStatus _status);
		
		void SetDataMembersDefaultValues();
		
		*********
		********/
		
		bool IsReadMode() const;
		
		bool IsWriteMode() const;
		
		template<class T>
		binIO_t& MyRead(T& _t);
		
		template<class T>
		binIO_t& MyWrite(T& _t);
		
		void* 		m_buf;
		
		CommaMode	m_commaMode;
		
	private:
		binIO_t(const binIO_t& _binIO_t);
		
		binIO_t& operator= (const binIO_t& _binIO_t);
};


template<class T>
binIO_t& binIO_t::MyRead(T& _t)
{
	if ((0 != m_fp) && (IsReadMode()))
	{
		m_commaMode = READ;
		
		int result = fread(&_t, sizeof(T), 1, m_fp);
		
		if (ferror(m_fp))
		{
			m_commaMode = NONE;
			
			throw(result);
		}
	}
	
	return *this;
}


template<class T>
binIO_t& binIO_t::MyWrite(T& _t)
{
	if ((0 != m_fp) && (IsWriteMode()))
	{
		m_commaMode = WRITE;
		
		int result = fwrite(&_t, sizeof(T), 1, m_fp);
		
		if (ferror(m_fp))
		{
			m_commaMode = NONE;
			
			throw(result);
		}
	}
	
	return *this;
}


#endif /* #ifndef __BINIO_H__ */














