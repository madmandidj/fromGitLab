#include "Event.h"
#include "../EventAttr/EventAttr.h"
#include <string>

Event::Event(std::string _timestamp,
            std::string _type,
            std::string _room,
            std::string _floor)
{
    EventAttr* eventAttr = new EventAttr(_timestamp, _type, _room, _floor);
    if (0 == eventAttr)
    {
        //TODO: handle bad alloc
    }
    
    m_attributes = eventAttr;
    
    m_payload = "payload";
}

Event(const EventAttr* _eventAttr)
{
    m_attributes = _eventAttr;
}


Event::~Event()
{
    delete m_attributes;
}


EventAttr* Event::GetAttributes() const
{
    return m_attributes;
}


Payload_t* Event::GetPayload() const
{
    return m_payload;
}












