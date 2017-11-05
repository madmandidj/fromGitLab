#ifndef __CONFIGPARSER_H__
#define __CONFIGPARSER_H__

#include <string>
#include <fstream>
//#include <map>
#include<vector>

class Hub;
class Agent;

class ConfigLoader
{
	public:
		ConfigLoader(std::string _soPath, std::string _iniPath);
		~ConfigLoader();
		bool LoadConfig(std::vector<Agent*>& _agents, Hub* _hub); //TODO: Make AgentContainer class
//		bool LoadConfig();
		
	private:
		bool LoadAgents();
		bool LoadSharedObject();
		
        std::string 	m_soPath;
		std::string 	m_iniPath;
		std::string		m_line;
		size_t			m_linePosition;
		std::ifstream 	m_fileStream;
//		AgentFactory* 	m_agentFactory;
		
};

#endif //#ifndef __CONFIGPARSER_H__

