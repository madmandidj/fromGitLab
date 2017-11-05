#include "Event.h"
#include "../EventAttr/EventAttr.h"
#include <string>

Event::Event(std::string _timestamp,
            std::string _type,
            std::string _room,
            std::string _floor)
{
//    EventAttr* eventAttr = new EventAttr(_timestamp, _type, _room, _floor);
//    if (0 == eventAttr)
//    {
//        //TODO: handle bad alloc
//    }
    
//    m_attributes = eventAttr;

    m_attributes.SetTimeStamp(_timestamp);
    m_attributes.SetType(_type);
    m_attributes.SetRoom(_room);
    m_attributes.SetFloor(_floor);            
    
//    m_payload = new Payload;
}

//Event::Event(const EventAttr* _eventAttr)
//{
//    m_attributes = (EventAttr*)_eventAttr;
//}


Event::~Event()
{
//    delete m_attributes;
}

const std::string Event::GetTimestamp() const
{
    return m_attributes.GetTimestamp();
}


const std::string Event::GetType() const
{
    return m_attributes.GetType();
}


const std::string Event::GetRoom() const
{
    return m_attributes.GetRoom();
}


const std::string Event::GetFloor() const
{
    return m_attributes.GetFloor();
}


const EventAttr& Event::GetAttributes() const
{
    return m_attributes;
}


Payload_t* Event::GetPayload() const
{
    return m_payload;
}












