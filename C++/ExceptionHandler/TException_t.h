#ifndef __TEXCEPTION_T_H__
#define __TEXCEPTION_T_H__

#include <iostream>
#include <string>

/********************************************************************************
Test for this file is included in MemoryManager exercise for function SetPosition 
********************************************************************************/

template <class T> 
class TException_t
{
	public:
		TException_t(T* const _object, const std::string& _description, const std::string& _sourceFileName, size_t _lineNumber);
		TException_t(const TException_t& _tException);
		TException_t& operator= (const TException_t& _tException);
		~TException_t();
		
		T* GetObject() const;
		std::string& GetDescription();
		std::string& GetSourceFileName();
		size_t GetLineNumber() const;
		
	private:
		T* 				m_object;
		std::string		m_description;
		std::string		m_sourceFileName;
		size_t 			m_lineNumber;
};


template <class T>
std::ostream& operator<< (std::ostream& _os, TException_t<T>& _tException)
{
	_os << "Description: " << _tException.GetDescription() << ", File: " << _tException.GetSourceFileName() << ", Line: " << _tException.GetLineNumber() << std::endl;
	
	return _os;
}


template <class T>
TException_t<T>::TException_t(T* const _object, const std::string& _description, const std::string& _sourceFileName, size_t _lineNumber)
{
	if (0 == _object)
	{
		/* TODO: handle invalid pointer */
	}
	
	m_object = _object;
	
	m_description.assign(_description);
	
	m_sourceFileName.assign(_sourceFileName);
	
	m_lineNumber = _lineNumber;
}


template <class T>
TException_t<T>::TException_t(const TException_t& _tException)
{	
	m_object = _tException.m_object;
	
	m_description.assign(_tException.m_description);
	
	m_sourceFileName.assign(_tException.m_sourceFileName);
	
	m_lineNumber = _tException.m_lineNumber;
}


template <class T>
TException_t<T>& TException_t<T>::operator= (const TException_t& _tException)
{	
	if (this != &_tException)
	{
		m_object = _tException.m_object;
	
		m_description.assign(_tException.m_description);
	
		m_sourceFileName.assign(_tException.m_sourceFileName);
	
		m_lineNumber = _tException.m_lineNumber;
	}
	
	return *this;
}


template <class T>
TException_t<T>::~TException_t(){}


template <class T>
T* TException_t<T>::GetObject() const
{
	return m_object;
}


template <class T>
std::string& TException_t<T>::GetDescription()
{
	return m_description;
}


template <class T>
std::string& TException_t<T>::GetSourceFileName()
{
	return m_sourceFileName;
}


template <class T>
size_t TException_t<T>::GetLineNumber() const
{
	return m_lineNumber;
}





#endif /* #ifndef __TEXCEPTION_T_H__ */







