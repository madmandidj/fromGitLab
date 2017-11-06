#include "SONY_SD101.h"
#include "../../../Agent/Agent.h"
#include "../../../Event/Event.h"
#include<iostream> //REMOVE
#include<unistd.h>


SONY_SD101::SONY_SD101(AgentAttr* _agentAttr, Hub* _hub) : Agent::Agent(_agentAttr, _hub)
{
    //Empty
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
        sleep(3);                                            
    }
}


extern "C" SONY_SD101* CreateAgent(AgentAttr* _agentAttr, Hub* _hub)
{
    SONY_SD101* newSD101 = new SONY_SD101(_agentAttr, _hub);
    if (0 == newSD101)
    {
        //TODO: handle bad alloc
    }
    
    return newSD101;
}



































