#include "Agent.h"
#include "../Hub/Hub.h"
#include "../HubInterface/HubInterface.h"
#include "../AgentAttr/AgentAttr.h"
#include "../Event/Event.h"
#include "../EventAttr/EventAttr.h"
#include<string>
#include<queue>
#include<pthread.h>
#include<sstream>
#include<iostream> //REMOVE
#include<stdexcept>

size_t Agent::m_maxQueueSize = 5;

Agent::Agent(AgentAttr* _attr, HubInterface* _hub)
{
	if (0 == _attr || 0 == _hub)
	{
		throw std::runtime_error("Agent::Agent, invalid parameter");	
	}
	
	m_attributes = _attr;
	
	m_hub = _hub;
	
	if (0 != pthread_mutex_init(&m_mutex, NULL))
	{
		delete m_attributes;
		throw std::runtime_error("Agent::Agent, mutex init fail");
	}
	
	if (0 != pthread_cond_init(&m_condVar, NULL))
	{
	    pthread_mutex_destroy(&m_mutex);
		delete m_attributes;
		throw std::runtime_error("Agent::Agent, cond init fail");
	}
	
	
}


Agent::~Agent()
{
	delete m_attributes;
	pthread_mutex_destroy(&m_mutex);
	pthread_cond_destroy(&m_condVar);
	pthread_cancel(m_thread);
//	std::cout << "In ~Agent()" << std::endl;
}


bool Agent::Subscribe(std::string _type, std::string _room, std::string _floor)
{
    EventAttr eventAttr("", _type, _room, _floor);
	
	return m_hub->AddSubscription(eventAttr, this);
}


bool Agent::Unsubscribe(std::string _type, std::string _room, std::string _floor)
{
	EventAttr eventAttr("", _type, _room, _floor);
	
	return m_hub->RemoveSubscription(eventAttr, this);
}	


std::tr1::shared_ptr<Event> Agent::GenerateEvent(std::string _timestamp,
                            std::string _type,
                            std::string _room,
                            std::string _floor)
{	
    std::tr1::shared_ptr<Event> event(new Event(_timestamp,
                            _type,
                            _room,
                            _floor));
                            
	if (0 == event)
	{
	    throw std::runtime_error("Agent::GenerateEvent, event bad alloc");
	}
	
	return event;
}


bool Agent::PublishEvent(std::tr1::shared_ptr<Event> _event)
{
    m_hub->PublishEvent(_event);
	return true;
}


bool Agent::PushEvent(std::tr1::shared_ptr<Event> _event)
{
    pthread_mutex_lock(&m_mutex);

    if (m_maxQueueSize > m_queue.size())
    {
        m_queue.push(_event);
        pthread_cond_signal(&m_condVar);
        pthread_mutex_unlock(&m_mutex);
        return true;
    }
    
    pthread_mutex_unlock(&m_mutex);
    
    return false;
}


std::tr1::shared_ptr<Event> Agent::PopEvent()
{
    pthread_mutex_lock(&m_mutex);
    
    while (0 == m_queue.size())
    {
        pthread_cond_wait(&m_condVar, &m_mutex);
    }
    
    std::tr1::shared_ptr<Event> event = m_queue.front(); 
    m_queue.pop();
    pthread_mutex_unlock(&m_mutex);

    return event;
}


std::string Agent::GenerateTimestamp() const
{
    time_t rawtime = time(0); 
    struct tm * curTime = localtime (&rawtime);
    std::string str;
    std::stringstream strm;

	strm << "(" << curTime->tm_mday << "/" 
	<< curTime->tm_mon + 1  << "/2017, " 
	<< curTime->tm_hour << ":" << curTime->tm_min << ":" << curTime->tm_sec << ")";
    
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


size_t Agent::GetMaxQueueSize()
{
    return m_maxQueueSize;
}


void Agent::CreateAgentThread()
{
    pthread_create(&m_thread, NULL, &AgentTrampoline, this);
}

//void Agent::CancelAgentThread()
//{
//    pthread_create(&m_thread, NULL, &AgentTrampoline, this);
//}

void* Agent::AgentTrampoline(void* _agent)
{
    ((Agent*)_agent)->DoRoutine();
    
    return 0;
}


const pthread_t& Agent::GetThread() const
{
	return m_thread;
}






