#ifndef __TCONTAINER_T_H__
#define __TCONTAINER_T_H__

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

template <class T1, class T2> 
class tContainer_t
{
	public:
		tContainer_t();
		
		~tContainer_t();
		
		/*
		TODO: Implement small functions inside class
		
		bool 	IsEmpty(); const
		
		size_t	NumOfElements(); const
		
		void	InsertElemenet(T1* _elementPtr); const
		
		T1* 	GetFirstElement(); const
		
		T1*		Find(T1 _element); const
		
		T1*		Remove(T1 _element);
		
		void	RemoveAll();
		
		void	RemoveAndDelete(T1 _element);
		
		void	RemoveAndDeleteAll();
		
		 T1*	operator[] (size_t index);
		
		*/
		
	private:
		tContainer_t(const tContainer_t& _tcont);
		
		tContainer_t& operator= (const tContainer_t& _tcont);
		
		T2 m_container;
		
		
};



































#endif /*  */










