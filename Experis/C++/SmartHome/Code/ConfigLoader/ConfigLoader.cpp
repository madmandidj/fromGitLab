#include "ConfigLoader.h"
#include "../AgentAttr/AgentAttr.h"
//#include "../Hub/Hub.h"
#include "../HubInterface/HubInterface.h"
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
	while(!m_fileStream.eof())
	{
		temp_type = "";
	    temp_room = "";
	    temp_floor = "";
	    temp_log = "";
	    temp_config = "";
	    temp_str = "";
	    
	    //Get ID
	    std::getline(m_fileStream, m_line);
	    leftPos = m_line.find_first_of("[", leftPos);
		rightPos = m_line.find_first_of("]", leftPos + 1);
		temp_ID = m_line.substr(leftPos + 2, rightPos - leftPos - 2);
		
		//GetType
		std::getline(m_fileStream, m_line);
		leftPos = 0;
        rightPos = 0;
		leftPos = m_line.find_first_of("=", leftPos);
		temp_type = m_line.substr(leftPos + 2, m_line.size() - leftPos + 2);
		
		//GetRoom
		std::getline(m_fileStream, m_line);
		leftPos = 0;
        rightPos = 0;
		leftPos = m_line.find_first_of("=", leftPos);
		temp_room = m_line.substr(leftPos + 2, m_line.size() - leftPos + 2);
		
		//GetFloor
		std::getline(m_fileStream, m_line);
		leftPos = 0;
        rightPos = 0;
		leftPos = m_line.find_first_of("=", leftPos);
		temp_floor = m_line.substr(leftPos + 2, m_line.size() - leftPos + 2);
		
		//GetLog
		std::getline(m_fileStream, m_line);
		//Check if blank parameter
		leftPos = 0;
        rightPos = 0;
		leftPos = m_line.find_first_of("=", leftPos);
		temp_log = m_line.substr(leftPos + 2, m_line.size() - leftPos + 2);
		
		//GetConfig
	    std::getline(m_fileStream, m_line);
		leftPos = 0;
        rightPos = 0;
		leftPos = m_line.find_first_of("=", leftPos);
		temp_config = m_line.substr(leftPos + 2, m_line.size() - leftPos + 2);
		
		
		
		
		
		
		
		
		func = GetCreateAgentFunc(temp_type);
	    if (0 == func)
	    {
	    	return false;
	    }

        Agent* agent = CreateAgent(func, _hub, temp_ID, temp_type, temp_room, temp_floor, temp_log, temp_config);

	    _agents.push_back(agent);
	    
	    //Get blank line or end of file
	    std::getline(m_fileStream, m_line);
	}

	return true;
}


CreateAgentFunc ConfigLoader::GetCreateAgentFunc(std::string _type)
{
    std::string soFilePath;
    void* curSO;
    soFilePath = m_soPath + _type + ".so";
    curSO = dlopen(soFilePath.c_str(), RTLD_NOW);
    if (0 == curSO)
    {
    	return 0;
    }
    m_soContainer.push_back(curSO);
    CreateAgentFunc func = (CreateAgentFunc)dlsym(curSO, "CreateAgent");
    if (0 == func)
    {
    	return 0;
    }
		    
    return func;
}


Agent* ConfigLoader::CreateAgent(CreateAgentFunc _func,
									HubInterface* _hub,
                                    std::string _ID, 
                                    std::string _type, 
                                    std::string _room, 
                                    std::string _floor, 
                                    std::string _log, 
                                    std::string _config)
{
    AgentAttr* agentAttr = new AgentAttr(_ID, _type, _room, _floor, _log, _config);
    
    Agent* agent;
    
    try
    {
		agent = _func(agentAttr, _hub);
    }
    catch(std::bad_alloc& _exc)
    {
    	delete agentAttr;
    	throw;
    }
    
    return agent;
}


