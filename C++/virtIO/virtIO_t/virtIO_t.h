#ifndef __VIRTIO_T_H__
#define __VIRTIO_T_H__

#include <stdio.h>
#include <string>

using namespace std;

class virtIO_t
{
	public:
		enum FileStatus
		{
			ok_e,
			cant_open_file_e,
			bad_access_e,
			writeErr_e,
			readErr_e
		};
		
		virtIO_t();
		
		virtIO_t(const string& _fileName, const string& _mode);
		
		virtual ~virtIO_t() = 0;
		
		FileStatus Open(const string& _fileName, const string& _mode);
		
		void Close();
		
		const string& GetFileName() const;
		
		string GetMode() const;
		
		FileStatus GetStatus() const;
		
		size_t GetFileLength();
		
		virtual virtIO_t& operator>> (char& _char) = 0;
		
		virtual virtIO_t& operator<< (const char& _char) = 0;
		
	protected:
		FILE* m_fp;
	
		void SetFileName(const string& _fileName); //TODO: Implement if needed
	
		void SetMode(const string& _mode); //TODO: Implement if needed
		
		void SetStatus(const FileStatus& _status);
		
		void SetDataMembersDefaultValues();
		
	private:
		virtIO_t(const virtIO_t& _virtIO_t);
		
		virtIO_t& operator= (const virtIO_t& _virtIO_t);
		
		string		m_fileName;	
		
		string		m_mode;
		
		FileStatus	m_status;	
};



#endif /* #ifndef __VIRTIO_T_H__ */






