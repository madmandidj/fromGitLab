#ifndef __CONFIGPARSER_H__
#define __CONFIGPARSER_H__

#include <string>
#include <fstream>
#include <map>

using namespace std;

class Hub;
class AgentFactory;
class Agent;

class ConfigLoader
{
	public:
		ConfigLoader(string _soPath, string _iniPath);
		~ConfigLoader();
		bool LoadConfig(multimap<string, Agent*> _agents, Hub* _hub); //TODO: Make AgentContainer class
		bool LoadConfig();
		
	private:
		bool LoadAgents();
		bool LoadSharedObject();
		
		string 			m_soPath;
		string 			m_iniPath;
		string			m_line;
		size_t			m_linePosition;
		ifstream 		m_fileStream;
		AgentFactory* 	m_agentFactory;
		
};

#endif //#ifndef __CONFIGPARSER_H__

