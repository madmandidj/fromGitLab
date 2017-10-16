#include "virtIO_t.h"


void virtIO_t::SetDataMembersDefaultValues()
{
	m_fp = 0;
	
	m_fileName = "";
	
	m_mode = "";
	
	m_status = cant_open_file_e;
	
	return;
}


virtIO_t::virtIO_t()
{
	SetDataMembersDefaultValues();
}


virtIO_t::virtIO_t(const string& _fileName, const string& _mode)
{
	Open(_fileName, _mode);
}


virtIO_t::~virtIO_t()
{
	if (0 != m_fp)
	{
		fclose(m_fp);
	}
}



virtIO_t::FileStatus virtIO_t::Open(const string& _fileName, const string& _mode)
{
	m_fileName = _fileName;
	
	m_mode = _mode;
	
	m_fp = fopen(m_fileName.c_str(), m_mode.c_str());
	
	m_status = (0 == m_fp) ? cant_open_file_e : ok_e;
	
	return m_status;
}


void virtIO_t::Close()
{
	fclose(m_fp);	
	
	SetDataMembersDefaultValues();
}


const string& virtIO_t::GetFileName() const
{
	return m_fileName;
}


string virtIO_t::GetMode() const
{
	return m_mode;
}


virtIO_t::FileStatus virtIO_t::GetStatus() const
{
	return m_status;
}


size_t virtIO_t::GetFileLength() const
{
	if (0 == m_fp)
	{
		return 0;
	}

	fseek(m_fp, 0, SEEK_END);

	return ftell(m_fp);
}


void virtIO_t::SetStatus(const FileStatus& _status)
{
	m_status = _status;
}



void virtIO_t::SetToStartPosition() const
{
	fseek(m_fp, 0, SEEK_SET);
	
	return;
}
















