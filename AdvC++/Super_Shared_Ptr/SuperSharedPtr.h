#ifndef __SUPER_SHARED_PTR__
#define __SUPER_SHARED_PTR__

#include<stddef.h>
namespace advcpp
{


template<class T>
class SharedPtr
{
public:
	~SharedPtr();
	SharedPtr();
	SharedPtr(T* _ptr);
	SharedPtr(const SharedPtr& _sp);
	SharedPtr& operator=(const SharedPtr& _sp);
	T* const GetPtr() const;
	T& operator*() const;
	T* const operator->() const;
	bool operator==(const SharedPtr& _sp);
	operator bool()const;
protected:

private:
	T* 			m_ptr;
	size_t* 	m_numOfOwners; 
	void CreateOwner(T* _ptr);
	void AddOwner(const SharedPtr& _sp);
	void RemoveOwner();
	void SetNullSP();

};
//////////////////////////////////////////////////////////////////////////////////////////
//Private member functions
template<class T>
void SharedPtr<T>::CreateOwner(T* _ptr)
{
	m_ptr = _ptr;
	m_numOfOwners = new size_t;
	*m_numOfOwners = 1;
}

template<class T>
void SharedPtr<T>::AddOwner(const SharedPtr& _sp)
{
	m_ptr = _sp.m_ptr;
	m_numOfOwners = _sp.m_numOfOwners;
	__sync_add_and_fetch(m_numOfOwners, 1);
}

template<class T>
void SharedPtr<T>::RemoveOwner()
{
	if(m_numOfOwners)
	{
		if (0 == __sync_sub_and_fetch(m_numOfOwners, 1))
		{	
			delete m_ptr;
			delete m_numOfOwners;
			m_ptr = 0;	
		}
	}
}

template<class T>
void SharedPtr<T>::SetNullSP()
{
	m_ptr = 0;
	m_numOfOwners = 0;
}
//////////////////////////////////////////////////////////////////////////////////////////
//Public member functions
template<class T>
SharedPtr<T>::~SharedPtr()
{
	RemoveOwner();
}

template<class T>
SharedPtr<T>::SharedPtr() : m_ptr(0), m_numOfOwners(0)
{
	//Empty
}

template<class T>
SharedPtr<T>::SharedPtr(T* _ptr)
{
	if (!_ptr)
	{
		SetNullSP();
	}
	else
	{
		CreateOwner(_ptr);
	}
}

template<class T>
SharedPtr<T>::SharedPtr(const SharedPtr& _sp)
{
	if (!_sp.GetPtr())
	{
		SetNullSP();
	}
	else
	{	
		AddOwner(_sp);
	}
}

template<class T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr& _sp)
{
	if (this != &_sp)
	{	
		if (!_sp.GetPtr())
		{
			SetNullSP();
		}
		RemoveOwner();
		AddOwner(_sp);
	}
	return *this;
}

template<class T>
T* const SharedPtr<T>::GetPtr() const
{
	return m_ptr;
}

template<class T>
T& SharedPtr<T>::operator*() const
{
	if (!GetPtr())
	{
		//Throw exception
	}
	return *m_ptr;
}

template<class T>
T* const SharedPtr<T>::operator->() const
{
	if (!GetPtr())
	{
		//Throw exception
	}
	return m_ptr;
}



















}//using namespace advcpp
#endif//#ifndef __SUPER_SHARED_PTR__


