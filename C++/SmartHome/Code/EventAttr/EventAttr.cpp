#include "EventAttr.h"
#include<string>

EventAttr::~EventAttr()
{
    //Empty
}


EventAttr::EventAttr(std::string _timestamp,
				std::string _type,
				std::string _room,
				std::string _floor)
				: m_timestamp(_timestamp),
				    m_type(_type),
				    m_room(_room),
				    m_floor(_floor)
{
    //Empty
}


const std::string& GetTimestamp()const
{
    return m_timestamp;
}


const std::string& GetType()const
{
    return m_type;
}


const std::string& GetRoom()const
{
    return m_room;
}


const std::string& GetFloor()const
{
    return m_floor;
}


bool operator==(const EventAttr& _eventAttr) const
{
    if (m_type == _eventAttr.GetType() &&
            m_room == _eventAttr.GetRoom() &&
            m_floor == _eventAttr.GetFloor())
    {
        return true;
    }            
    
    return false;
}


bool operator<(const EventAttr& _eventAttr) const
{
    if (*this == _eventAttr)
    {
        return false;
    }
    
    int compareResult;
    
    compareResult = m_type.compare(_eventAttr.GetType());
    if (0 != compareResult)
    {
        return 0 < compareResult ? true : false;
    }
    
    compareResult = m_floor.compare(_eventAttr.GetFloor());
    if (0 != compareResult)
    {
        return 0 < compareResult ? true : false;
    }
    
    compareResult = m_room.compare(_eventAttr.GetRoom());
    
    return 0 < compareResult ? true : false;
}




























