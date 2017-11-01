#include "ConfigLoader.h"
#include<iostream>
#include <fstream>

using namespace std;

//#include "../Hub/Hub.h"
//#include "../AgentFactory/AgentFactory.h"
//#include "../Agent/Agent.h"


ConfigLoader::ConfigLoader(string _soPath, string _iniPath)
{	
//	m_agentFactory = new AgentFactory;
	
	if (0 == m_agentFactory)
	{
		// Handle failed new
	}

	m_soPath = _soPath;
	
	m_iniPath = _iniPath;	
	
	m_line = "";
	
	m_linePosition = 0;
}


ConfigLoader::~ConfigLoader()
{
//	delete m_agentFactory;
}


//bool ConfigLoader::LoadConfig(multimap<string, Agent*> _agents, Hub* _hub)
bool ConfigLoader::LoadConfig() // remove this
{
//	m_fileStream.open(m_iniPath, ios_base::in); 
	m_fileStream.open(m_iniPath.c_str(), ios_base::in); 
//	if (0  != m_fileStream)
//	{
//		return false;
//	}
	
	if (false == m_fileStream.good())
	{
		return false;
	}
	
	
	LoadAgents();
	
	/*
		Pseudo Code:
		------------
		Open Ini File
		While (!eof)
		{
			Retrieve config attributes for agent (example for type:			"Yamaha_SD101") TODO: AgentAttr class
			Find .so file for company 			(example file name: 		Yamaha.so)
			Load AgentCreate Function from .so	(example create func name:	create_SD101(...))
			TODO: Load and store PayloadFactory  as member in Agent. Pass to EventFactory as parameter when used.
			Create New Agent in Hub AgentContainer
		}
	*/

}


bool ConfigLoader::LoadAgents()
{
	bool isEndOfAgent = false;
	size_t position = 0;
	
//	AgentAttr* attr = new AgentAttr;	
//	if (0 == attr)
//	{
//		// Handle failed new
//	}
	
	while(1)
	{
		std::getline(m_fileStream, m_line);
	
		if(m_fileStream.eof())
		{
			break;
		}
		
		m_linePosition = 0;
		position = 0;	
		
		while (!isEndOfAgent)
		{
			m_linePosition = m_line.find_first_of("[", m_linePosition);
			
			if (string::npos == position)
			{
				return false;
			}
			
			cout << m_linePosition;
			
			break; //remove
		}
		break;//remove
	}
}


bool ConfigLoader::LoadSharedObject()
{


}




