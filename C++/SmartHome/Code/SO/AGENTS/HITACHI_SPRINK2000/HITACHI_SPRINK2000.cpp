#include "HITACHI_SPRINK2000.h"
#include "../../../Agent/Agent.h"
#include "../../../Event/Event.h"
#include<unistd.h>
#include<iostream> //REMOVE


HITACHI_SPRINK2000::HITACHI_SPRINK2000(AgentAttr* _agentAttr, Hub* _hub) : Agent::Agent(_agentAttr, _hub)
{
    //option: Do something with config string
    std::cout << "In SD101 constructor" << std::endl;
    Subscribe("SONY_SD101", "room_2_a", "1");
}


HITACHI_SPRINK2000::~HITACHI_SPRINK2000()
{
    //empty
    std::cout << "In SD101 destructor" << std::endl;
}


void HITACHI_SPRINK2000::DoOnEvent(std::tr1::shared_ptr<Event> _event)
{
    std::cout << "Agent" << GetID() << "received event of type " << _event->GetType()
                << "---> turning on sprinklers" << std::endl;
}

void HITACHI_SPRINK2000::DoRoutine()
{
    sleep(2);
    
    std::tr1::shared_ptr<Event> event = PopEvent();
    
    DoOnEvent(event);                           
}

extern "C" HITACHI_SPRINK2000* CreateAgent(AgentAttr* _agentAttr, Hub* _hub)
{
    HITACHI_SPRINK2000* hitSprink2000 = new HITACHI_SPRINK2000(_agentAttr, _hub);
    if (0 == hitSprink2000)
    {
        //TODO: handle bad alloc
    }
    
    return hitSprink2000;
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

