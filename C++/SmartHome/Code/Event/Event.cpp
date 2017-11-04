#include "Event.h"
#include "../EventAttr/EventAttr.h"


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
}


Event::~Event
{
    delete m_attributes;
}


const EventAttr* Event::GetAttributes() const
{
    return m_attributes;
}












