#ifndef __AGENT_H__
#define __AGENT_H__

#include<string>
#include<queue>
#include<pthread>
class Hub;
class AgentAttr;
class Event;
class EventAttr;


class Agent
{
public:
	virtual ~Agent();
	Agent(AgentAttr* _attr, Hub* _hub);
	bool Subscribe(std::string _type, std::string _room, std::string _floor);
	bool Unsubscribe(std::string _type, std::string _room, std::string _floor);
	const Event* GenerateEvent();
	bool PublishEvent(Event* _event);
	const std::string& GetID() const;
	const std::string& GetType() const;
	const std::string& GetRoom() const;
	const std::string& GetFloor() const;
	const std::string& GetLog() const;
	const std::string& GetConfig() const;
	virtual EventAttr* GenerateEventAttr() = 0;
	virtual Event* ReceiveEvent()= 0;
	
private:
//	std::string 	m_ID;
//	std::string 	m_type;
//	std::string 	m_room;
//	std::string 	m_floor;
//	std::string 	m_log;
//	std::string 	m_config;
	Agent(const Agent& _agent);
	Agent& operator=(const Agent& _agent)
	
	AgentAttr*		m_attributes;
	Hub*			m_hub;
	std::queue		m_queue;
	pthread_mutex_t	m_mutex;
};



#endif //#ifndef __AGENT_H__

