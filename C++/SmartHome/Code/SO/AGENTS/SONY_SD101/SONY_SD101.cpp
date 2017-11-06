#include "SONY_SD101.h"
#include "../../../Agent/Agent.h"
#include "../../../Event/Event.h"
#include<iostream> //REMOVE
#include<unistd.h>


SONY_SD101::SONY_SD101(AgentAttr* _agentAttr, Hub* _hub) : Agent::Agent(_agentAttr, _hub)
{
    //option: Do something with config string
    std::cout << "In SD101 constructor" << std::endl;
}


SONY_SD101::~SONY_SD101()
{
    //empty
    std::cout << "In SD101 destructor" << std::endl;
}


//void SONY_SD101::CreateSubscriptions()
//{
//    
//}


void SONY_SD101::DoOnEvent(std::tr1::shared_ptr<Event>)
{
    //Empty because this is a sensor
}


void SONY_SD101::DoRoutine()
{
    while(1)
    {
        std::tr1::shared_ptr<Event> event(new Event(GenerateTimestamp(),
                                                    GetType(),
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


//EventAttr* SONY_SD101::GenerateEventAttr(std::string _type, std::string _room, std::string _floor)
//{
//    string time = GenerateTimestamp();
//    EventAttr* eventAttr = new EventAttr(time, _type, _room, _floor);
//}

//Payload_SD101::GeneratePayload()
//{
//    int sensorReading = 50;
//    m_smokePercentage = sensorReading;
//}

