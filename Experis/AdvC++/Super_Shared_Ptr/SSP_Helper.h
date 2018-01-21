#ifndef __SSP_HELPER_H__
#define __SSP_HELPER_H__

#include <stddef.h>
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
template<class T>
void SetNullSP(SharedPtr<T>& _thisSp);
template<class T>
void Do_Def_CTOR(SharedPtr<T>& _sp, T* _ptr);
////////////////////////////////////////////////////////////////////////////////////////
//Helper function implementations
template<class T>
inline void Do_Def_CTOR(SharedPtr<T>& _sp, T* _ptr)
{
	if (!_ptr)
	{
		SetNullSP(_sp);
	}
	else
	{
		CreateOwner(_sp, _ptr);
	}
}


//template<class T, T* IS_NULL>
//class Def_Ctor_Functor
//{
//	public:
//		inline Def_Ctor_Functor();
//		inline void operator()(
//}







template<class T>
inline void CreateOwner(SharedPtr<T>& _sp, T* _ptr)
{
		_sp.m_ptr = _ptr;
		_sp.m_numOfOwners = new size_t; //If this fails, we need to free _sp.m_ptr, because user sent this a (new T*) parameter
		*_sp.m_numOfOwners = 1;
}
template<class T>
inline void RemoveOwner(SharedPtr<T>& _sp)
{
	if(_sp.m_numOfOwners) //could be if(_sp.m_ptr)
	{
		if (0 == __sync_sub_and_fetch(_sp.m_numOfOwners, 1))
		{	
			delete _sp.m_ptr;
			delete _sp.m_numOfOwners;
			_sp.m_ptr = 0;	// This is redundant
		}
	}
}
template<class T>
inline void AddOwner(SharedPtr<T>& _thisSp, const SharedPtr<T>& _otherSp)
{
	_thisSp.m_ptr = _otherSp.m_ptr;
	_thisSp.m_numOfOwners = _otherSp.m_numOfOwners;
	__sync_add_and_fetch(_thisSp.m_numOfOwners, 1);
}
template<class T>
inline void SetNullSP(SharedPtr<T>& _thisSp)
{
	_thisSp.m_ptr = 0;
	_thisSp.m_numOfOwners = 0;
}
































}//namespace advcpp
#endif//#ifndef __SSP_HELPER_H__

