#ifndef __TEMPLATE_SINGLETON_H__
#define __TEMPLATE_SINGLETON_H__

namespace advcpp
{

template<class T>
class TemplateSingleton { 
private: 
	static T* m_instancePtr; 
public: 
	static void Destroy();
	static T* Create();
protected: 
	virtual ~TemplateSingleton(){} 
private: 
	TemplateSingleton(){}							//NA
	TemplateSingleton(const TemplateSingleton&);	//NA
	void operator=(TemplateSingleton&);				//NA
};


template<class T>
T* TemplateSingleton<T>::m_instancePtr = 0;

template<class T>
void TemplateSingleton<T>::Destroy()	
{ 
	if (m_instancePtr != 0)
	{
		delete m_instancePtr; 
		m_instancePtr = 0; 
	}
}	

template<class T>
T* TemplateSingleton<T>::Create() 
{ 
	if (m_instancePtr == 0)	
	{ 
		m_instancePtr = new T; 
	} 
	return m_instancePtr; 
} 




 
}//namespace advcpp
#endif//#ifndef __TEMPLATE_SINGLETON_H__



