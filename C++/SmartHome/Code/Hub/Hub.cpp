#include "Hub.h"
#include "../Agent/Agent.h"
#include "../Event/Event.h"
#include "../EventAttr/EventAttr.h"
#include<string>
#include<iostream> //REMOVE THIS


Hub::~Hub()
{
    //TODO: Destroy Agents
    //TODO: Destroy remaining live events
}


Hub::Hub() : m_livePrintMode(true)
{
 // Empty
}


bool Hub::AddSubscription(const EventAttr* _eventAttr, const Agent* _agent)
{
    std::pair <std::multimap<EventAttr*, Agent*>::iterator, std::multimap<EventAttr*, Agent*>::iterator> agentRange; 
    std::multimap<EventAttr*, Agent*>::iterator firstIt;
    std::multimap<EventAttr*, Agent*>::iterator secondIt;

    agentRange = m_subscriptions.equal_range((EventAttr*)_eventAttr);
    firstIt = agentRange.first;
    secondIt = agentRange.second;

    if (firstIt == secondIt)
    {
        std::cout << "New subscription bucket created, subscription added" << std::endl;
        m_subscriptions.insert(std::pair<EventAttr*, Agent*>((EventAttr*)_eventAttr, (Agent*)_agent));
    }
    else
    {
        Agent* agentPtr;
        while(firstIt != secondIt)
        {
            agentPtr = firstIt->second;
            if (agentPtr->GetID() == _agent->GetID())
            {
                std::cout << "Subscription already exists, returning false" << std::endl;
                return false;
            }
            ++firstIt;
        }
        std::cout << "New Subscription added to existing bucket" << std::endl;
        m_subscriptions.insert(std::pair<EventAttr*, Agent*>((EventAttr*)_eventAttr, (Agent*)_agent));
    }   

    return true;
}


bool Hub::RemoveSubscription(const EventAttr* _eventAttr, const Agent* _agent)
{
    std::pair <std::multimap<EventAttr*, Agent*>::iterator, std::multimap<EventAttr*, Agent*>::iterator> agentRange; 
    std::multimap<EventAttr*, Agent*>::iterator firstIt;
    std::multimap<EventAttr*, Agent*>::iterator secondIt;

    agentRange = m_subscriptions.equal_range((EventAttr*)_eventAttr);
    firstIt = agentRange.first;
    secondIt = agentRange.second;

    if (firstIt == secondIt)
    {
        std::cout << "No matching subscription bucket" << std::endl;
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
                std::cout << "Subscription removed" << std::endl;
                return true;
            }
            ++firstIt;
        }
    }
    
    std::cout << "No matching subscription in the existing bucket" << std::endl;
    return false;
}


size_t Hub::PublishEvent(Event* _event) //TODO: returns number of distributions
{
    size_t count = 0;
    EventAttr* eventAttr = _event->GetAttributes();
    
    std::pair <std::multimap<EventAttr*, Agent*>::iterator, std::multimap<EventAttr*, Agent*>::iterator> agentRange; 
    std::multimap<EventAttr*, Agent*>::iterator firstIt;
    std::multimap<EventAttr*, Agent*>::iterator secondIt;

    agentRange = m_subscriptions.equal_range(eventAttr);
    firstIt = agentRange.first;
    secondIt = agentRange.second;
    
    if (firstIt == secondIt)
    {
        std::cout << "No subscribers to this event" << std::endl;
        return count;
    }
    else
    {
        Agent* agentPtr;
        while(firstIt != secondIt)
        {
            agentPtr = firstIt->second;
//            if (agentPtr->GetID() == _agent->GetID())
//            {
//                m_subscriptions.erase(firstIt);
//                std::cout << "Subscription removed" << std::endl;
//                return true;
//            }
            agentPtr->PushEvent(_event);
            ++firstIt;
            ++count;
        }
        std::cout << "Even published" << count << " times" << std::endl;
    }
    
//    std::cout << "No matching subscription in the existing bucket" << std::endl;
    return count;
    
    /*
    Psuedo code:
        Get EventAttr
        For (number of event subscribers)
        {
            ++count;
            publishEvent(Agent*, Event*);
        }
        
    */
}


void Hub::SetLivePrintMode(bool _shouldLivePrint)
{

}


bool Hub::GetLivePrintMode()
{

}






