#ifndef __EVENT_ATTR_H__
#define __EVENT_ATTR_H__


#include<string>


class EventAttr
{
public:
	virtual ~EventAttr();
	EventAttr();
	EventAttr(std::string _timestamp,
				std::string _type,
				std::string _room,
				std::string _floor);
	void SetTimeStamp(const std::string _time);
	void SetType(const std::string _type);
	void SetRoom(const std::string _room);
	void SetFloor(const std::string _floor);
	const std::string& GetTimestamp()const; 
	const std::string& GetType()const;
	const std::string& GetRoom()const;
	const std::string& GetFloor()const;
	EventAttr& operator=(const EventAttr& _eventAttr);
//    EventAttr& operator=(std::string _timestamp,
//				            std::string _type,
//				            std::string _room,
//				            std::string _floor);
	bool operator==(const EventAttr& _eventAttr) const;
	bool operator<(const EventAttr& _eventAttr) const;

protected:
	

private:
	std::string     m_timestamp;
	std::string     m_type;
	std::string     m_floor;
	std::string     m_room;
};




















#endif //#ifndef __EVENT_ATTR_H__














