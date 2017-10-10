#ifndef __TCONTAINER_T_H__ /* VERSION B */
#define __TCONTAINER_T_H__

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <typeinfo>


//template <class T1, class T2> 
template <class T1, template <class, class Alloc = std::allocator <T1*> > class Container> 
class tContainer_t
{
	typedef typename Container<T1*>::iterator iter_t;
	typedef typename Container<T1*>::const_iterator constIter_t;

	public:
		class IsEqual
		{
			public:
				IsEqual(T1 _element) : m_val(_element) {}
				bool operator()(T1* _element)const {return *_element == m_val;}
			
			private:
				T1 m_val;
		};
	
	
		tContainer_t() {}
	
	
		~tContainer_t() {}
		
		
		bool IsEmpty() const {return m_container.empty();}
		
		
		size_t NumOfElements() const {return m_container.size();}
		
		
		bool InsertElement(const T1* _elementPtr)
		{
			if (0 == _elementPtr)
			{
				return false;
			}
			
			m_container.push_back((T1*)_elementPtr);
			
			return true;
		}
		
		
		T1* Remove(T1 _element)
		{
			iter_t it;
			
			for (it = m_container.begin(); it != m_container.end(); ++it)
			{
				if (_element == (**it))
				{
					T1* elementPtr = *it;
					
					m_container.erase(it);
					
					return elementPtr;
				}
			}
			
			return 0;
		}
		
		
		T1* GetFirstElement() const {return *m_container.begin();}
		
		
		T1* GetLastElement() const {return *(m_container.end() - 1);}
		
		
		T1*	Find(const T1 _element) const
		{
			constIter_t it = find_if(m_container.begin(), m_container.end(), IsEqual(_element));
			
			return m_container.end() == it ? 0 : *it;
		}
		
		
		void RemoveAll()
		{
			m_container.erase(m_container.begin(), m_container.end());
			
			return;
		}
		
		
		void RemoveAndDelete(T1 _element)
		{
			T1* element = Remove(_element);
			
			if (0 != element)
			{
				delete element;	
			} 
			
			return;
		}
		
		
		void RemoveAndDeleteAll()
		{
			iter_t it;
			
			T1* elementPtr;
			
			while(0 < NumOfElements())
			{	
				if (typeid(m_container) == typeid(std::vector<T1*>))
		 		{
//					delete (*(m_container.end() - 1));

					delete (*(m_container.begin()));
					
//					m_container.erase(m_container.end() - 1);

					m_container.erase(m_container.begin());
		 		}
		 		else if (typeid(m_container) == typeid(std::list<T1*>))
		 		{
					m_container.pop_back();
		 		}


			}
			
			return;
		}


		 T1* operator[] (size_t _index) const
		 {
		 	if (NumOfElements() <= _index)
		 	{
		 		return 0;
		 	}
		 
//		 	if (typeid(m_container) == typeid(std::vector<T1*>))
			if (typeid(m_container) == typeid(Container<T1*>))
		 	{
//		 		return m_container[_index];
				return (*(std::vector<T1*>*)&m_container)[_index];
		 	}
		 	
		 	else if (typeid(m_container) == typeid(std::list<T1*>))
		 	{
		 		constIter_t it = m_container.begin();
		 		size_t index;
		 		
		 		for (index = 0; index <= _index; ++index)
		 		{
		 			++it;
		 		}
		 		
		 		return *it;
		 		
//		 		return m_container.begin() + _index;
		 	}
		 	
		 	return 0;
		 }

		
	private:
		tContainer_t(const tContainer_t& _tcont);
		
		tContainer_t& operator= (const tContainer_t& _tcont);
		
		Container<T1*> m_container;	
};
















#endif /*  */










