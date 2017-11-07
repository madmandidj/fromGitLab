#include "ConfigLoader.h"
#include "../AgentAttr/AgentAttr.h"
#include "../Hub/Hub.h"
#include "../Agent/Agent.h"
#include<iostream>
#include<fstream>
#include<dlfcn.h>

using namespace std;

ConfigLoader::ConfigLoader(string _soPath, string _iniPath)
{	
	m_soPath = _soPath;
	
	m_iniPath = _iniPath;	
	
	m_line = "";
	
	m_linePosition = 0;
}


ConfigLoader::~ConfigLoader()
{
    std::vector<void*>::iterator leftIt = m_soContainer.begin();
    std::vector<void*>::iterator rightIt = m_soContainer.end();
    
    while(leftIt != rightIt)
    {
        dlclose(*leftIt);
        ++leftIt;
    }
}


//bool ConfigLoader::LoadConfig(vector<Agent*>& _agents, Hub* _hub)
bool ConfigLoader::LoadConfig(vector<Agent*>& _agents, HubInterface* _hub)
{
	m_fileStream.open(m_iniPath.c_str(), ios_base::in); 
	
	if (false == m_fileStream.good())
	{
		return false;
	}
	
	
	LoadAgents(_agents, _hub);
	
	std::cout << "ConfigLoader: Finished Loading Agents" << std::endl << std::endl;

	return true;
}


//bool ConfigLoader::LoadAgents(std::vector<Agent*>& _agents, Hub* _hub)
bool ConfigLoader::LoadAgents(std::vector<Agent*>& _agents, HubInterface* _hub)
{
	size_t leftPos = 0;
	size_t rightPos = 0;
	string temp_ID;
	string temp_type;
	string temp_room;
	string temp_floor;
	string temp_log;
	string temp_config;
	string temp_str;
	string soFilePath;
	CreateAgentFunc func;
	
	while(1)
	{
	    temp_type = "";
	    temp_room = "";
	    temp_floor = "";
	    temp_log = "";
	    temp_config = "";
	    temp_str = "";
	    //Get next line and check if eof
		std::getline(m_fileStream, m_line);
		if(m_fileStream.eof())
		{
			break;
		}
        leftPos = 0;
        rightPos = 0;

        //Get ID
		leftPos = m_line.find_first_of("[", leftPos);
		if (string::npos == leftPos)
		{
			return false;
		}
		rightPos = m_line.find_first_of("]", leftPos + 1);
		temp_ID = m_line.substr(leftPos + 1, rightPos - leftPos - 1);
		
		//Get Type
		std::getline(m_fileStream, m_line);
		leftPos = 0;
        rightPos = 0;
		leftPos = m_line.find_first_of("=", leftPos);
		if (string::npos == leftPos)
		{
			return false;
		}
		temp_type = m_line.substr(leftPos + 2, m_line.size() - leftPos + 2);
		
		//Get Room
		std::getline(m_fileStream, m_line);
		leftPos = 0;
        rightPos = 0;
		leftPos = m_line.find_first_of("=", leftPos);
		if (string::npos == leftPos)
		{
			return false;
		}
		temp_room = m_line.substr(leftPos + 2, m_line.size() - leftPos + 2);
		
		//Get Floor
		std::getline(m_fileStream, m_line);
		leftPos = 0;
        rightPos = 0;
		leftPos = m_line.find_first_of("=", leftPos);
		if (string::npos == leftPos)
		{
			return false;
		}
		temp_floor = m_line.substr(leftPos + 2, m_line.size() - leftPos + 2);
		
		//Check if eof
		std::getline(m_fileStream, m_line);
		if(m_fileStream.eof())
		{
			break;
		}
		if ("" == m_line)
		{
		    func = GetCreateAgentFunc(temp_type);

            Agent* agent = CreateAgent(func, _hub, temp_ID, temp_type, temp_room, temp_floor, temp_log, temp_config);            

		    _agents.push_back(agent);
		    
		    continue;
		}
		
		//Check optional parameters
		leftPos = 0;
        rightPos = 0;
		rightPos = m_line.find_first_of("=", rightPos);
		if (string::npos == rightPos)
		{
			return false;
		}
		temp_str = m_line.substr(leftPos, rightPos - 1);
		//Check if log
		if (temp_str == "log")
		{
		    temp_log = m_line.substr(rightPos + 2, m_line.size() - rightPos + 2);
		}
		//Check if config
		else if(temp_str == "config")
		{
		    temp_config = m_line.substr(rightPos + 2, m_line.size() - rightPos + 2);
		}
		else
		{
		    //REDUNDANT
		    continue;
		}
		
		//Check if eof
		std::getline(m_fileStream, m_line);
		if(m_fileStream.eof())
		{
			break;
		}
		if ("" == m_line)
		{
		    func = GetCreateAgentFunc(temp_type);

            Agent* agent = CreateAgent(func, _hub, temp_ID, temp_type, temp_room, temp_floor, temp_log, temp_config);            

		    _agents.push_back(agent);

		    continue;
		}
	
		leftPos = 0;
        rightPos = 0;
		rightPos = m_line.find_first_of("=", rightPos);
		if (string::npos == rightPos)
		{
			return false;
		}
		temp_str = m_line.substr(leftPos, rightPos - 1);
		//Check if Config
		if (temp_str == "config")
		{
		    temp_config = m_line.substr(rightPos + 2, m_line.size() - rightPos + 2);
		}
		
		std::getline(m_fileStream, m_line);
		if(m_fileStream.eof())
		{
			break;
		}
		if ("" == m_line)
		{
            func = GetCreateAgentFunc(temp_type);
            Agent* agent = CreateAgent(func, _hub, temp_ID, temp_type, temp_room, temp_floor, temp_log, temp_config);            
		    _agents.push_back(agent);
		    continue;
		}
	}
	return true;
}


CreateAgentFunc ConfigLoader::GetCreateAgentFunc(std::string _type)
{
    std::string soFilePath;
    void* curSO;
    soFilePath = m_soPath + _type + ".so";
    curSO = dlopen(soFilePath.c_str(), RTLD_NOW);
    m_soContainer.push_back(curSO);
    CreateAgentFunc func = (CreateAgentFunc)dlsym(curSO, "CreateAgent");
		    
    return func;
}


Agent* ConfigLoader::CreateAgent(CreateAgentFunc _func,
									HubInterface* _hub,
//                                    Hub* _hub, 
                                    std::string _ID, 
                                    std::string _type, 
                                    std::string _room, 
                                    std::string _floor, 
                                    std::string _log, 
                                    std::string _config)
{
    AgentAttr* agentAttr = new AgentAttr(_ID, _type, _room, _floor, _log, _config);
    if (0 == agentAttr)
    {
        //TODO: handle bad alloc
    }
    Agent* agent = _func(agentAttr, _hub);
    if (0 == agent)
    {
        //TODO: handle bad alloc
    }
    
    return agent;
}


