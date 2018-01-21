#ifndef __CONFIGPARSER_H__
#define __CONFIGPARSER_H__

#include <string>
#include <fstream>
#include<vector>

//class Hub;
class HubInterface;
class Agent;
class AgentAttr;

typedef Agent* (*CreateAgentFunc)(AgentAttr* _agentAttr, HubInterface* _hub);

class ConfigLoader
{
	public:
		virtual ~ConfigLoader();
		ConfigLoader(std::string _soPath, std::string _iniPath);
		bool LoadConfig(std::vector<Agent*>& _agents, HubInterface* _hub); 
		
	private:
		bool LoadAgents(std::vector<Agent*>& _agents, HubInterface* _hub); 
		CreateAgentFunc GetCreateAgentFunc(std::string _type);
		Agent* CreateAgent(CreateAgentFunc _func,
									HubInterface* _hub, 
                                    std::string _ID, 
                                    std::string _type, 
                                    std::string _room, 
                                    std::string _floor, 
                                    std::string _log, 
                                    std::string _config); // Throws std::bad_alloc
        std::string 	    m_soPath;
		std::string 	    m_iniPath;
		std::string		    m_line;
		size_t			    m_linePosition;
		std::ifstream 	    m_fileStream;
		std::vector<void*>  m_soContainer;	
};

#endif //#ifndef __CONFIGPARSER_H__























