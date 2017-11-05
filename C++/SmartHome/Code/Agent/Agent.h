#ifndef __AGENT_H__
#define __AGENT_H__

#include<string>
#include<queue>
#include<pthread.h>

class Hub;
class AgentAttr;
class Event;
class EventAttr;
//class Payload;


class Agent
{
public:
	virtual ~Agent();
	Agent(AgentAttr* _attr, Hub* _hub);
	bool Subscribe(std::string _type, std::string _room, std::string _floor);
	bool Unsubscribe(std::string _type, std::string _room, std::string _floor);
	Event* GenerateEvent(std::string _timestamp,
            std::string _type,
            std::string _room,
            std::string _floor);
	bool PublishEvent(Event* _event);
	bool PushEvent(Event* _event);
	const Event* PopEvent();
	std::string GenerateTimestamp() const;
	const std::string& GetID() const;
	const std::string& GetType() const;
	const std::string& GetRoom() const;
	const std::string& GetFloor() const;
	const std::string& GetLog() const;
	const std::string& GetConfig() const;
//	EventAttr* GenerateEventAttr(std::string _type, std::string _room, std::string _floor);
//	virtual Event* ReceiveEvent()= 0;
	
private:
	Agent(const Agent& _agent);
	Agent& operator=(const Agent& _agent);
	
	AgentAttr*		        m_attributes;
	Hub*			        m_hub;
	std::queue<Event*>		m_queue; //TODO: make class and set size in destructor
	pthread_mutex_t	        m_mutex;
};



#endif //#ifndef __AGENT_H__

