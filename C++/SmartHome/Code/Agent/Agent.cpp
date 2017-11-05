#include "Agent.h"
#include "../Hub/Hub.h"
#include "../AgentAttr/AgentAttr.h"
#include "../Event/Event.h"
#include "../EventAttr/EventAttr.h"
//#include "../Payload/Payload.h"
#include<string>
#include<queue>
#include<pthread.h>
#include<sstream>
#include<iostream> //REMOVE

Agent::Agent(AgentAttr* _attr, Hub* _hub)
{
	if (0 == _attr || 0 == _hub)
	{
		//TODO: handle invalid pointers
	}
	
	m_attributes = _attr;
	m_hub = _hub;
	if (0 != pthread_mutex_init(&m_mutex, NULL))
	{
		delete m_attributes;
	}
}


Agent::~Agent()
{
	delete m_attributes;
	pthread_mutex_destroy(&m_mutex);
}


bool Agent::Subscribe(std::string _type, std::string _room, std::string _floor)
{
	EventAttr* eventAttr = new EventAttr("", _type, _room, _floor);
	if (0 == eventAttr)
	{
		//TODO: handle bad alloc
	}
	
	return m_hub->AddSubscription(eventAttr, this);
}


bool Agent::Unsubscribe(std::string _type, std::string _room, std::string _floor)
{
	EventAttr* eventAttr = new EventAttr("", _type, _room, _floor);
	if (0 == eventAttr)
	{
		//TODO: handle bad alloc
	}
	
	return m_hub->RemoveSubscription(eventAttr, this);
}	


Event* Agent::GenerateEvent(std::string _timestamp,
                            std::string _type,
                            std::string _room,
                            std::string _floor)
{
//	EventAttr* eventAttr = GenerateEventAttr(std::string _timestamp,
//                                            std::string _type,
//                                            std::string _room,
//                                            std::string _floor);
//	if (0 == eventAttr)
//	{
//	    //TODO: handle bad alloc
//	}
	
	
	
	Event* event = new Event(_timestamp,
                            _type,
                            _room,
                            _floor);
	if (0 == event)
	{
	    //TODO: handl bad alloc
	}
	
	return event;
}


bool Agent::PublishEvent(Event* _event)
{
    m_hub->PublishEvent(_event);
	return true;
}


bool Agent::PushEvent(Event* _event)
{
    m_queue.push(_event);
    return true;
}


const Event* Agent::PopEvent()
{
    Event* event = m_queue.front(); 
    m_queue.pop();
    return event;
}


std::string Agent::GenerateTimestamp() const
{
    time_t rawtime = time(0); 
    struct tm * curTime = localtime (&rawtime);
    std::string str;
    std::stringstream strm;
    
    strm << "Month= " << curTime->tm_mon << ", " 
        << "Day= " << curTime->tm_mday << ", " 
        << "Time= " << curTime->tm_hour << ":" << curTime->tm_min << ":" << curTime->tm_sec;
    
    return strm.str(); 
}


const std::string& Agent::GetID() const
{
	return m_attributes->GetID();
}


const std::string& Agent::GetType() const
{
	return m_attributes->GetType();
}


const std::string& Agent::GetRoom() const
{
	return m_attributes->GetRoom();
}


const std::string& Agent::GetFloor() const
{
	return m_attributes->GetFloor();
}


const std::string& Agent::GetLog() const
{
	return m_attributes->GetLog();
}


const std::string& Agent::GetConfig() const
{
	return m_attributes->GetConfig();
}













