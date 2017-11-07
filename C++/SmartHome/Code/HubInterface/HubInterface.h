#ifndef __HUB_INTERFACE_H__
#define __HUB_INTERFACE_H__

#include "../Event/Event.h"
#include "../EventAttr/EventAttr.h"
#include <tr1/memory>

class Agent;
class EventAttr;

class HubInterface
{
public:
	virtual ~HubInterface() {}
	virtual bool AddSubscription(const EventAttr _eventAttr, const Agent* _agent) = 0;
    virtual bool RemoveSubscription(const EventAttr _eventAttr, const Agent* _agent) = 0;
    virtual size_t PublishEvent(std::tr1::shared_ptr<Event> _event) = 0;
protected:
	
private:
	
};
































#endif //#ifndef __HUB_INTERFACE_H__

