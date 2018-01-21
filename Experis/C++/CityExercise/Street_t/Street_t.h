#ifndef __STREET_T_H__
#define __STREET_T_H__
#include "../Building_t/Building_t.h"
#include <vector>

template <class T1, class T2> //change T to meaningful name
class Street_t
{
	public:
		Street_t(const T1& _id);
		Street_t(const Street_t& _street);
		Street_t& operator= (const Street_t& _street);
		~Street_t();
		bool SetID(const T1& _id);
		T1 GetID() const;
		void AddBuilding(const Building_t<T2>& _building);
		Building_t<T2>& GetBuilding(const T2& _id) const;
		
	private:
		std::vector< Building_t<T2>* > m_vec;
		T1 m_id;
};



template <class T1, class T2> 
Street_t<T1, T2>::Street_t(const T1& _id)
{
	m_id = _id;
}



template <class T1, class T2> 
Street_t<T1, T2>::Street_t(const Street_t& _street)
{
	m_id = _street.m_id;
}



template <class T1, class T2> 
Street_t<T1, T2>& Street_t<T1, T2>::operator= (const Street_t& _street)
{
	m_id = _street.m_id;
}



#endif /* #ifndef __STREET_T_H__ */



