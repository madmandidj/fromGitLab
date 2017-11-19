#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
template<class T>
class Accumulator
{
public:
	Accumulator();
	T operator()(T _arg);
	T GetSum() const;

private:
	T m_sum;
};

template<class T>
inline Accumulator<T>::Accumulator() : m_sum(0)
{
	//Empty
}

template<class T>
inline T Accumulator<T>::operator()(T _arg)
{
	return m_sum += _arg;
}

template<class T>
inline T Accumulator<T>::GetSum() const
{
	return m_sum;
}
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
template<class T>
class Printer
{
public:
	Printer();
	void operator()(T _arg);
};

template<class T>
inline Printer<T>::Printer()
{
	//Empty
}

template<class T>
inline void Printer<T>::operator()(T _arg)
{
	cout << _arg << endl;
}
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////













int main()
{
	srand(time(NULL));
	const size_t size = 10;
	int intArr[size];
	for (size_t index = 0; index < size; ++index)
	{
		intArr[index] = rand() % size;
	}
	vector<int> vec1(intArr, intArr + size);
	
	Accumulator<int> accum1;
	
	accum1 = for_each(vec1.begin(), vec1.end(), Accumulator<int>());
	
	for_each(vec1.begin(), vec1.end(), Printer<int>());
	
	cout << accum1.GetSum() << endl;
	
	return 0;
}
























