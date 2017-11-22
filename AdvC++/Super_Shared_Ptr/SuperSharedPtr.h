#ifndef __SUPER_SHARED_PTR__
#define __SUPER_SHARED_PTR__

#include<stddef.h>
namespace advcpp
{
//////////////////////////////////////////////////////////////////////////////////////////
//SharedPtr forward declaration
template<class T>
class SharedPtr;
//////////////////////////////////////////////////////////////////////////////////////////
//Helper function forward declarations
template<class T>
void CreateOwner(SharedPtr<T>& _sp, T* _ptr);
template<class T>
void RemoveOwner(SharedPtr<T>& _sp);
template<class T>
void AddOwner(SharedPtr<T>& _thisSp, const SharedPtr<T>& _otherSp);
//////////////////////////////////////////////////////////////////////////////////////////
//SharedPtr class
template<class T>
class SharedPtr
{
public:
	~SharedPtr();
	explicit SharedPtr();
	explicit SharedPtr(T* _ptr);
	SharedPtr(const SharedPtr& _sp);
	SharedPtr& operator=(const SharedPtr& _sp);
	T* const GetPtr() const;
	T& operator*() const;
	const SharedPtr* operator->() const;
	bool operator==(const SharedPtr& _sp);
	operator bool()const;
private:
	T* 			m_ptr;
	size_t* 	m_numOfOwners;
	friend void CreateOwner<T>(SharedPtr<T>& _sp, T* _ptr);
	friend void RemoveOwner<T>(SharedPtr<T>& _sp);
	friend void AddOwner<T>(SharedPtr<T>& _thisSp, const SharedPtr<T>& _otherSp); 
//	void CreateOwner(T* _ptr);
//	void AddOwner(const SharedPtr& _sp);
//	void RemoveOwner();
	void SetNullSP();
};
//////////////////////////////////////////////////////////////////////////////////////////
//Helper function implementations //TODO: Move to seperate file
template<class T>
inline void CreateOwner(SharedPtr<T>& _sp, T* _ptr)
{
		_sp.m_ptr = _ptr;
		_sp.m_numOfOwners = new size_t;
		*_sp.m_numOfOwners = 1;
}

template<class T>
inline void RemoveOwner(SharedPtr<T>& _sp)
{
	if(_sp.m_numOfOwners)
	{
		if (0 == __sync_sub_and_fetch(_sp.m_numOfOwners, 1))
		{	
			delete _sp.m_ptr;
			delete _sp.m_numOfOwners;
			_sp.m_ptr = 0;	
		}
	}
}

template<class T>
inline void AddOwner(SharedPtr<T>& _thisSp, const SharedPtr<T>& _otherSp)
{
	//TODO: check if pointers are valid
	_thisSp.m_ptr = _otherSp.m_ptr;
	_thisSp.m_numOfOwners = _otherSp.m_numOfOwners;
	__sync_add_and_fetch(_thisSp.m_numOfOwners, 1);
}

//////////////////////////////////////////////////////////////////////////////////////////
//Private member functions
//template<class T>
//inline void SharedPtr<T>::CreateOwner(T* _ptr)
//{
//	m_ptr = _ptr;
//	m_numOfOwners = new size_t;
//	*m_numOfOwners = 1;
//}

//template<class T>
//inline void SharedPtr<T>::AddOwner(const SharedPtr& _sp)
//{
//	m_ptr = _sp.m_ptr;
//	m_numOfOwners = _sp.m_numOfOwners;
//	__sync_add_and_fetch(m_numOfOwners, 1);
//}

//template<class T>
//inline void SharedPtr<T>::RemoveOwner()
//{
//	if(m_numOfOwners)
//	{
//		if (0 == __sync_sub_and_fetch(m_numOfOwners, 1))
//		{	
//			delete m_ptr;
//			delete m_numOfOwners;
//			m_ptr = 0;	
//		}
//	}
//}

template<class T>
inline void SharedPtr<T>::SetNullSP()
{
	m_ptr = 0;
	m_numOfOwners = 0;
}
//////////////////////////////////////////////////////////////////////////////////////////
//Public member functions
template<class T>
inline SharedPtr<T>::~SharedPtr()
{
//	RemoveOwner();
	RemoveOwner(*this);
}

template<class T>
inline SharedPtr<T>::SharedPtr() : m_ptr(0), m_numOfOwners(0)
{
	//Empty
}

template<class T>
inline SharedPtr<T>::SharedPtr(T* _ptr)
{
	if (!_ptr)
	{
		SetNullSP();
	}
	else
	{
		CreateOwner(*this, _ptr);
	}
}

template<class T>
inline SharedPtr<T>::SharedPtr(const SharedPtr& _sp)
{
	if (!_sp.GetPtr())
	{
		SetNullSP();
	}
	else
	{	
//		AddOwner(_sp);
		AddOwner(*this, _sp);
	}
}

template<class T>
inline SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr& _sp)
{
	if (this != &_sp)
	{	
		if (!_sp.GetPtr())
		{
			SetNullSP();
		}
//		RemoveOwner();
		RemoveOwner(*this);
//		AddOwner(_sp);
		AddOwner(*this, _sp);
	}
	return *this;
}

template<class T>
inline T* const SharedPtr<T>::GetPtr() const
{
	return m_ptr;
}

template<class T>
inline T& SharedPtr<T>::operator*() const
{
	if (!GetPtr())
	{
		//Throw exception
	}
	return *m_ptr;
}

template<class T>
inline const SharedPtr<T>* SharedPtr<T>::operator->() const
{
	if (!GetPtr())
	{
		//Throw exception
	}
	return this;
}

template<class T>
inline SharedPtr<T>::operator bool() const
{
	if (!GetPtr())
	{
		//Throw exception
	}
	return !GetPtr() ? false : true;
}

template<class T>
inline bool SharedPtr<T>::operator==(const SharedPtr& _sp)
{
	return m_ptr == _sp.m_ptr ? true : false;
}
















}//using namespace advcpp
#endif//#ifndef __SUPER_SHARED_PTR__


