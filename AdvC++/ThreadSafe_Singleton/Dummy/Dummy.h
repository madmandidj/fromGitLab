#ifndef __DUMMY_H__
#define __DUMMY_H__

#include<iostream>
namespace advcpp
{
////////////////////////////////////////////////////////////////////////////////////////////////
////// Template Dummy class
template<class T>
class Dummy
{
public:
	inline ~Dummy();
	inline Dummy(T _dummy);
	inline T SetDummy(T _dummy); //Returns new Dummy state
	inline T GetDummy() const;
private:
	T m_dummy;
};
////////////////////////////////////////////////////////////////////////////////////////////////
////// Operator Print definition
template<class T> // TODO: Ask why i cant make this specialized
std::ostream& operator<<(std::ostream& _ostream, const Dummy<T>& _dummy)
{
	std::cout << _dummy.GetDummy();
	return _ostream;
} 

////////////////////////////////////////////////////////////////////////////////////////////////
////// bool specialization implementation
template<>
Dummy<bool>::~Dummy()
{
	//Empty
}

template<>
Dummy<bool>::Dummy(bool _isDummy)
{
	m_dummy = _isDummy;
}

template<>
bool Dummy<bool>::SetDummy(bool _isDummy)
{
	if (_isDummy)
	{
		return true; //Because once you go Dummy, you don't go back!
	}
	return m_dummy = (!_isDummy) ? ((m_dummy) ? true : false) : true;
}

template<>
bool Dummy<bool>::GetDummy() const
{
	return m_dummy;
}





































}//namespace advcpp
#endif //#ifndef __DUMMY_H__

