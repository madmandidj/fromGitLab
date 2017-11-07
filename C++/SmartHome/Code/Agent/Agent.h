#ifndef __AGENT_H__
#define __AGENT_H__

#include<string>
#include<queue>
#include<pthread.h>
#include<tr1/memory>
#include<stdexcept>

class HubInterface;
class AgentAttr;
class Event;
class EventAttr;

class Agent
{
public:
	virtual ~Agent();
	Agent(AgentAttr* _attr, HubInterface* _hub); // Throws std::runtime_error
	bool Subscribe(std::string _type, std::string _room, std::string _floor) const;
	bool Unsubscribe(std::string _type, std::string _room, std::string _floor) const;
	void CreateAgentThread();
	bool PushEvent(std::tr1::shared_ptr<Event> _event);
    const std::string& GetID() const;
	const std::string& GetType() const;
	const std::string& GetRoom() const;
	const std::string& GetFloor() const;
	const std::string& GetLog() const;
	const std::string& GetConfig() const;
	const pthread_t& GetThread() const;
	
protected:
	bool PublishEvent(std::tr1::shared_ptr<Event> _event) const;
    std::tr1::shared_ptr<Event> PopEvent();
	std::string GenerateTimestamp() const; 	
	static void* AgentTrampoline(void* _agent); // Throws ...
	virtual void DoOnEvent(std::tr1::shared_ptr<Event> _event) = 0; // Throws ...
	virtual void DoRoutine() = 0; // Throws ...
	static size_t GetMaxQueueSize();
	
private:
	Agent(const Agent& _agent);
	Agent& operator=(const Agent& _agent);
	
	AgentAttr*		                                m_attributes;
	HubInterface*			                        m_hub;
	std::queue<std::tr1::shared_ptr<Event> >		m_queue;
	pthread_mutex_t	                                m_mutex;
	pthread_cond_t                                  m_condVar;
	static size_t                                   m_maxQueueSize;
	pthread_t                                       m_thread;
};



#endif //#ifndef __AGENT_H__

