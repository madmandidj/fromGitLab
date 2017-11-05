#ifndef __HUB_H__
#define __HUB_H__

#include<string>
#include<map>
#include <tr1/memory>

class Agent;
class Event;
class EventAttr;

class Hub
{
public:
    virtual ~Hub();
    Hub();
    bool AddSubscription(const EventAttr _eventAttr, const Agent* _agent);
    bool RemoveSubscription(const EventAttr _eventAttr, const Agent* _agent);
    size_t PublishEvent(std::tr1::shared_ptr<Event> _event); //TODO: returns number of distributions
    void SetLivePrintMode(bool _shouldLivePrint);
    bool GetLivePrintMode();

protected:


private:
    Hub(const Hub& _hub);
    Hub& operator=(const Hub& _hub);
    std::multimap<EventAttr, Agent*>    m_subscriptions;
//    std::multimap<std::string, Event*>   m_liveEvents;
//    std::multimap<std::string, std::tr1::shared_ptr<Event> >   m_liveEvents;
    bool    m_livePrintMode;
};






















#endif //#ifndef __HUB_H__

