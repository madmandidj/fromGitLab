#include "ConfigLoader.h"

//#include "../Hub/Hub.h"
//#include "../AgentFactory/AgentFactory.h"
//#include "../Agent/Agent.h"


ConfigLoader::ConfigLoader(string _soPath, string _iniPath)
{	
	m_agentFactory = new AgentFactory;

	m_soPath = _soPath;
	
	m_iniPath = _iniPath;	
}


ConfigLoader::~ConfigLoader()
{
	delete m_agentFactory;
}


bool ConfigLoader::LoadConfig(multimap<string, Agent*> _agents, Hub* _hub)
{
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


bool ConfigLoader::ParseDevice()
{


}


bool ConfigLoader::LoadSharedObject()
{


}




