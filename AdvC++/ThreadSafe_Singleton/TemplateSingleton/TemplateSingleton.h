#ifndef __TEMPLATE_SINGLETON_H__
#define __TEMPLATE_SINGLETON_H__

#include<tr1/memory>
#include<pthread.h>

namespace advcpp
{

template<class T>
class TemplateSingleton { 
private: 
	static T* m_instancePtr; 
//	static std::tr1::shared_ptr<T> m_instancePtr;
//	static pthread_mutex_t m_mutex;
//	static volatile int m_flag; //Doesnt need to be volatile
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

//template<class T>
//pthread_mutex_t TemplateSingleton<T>::m_mutex = PTHREAD_MUTEX_INITIALIZER;

//template<class T>
//std::tr1::shared_ptr<T> TemplateSingleton<T>::m_instancePtr;

//template<class T>
//volatile int TemplateSingleton<T>::m_flag = 0;

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
T* TemplateSingleton<T>::Create() //should be called GetInstance and not Create
{ 
	if (m_instancePtr == 0)	
	{ 
		m_instancePtr = new T; 
	} 
	
	
//	if (!m_flag)
//	{
//		Lock lock(&m_mutex);
//		if (!m_flag)
//		{
//			m_instancePtr = std::tr1::shared_ptr<T>(new T);
//			__sync_fetch_and_add(&m_flag,1);
//		}
//	}
	
	return m_instancePtr; 
} 




 
}//namespace advcpp
#endif//#ifndef __TEMPLATE_SINGLETON_H__



