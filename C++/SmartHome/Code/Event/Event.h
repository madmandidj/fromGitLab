#ifndef __EVENT_H__
#define __EVENT_H__

#include <string>

class EventAttr;

class Event
{
public:
    virtual ~Event();
    Event(std::string _timestamp,
            std::string _type,
            std::string _room,
            std::string _floor);
    Event(const EventAttr* _eventAttr);
    EventAttr* GetAttributes() const;
    
protected:


private:
    Event(const Event& _event);
    Event& operator=(const Event& _event);    
    EventAttr*  m_attributes;
    //TODO: Payload* // implemented by user
};














#endif //#ifndef __EVENT_H__














