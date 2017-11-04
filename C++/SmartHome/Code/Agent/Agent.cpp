#include "Agent.h"
#include "../Hub/Hub.h"
#include "../AgentAtrr/AgentAtrr.h"
#include "../Event/Event.h"
#include "../EventAttr/EventAttr.h"
#include<string>
#include<queue>
#include<pthread>

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
	pthread_mutex_destroy(&m_lock));
}


bool Agent::Subscribe(std:string _type, std::string _room, std::string _floor)
{
	EventAttr* eventAttr = new EventAttr("", _type, _room, _floor);
	if (0 == eventAttr)
	{
		//TODO: handle bad alloc
	}
	
	return m_hub->AddSubscription(eventAttr, this);
}


bool Agent::Unsubscribe(std:string _type, std::string _room, std::string _floor)
{
	EventAttr* eventAttr = new EventAttr("", _type, _room, _floor);
	if (0 == eventAttr)
	{
		//TODO: handle bad alloc
	}
	
	return m_hub->RemoveSubscription(eventAttr, this);
}	

const Event* Agent::GenerateEvent()
{
	
}



bool Agent::PublishEvent(Event* _event)
{
	
}


const std::string& Agent::GetID() const
{
	return m_attributes->GetID();
}


const std::string& Agent::GetType() const;
{
	return m_attributes->GetType();
}

const std::string& Agent::GetRoom() const;
{
	return m_attributes->GetRoom();
}

const std::string& Agent::GetFloor() const;
{
	return m_attributes->GetFloor();
}

const std::string& Agent::GetLog() const;
{
	return m_attributes->GetLog();
}

const std::string& Agent::GetConfig() const;
{
	return m_attributes->GetConfig();
}













