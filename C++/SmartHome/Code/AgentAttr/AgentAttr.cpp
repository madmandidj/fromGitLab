#include "AgentAttr.h"


AgentAttr::~AgentAttr()
{
    //Empty
}


AgentAttr::AgentAttr(std::string _ID,
				std::string _type,
				std::string _room,
				std::string _floor,
				std::string _log,
				std::string _config)
				: m_ID(_ID),
					m_type(_type),
					m_room(_room),
					m_floor(_floor),
					m_log(_log),
					m_config(_config)
{
	//Empty
}


const std::string& AgentAttr::GetID() const
{
	return m_ID;
}


const std::string& AgentAttr::GetType() const
{
	return m_type;
}

const std::string& AgentAttr::GetRoom() const
{
	return m_room;
}

const std::string& AgentAttr::GetFloor() const
{
	return m_floor;
}

const std::string& AgentAttr::GetLog() const
{
	return m_log;
}

const std::string& AgentAttr::GetConfig() const
{
	return m_config;
}

