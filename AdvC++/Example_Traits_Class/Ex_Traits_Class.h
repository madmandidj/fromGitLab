#ifndef __TRAITS_CLASS_H__
#define __TRAITS_CLASS_H__

template<class T>
struct BoolDetector<T>
{
	static bool is_bool = false;
};

template<>
struct BoolDetector<bool>
{
	static bool is_bool = true;
}

/////////////////////////////////////////////////////////////////

template<>
class std::numeric_limits<VeryVeryVeryLongInt>
{
	static const VeryVeryVeryLongInt max = 9999999999999;
}
//put this in the same .h file that VeryVeryVeryLongInt was defined

/////////////////////////////////////////////////////////////////

template <class T, class U>
class MyClass<T,U>

template<class U>
class MyClass<int, U>

/////////////////////////////////////////////////////////////////

template <class T>
class Other...

template<class U>
class Other<U*>

/////////////////////////////////////////////////////////////////
Specialization for functions is possible, but only full not semi specialization

/////////////////////////////////////////////////////////////////
template<class T> class X;

can now write specialized for this, and there will be no generic case.

template<>
class X<char>
{

}
/////////////////////////////////////////////////////////////////
Specialization can be declared in .h, and can implement in .cpp
/////////////////////////////////////////////////////////////////
Overloading is also possible

template<class T> void foo(T*);

template<int> void foo(int i);

#endif //#ifndef __TRAITS_CLASS_H__



