#include "Hub.h"
#include "../Agent/Agent.h"
#include "../Event/Event.h"
#include "../EventAttr/EventAttr.h"
#include<string>
#include<iostream> //REMOVE THIS


Hub::~Hub()
{
    //Empty
}


Hub::Hub() : m_livePrintMode(true)
{
    //Empty
}


bool Hub::AddSubscription(const EventAttr _eventAttr, const Agent* _agent)
{
    std::pair <std::multimap<EventAttr, Agent*>::iterator, std::multimap<EventAttr, Agent*>::iterator> agentRange; 
    std::multimap<EventAttr, Agent*>::iterator firstIt;
    std::multimap<EventAttr, Agent*>::iterator secondIt;

    agentRange = m_subscriptions.equal_range((EventAttr)_eventAttr);
    firstIt = agentRange.first;
    secondIt = agentRange.second;

    if (firstIt == secondIt)
    {        
        m_subscriptions.insert(std::pair<EventAttr, Agent*>((EventAttr)_eventAttr, (Agent*)_agent));
		if(m_livePrintMode)
		{
			std::cout << "Hub: " << _agent->GetID() <<" subscribed to " << _eventAttr.GetType() << " ";
			std::cout << _eventAttr.GetRoom() << " " << _eventAttr.GetFloor() << std::endl;
		}
		
    }
    else
    {
        Agent* agentPtr;
        while(firstIt != secondIt)
        {
            agentPtr = firstIt->second;
            if (agentPtr->GetID() == _agent->GetID())
            {
				if(m_livePrintMode)
				{
					std::cout << "Hub: " << _agent->GetID() <<" ALREADY subscribed to " << _eventAttr.GetType() << " ";
					std::cout << _eventAttr.GetRoom() << " " << _eventAttr.GetFloor() << std::endl;
				}
                return false;
            }
            ++firstIt;
        }
        
		if(m_livePrintMode)
		{
			std::cout << "Hub: " << _agent->GetID() <<" subscribed to " << _eventAttr.GetType() << " ";
			std::cout << _eventAttr.GetRoom() << " " << _eventAttr.GetFloor() << std::endl;
		}
        
        m_subscriptions.insert(std::pair<EventAttr, Agent*>((EventAttr)_eventAttr, (Agent*)_agent));
    }   

    return true;
}


bool Hub::RemoveSubscription(const EventAttr _eventAttr, const Agent* _agent)
{
    std::pair <std::multimap<EventAttr, Agent*>::iterator, std::multimap<EventAttr, Agent*>::iterator> agentRange; 
    std::multimap<EventAttr, Agent*>::iterator firstIt;
    std::multimap<EventAttr, Agent*>::iterator secondIt;

    agentRange = m_subscriptions.equal_range((EventAttr)_eventAttr);
    firstIt = agentRange.first;
    secondIt = agentRange.second;

    if (firstIt == secondIt)
    {
    	if(m_livePrintMode)
		{
			std::cout << "Hub: " << _agent->GetID() <<" not subscribed to " << _eventAttr.GetType() << " ";
			std::cout << _eventAttr.GetRoom() << " " << _eventAttr.GetFloor() << std::endl;
		}

        return false;
    }
    else
    {
        Agent* agentPtr;
        while(firstIt != secondIt)
        {
            agentPtr = firstIt->second;
            if (agentPtr->GetID() == _agent->GetID())
            {
                m_subscriptions.erase(firstIt);

				if(m_livePrintMode)
				{
					std::cout << "Hub: " << _agent->GetID() <<" unsibscribed from " << _eventAttr.GetType() << " ";
					std::cout << _eventAttr.GetRoom() << " " << _eventAttr.GetFloor() << std::endl;
				}
                return true;
            }
            ++firstIt;
        }
    }

    if(m_livePrintMode)
	{
		std::cout << "Hub: " << _agent->GetID() <<" not subscribed to " << _eventAttr.GetType() << " ";
		std::cout << _eventAttr.GetRoom() << " " << _eventAttr.GetFloor() << std::endl;
	}
    return false;
}


size_t Hub::PublishEvent(std::tr1::shared_ptr<Event> _event)
{
    size_t count = 0;
    EventAttr eventAttr = _event->GetAttributes();
    
    std::pair <std::multimap<EventAttr, Agent*>::iterator, std::multimap<EventAttr, Agent*>::iterator> agentRange; 
    std::multimap<EventAttr, Agent*>::iterator firstIt;
    std::multimap<EventAttr, Agent*>::iterator secondIt;

    agentRange = m_subscriptions.equal_range(eventAttr);
    firstIt = agentRange.first;
    secondIt = agentRange.second;

    if (m_livePrintMode)
    {
    	std::cout << std::endl;
        std::cout << "Hub: Received " << _event->GetType() << 
                    " " << _event->GetTimestamp() <<
                    " " << _event->GetRoom() << 
                    " " << _event->GetFloor() << ", ";				
    }
    
    if (firstIt == secondIt)
    {
        std::cout << "No subscribers to this event" << std::endl;
        return count;
    }
    else
    {
        Agent* agentPtr;
        if (m_livePrintMode)
        {
        	std::cout << "Published to: ";
        }
        while(firstIt != secondIt)
        {
            agentPtr = firstIt->second;
            agentPtr->PushEvent(_event); 
            ++firstIt;
            ++count;
            if (m_livePrintMode)
            {
                std::cout << agentPtr->GetID() << ", ";
            }
        }
        if (m_livePrintMode)
        {
        	std::cout << "Event published " << count << " times" << std::endl;
    	}
    }

    return count;
}


void Hub::SetLivePrintMode(bool _shouldLivePrint)
{
    m_livePrintMode = _shouldLivePrint;
}


bool Hub::GetLivePrintMode()
{
    return m_livePrintMode;
}






