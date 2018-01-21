#ifndef __BUILDING_T_H__
#define __BUILDING_T_H__


template <class T> 
class Building_t
{
	public:
		Building_t(const T& _id);
		Building_t(const Building_t& _building);
		Building_t& operator= (const Building_t& _building);
		~Building_t();
		bool SetID(const T& _id);
		T GetID() const;
		
	private:
		T m_id;
};



template <class T>
Building_t<T>::Building_t(const T& _id)
{
	m_id = _id;
}



template <class T>
Building_t<T>::Building_t(const Building_t& _building)
{
	m_id = _building.m_id;
}



template <class T>
Building_t<T>& Building_t<T>:: operator= (const Building_t& _building)
{
	m_id = _building.m_id;
}



template <class T>
Building_t<T>::~Building_t(){}



template <class T>
bool Building_t<T>::SetID(const T& _id)
{
	m_id = _id;
}



template <class T>
T Building_t<T>::GetID() const
{
	return m_id;
}




#endif /* #ifndef __BUILDING_T_H__ */



