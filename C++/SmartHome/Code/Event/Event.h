#ifndef __EVENT_H__
#define __EVENT_H__

class EventAttr

class Event
{
public:
    virtual ~Event();
    Event(std::string _timestamp,
            std::string _type,
            std::string _room,
            std::string _floor);
    const EventAttr* GetAttributes() const;
    
protected:


private:
    Event(const Event& _event);
    Event& operator=(const Event& _event);    
    EventAttr*  m_attributes;
};














#endif //#ifndef __EVENT_H__














