#ifndef __EVENT_H__
#define __EVENT_H__

#include <string>
using namespace std;

//class Timestamp_t;
//class Type_t;
//class Data_t;
//class Location_t;

typedef Timestamp_t string;
typedef Type_t string;
typedef Data_t string;
typedef Location_t string;


class Event
{
	public: 
		virtual ~Event();
		Event(Timestamp_t _timestamp, Type_t _type, Data_t _data, Location_t _location);
		const Timestamp_t& GetTimeStamp() const {return m_timestamp;}
		const Type_t& GetType() const 			{return m_type;}
		const Data_t& GetData() const 			{return m_data;}
		const Location_t& GetLocation() const 	{return m_location;}
		
	protected:
		Timestamp_t 	m_timestamp;
		Type_t 			m_type;
		Data_t			m_data;
		Location_t		m_location;
		
	private:
		Event(const Event& _event);
		Event& operator= (const Event& _event);
		
};





































#endif // #ifndef __EVENT_H__
