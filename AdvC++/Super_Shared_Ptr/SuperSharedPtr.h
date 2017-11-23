#ifndef __SUPER_SHARED_PTR__
#define __SUPER_SHARED_PTR__

#include "SSP_Helper.h"
#include<stddef.h>
namespace advcpp
{
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
//	const SharedPtr* operator->() const; //should return T*
	T* operator->() const; //should return T*
	bool operator==(const SharedPtr& _sp);
	operator bool()const;
private:
	T* 			m_ptr;
	size_t* 	m_numOfOwners;
	friend void CreateOwner<T>(SharedPtr<T>& _sp, T* _ptr);
	friend void RemoveOwner<T>(SharedPtr<T>& _sp);
	friend void AddOwner<T>(SharedPtr<T>& _thisSp, const SharedPtr<T>& _otherSp);
	friend void SetNullSP<T>(SharedPtr<T>& _thisSp);
};
//////////////////////////////////////////////////////////////////////////////////////////
//Public member functions
template<class T>
inline SharedPtr<T>::~SharedPtr()
{
	RemoveOwner(*this);
}
template<class T>
inline SharedPtr<T>::SharedPtr():m_ptr(0), m_numOfOwners(0)
{
	//Empty
}
template<class T>
inline SharedPtr<T>::SharedPtr(T* _ptr)
{
//	if (!_ptr)
//	{
//		SetNullSP(*this);
//	}
//	else
//	{
//		CreateOwner(*this, _ptr);
//	}

	Do_Def_CTOR(*this, _ptr);
	
}
template<class T>
inline SharedPtr<T>::SharedPtr(const SharedPtr& _sp)
{
	if (!_sp.GetPtr())
	{
		SetNullSP(*this);
	}
	else
	{	
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
			SetNullSP(*this);
		}
		else
		{
			RemoveOwner(*this);
			AddOwner(*this, _sp);
		}
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
	return *m_ptr;
}
//template<class T>
//inline const SharedPtr<T>* SharedPtr<T>::operator->() const
//{
//	return this;
//}
template<class T>
inline T* SharedPtr<T>::operator->() const
{
	return m_ptr;
}
//template<class T>
//inline SharedPtr<T>::operator bool() const
//{
//	return !GetPtr() ? false : true;
//}
template<class T>
inline SharedPtr<T>::operator bool() const
{
	return (0 != GetPtr());
}
//template<class T>
//inline bool SharedPtr<T>::operator==(const SharedPtr& _sp)
//{
//	return m_ptr == _sp.m_ptr ? true : false;
//}
template<class T>
inline bool SharedPtr<T>::operator==(const SharedPtr& _sp)
{
	return m_ptr == _sp.m_ptr;
}















}//using namespace advcpp
#endif//#ifndef __SUPER_SHARED_PTR__


