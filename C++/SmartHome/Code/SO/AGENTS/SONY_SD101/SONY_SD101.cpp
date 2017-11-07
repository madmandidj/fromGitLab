#include "SONY_SD101.h"
#include "../../../Agent/Agent.h"
#include "../../../AgentAttr/AgentAttr.h"
#include "../../../Event/Event.h"
#include "../../../HubInterface/HubInterface.h"
#include<iostream> //REMOVE
#include<unistd.h>
#include<stdio.h>


//SONY_SD101::SONY_SD101(AgentAttr* _agentAttr, Hub* _hub) : Agent::Agent(_agentAttr, _hub)
SONY_SD101::SONY_SD101(AgentAttr* _agentAttr, HubInterface* _hub) : Agent::Agent(_agentAttr, _hub)
{
    if (_agentAttr->GetConfig() != "")
	{
		std::string config = _agentAttr->GetConfig();
		sscanf(config.c_str(), "%u", &m_sleepSec);
//		std::cout << m_sleepSec << std::endl;
	}
}


SONY_SD101::~SONY_SD101()
{
    //Empty
}


void SONY_SD101::DoOnEvent(std::tr1::shared_ptr<Event>)
{
    //Empty - SONY_SD101 is a sensor
}


void SONY_SD101::DoRoutine()
{
    while(1)
    {
        std::tr1::shared_ptr<Event> event(new Event(GenerateTimestamp(),
                                                    "FIRE",
                                                    GetRoom(),
                                                    GetFloor()));
        PublishEvent(event);
        sleep(m_sleepSec);   //TODO: change this to m_sleepSec, and check why doesnt seem to work
    }
}


//extern "C" SONY_SD101* CreateAgent(AgentAttr* _agentAttr, Hub* _hub)
extern "C" SONY_SD101* CreateAgent(AgentAttr* _agentAttr, HubInterface* _hub)
{
    SONY_SD101* newSD101 = new SONY_SD101(_agentAttr, _hub);
    if (0 == newSD101)
    {
        //TODO: handle bad alloc
    }
    
    return newSD101;
}



































