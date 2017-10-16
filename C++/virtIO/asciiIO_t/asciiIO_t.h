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
		
		virtual asciiIO_t& operator>> (int& _int);
		
		virtual asciiIO_t& operator<< (const int& _int);
		
		virtual asciiIO_t& operator>> (float& _float);		
		
		virtual asciiIO_t& operator<< (const float& _float);
		
	protected:
		/******** Inhertied from virtIO_t
		*********
		
		FILE* m_fp;
	
		void SetFileName(string _fileName);
	
		void SetMode(string _mode);
		
		void SetStatus(FileStatus _status);
		
		void SetDataMembersDefaultValues();
		
		size_t GetNumOfIntDigits(int _int) const;
		
		*********
		********/
		
		bool IsReadMode() const;
		
		bool IsWriteMode() const;
		
		size_t GetNumOfIntDigits(int _int) const;
		
		template<class T>
		asciiIO_t& MyRead(T& _t, const char* _format);
		
		template<class T>
		asciiIO_t& MyWrite(T& _t, const char* _format);

	private:
		asciiIO_t(const asciiIO_t& _asciiIO_t);
		
		asciiIO_t& operator= (const asciiIO_t& _asciiIO_t);
};


template<class T>
asciiIO_t& asciiIO_t::MyRead(T& _t, const char* _format)
{
	if ((0 != m_fp) && (IsReadMode()))
	{
		int result = fscanf(m_fp, _format, &_t);
	
		if (1 != result || ferror(m_fp))
		{
			throw(result);
		}
	}
	
	return *this;
}


template<class T>
asciiIO_t& asciiIO_t::MyWrite(T& _t, const char* _format)
{
	if ((0 != m_fp) && (IsWriteMode()))
	{
		int result = fprintf(m_fp, _format, _t);
		
		if (ferror(m_fp))
		{
			throw(result);
		}
	}
	
	return *this;
}





#endif /* #ifndef __ASCIIIO_H__ */




