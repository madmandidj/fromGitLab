#ifndef __AGENT_ATTR_H__
#define __AGENT_ATTR_H__


#include<string>


class AgentAttr
{
public:
	virtual ~AgentAttr();
	AgentAttr(std::string _ID,
				std::string _type,
				std::string _room,
				std::string _floor,
				std::string _log,
				std::string _config);	
	const std::string& GetID() const;
	const std::string& GetType() const;
	const std::string& GetRoom() const;
	const std::string& GetFloor() const;
	const std::string& GetLog() const;
	const std::string& GetConfig() const;
	
private:
	Agent(const Agent& _agent);
	Agent& operator=(const Agent& _agent)
	
	std::string		m_ID;
	std::string 	m_type;
	std::string 	m_room;
	std::string 	m_floor;
	std::string 	m_log;
	std::string 	m_config;
};








#endif //#ifndef __AGENT_ATTR_H__



