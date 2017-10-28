#ifndef __SONY_SD_127_H__
#define __SONY_SD_127_H__


#include <iostream>
#include <string>

using namespace std;

extern "C" unsigned int add(unsigned int a, unsigned int b);

class Event_t
{
	public:
		static Event_t& CreateEvent(string _timestamp, string _type, string _data, string _location)
		{	
			Event_t event(_timestamp, _type, _data, _location);
		}
//		Event_t(string _timestamp, string _type, string _data, string _location) 
		
					
		virtual ~Event_t(){}
		
		const string& GetLocation() const {return m_location;}
		
	private:
		Event_t(string _timestamp, string _type, string _data, string _location)
		{
			m_timestamp = _timestamp;
			m_type = _type;
			m_data = _data;
			m_location = _location;
		} 
		static Event_t m_event;
		string m_timestamp;
		string m_type;
		string m_data;
		string m_location;
};









#endif //#ifndef __SONY_SD_127_H__
