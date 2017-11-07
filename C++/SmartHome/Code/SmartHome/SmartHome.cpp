#include "SmartHome.h"
#include "../Hub/Hub.h"
#include "../ConfigLoader/ConfigLoader.h"
#include "../Agent/Agent.h"
#include<string>


SmartHome::SmartHome(std::string _soPath, std::string _iniPath)
{
    m_hub = new Hub();
    if (0 == m_hub)
    {
        //TODO: handle bad alloc
    }
    
    m_configLoader = new ConfigLoader(_soPath, _iniPath);
    if (0 == m_configLoader)
    {
        delete m_hub;
        //TODO: handle bad alloc
    }
}


SmartHome::~SmartHome()
{
	std::vector<Agent*>::iterator begin = m_agentContainer.begin();
	std::vector<Agent*>::iterator end = m_agentContainer.end();
	pthread_t thread;
	while (begin != end)
	{
		thread = (*begin)->GetThread();
		delete *begin;
		pthread_join(thread, NULL);
		++begin;
	}
    m_agentContainer.clear();
    
    delete m_hub;
    delete m_configLoader;
}


void SmartHome::LoadSmartHome()
{
    m_configLoader->LoadConfig(m_agentContainer, m_hub);
}


void SmartHome::Run()
{
    std::vector<Agent*>::iterator leftIt = m_agentContainer.begin();
    std::vector<Agent*>::iterator rightIt = m_agentContainer.end();
    
    while(leftIt != rightIt)
    {
        (*leftIt)->CreateAgentThread();
        ++leftIt;
    }    
}


void SmartHome::Quit()
{
    //TODO: implement if needed
}


void SmartHome::SetLivePrintMode(bool _shouldLivePrint)
{
    m_hub->SetLivePrintMode(_shouldLivePrint);
}


size_t SmartHome::GetNumOfAgents() const
{
    return m_agentContainer.size();
}

















