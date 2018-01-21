#include "TemplateSingleton.h"
namespace advcpp
{

T* TemplateSingleton::sngPtr = 0;

void TemplateSingleton::Destroy()	
{ 
	if (m_instancePtr != 0)
	{
		delete m_instancePtr; 
		m_instancePtr = 0; 
	}
}	

T* TemplateSingleton::Create() 
{ 
	if (m_instancePtr == 0)	
	{ 
		m_instancePtr = new T; 
	} 
	return m_instancePtr; 
} 



















}//namespace advcpp


