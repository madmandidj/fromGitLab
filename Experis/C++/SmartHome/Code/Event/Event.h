#ifndef __EVENT_H__
#define __EVENT_H__

#include <string>
#include "../EventAttr/EventAttr.h"

typedef std::string Payload_t;

class Event
{
public:
    virtual ~Event();
    Event(std::string _timestamp,
            std::string _type,
            std::string _room,
            std::string _floor);
    Event(const EventAttr* _eventAttr);
    const std::string GetTimestamp() const;
    const std::string GetType() const;
    const std::string GetRoom() const;
    const std::string GetFloor() const;
    const EventAttr& GetAttributes() const;
    Payload_t GetPayload() const;
    
protected:


private:
    Event(const Event& _event);
    Event& operator=(const Event& _event);    
    EventAttr    m_attributes;
    Payload_t   m_payload;
};














#endif //#ifndef __EVENT_H__














