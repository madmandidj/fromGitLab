#include "HITACHI_SPRINK2000.h"
#include "../../../Agent/Agent.h"
#include "../../../Event/Event.h"
#include<unistd.h>
#include<iostream>


HITACHI_SPRINK2000::HITACHI_SPRINK2000(AgentAttr* _agentAttr, Hub* _hub) : Agent::Agent(_agentAttr, _hub)
{
    Subscribe("FIRE", "room_2_a", "1");
    Subscribe("FIRE", "room_2_a", "1");
    Subscribe("DOOR_OPEN", "room_2_a", "1");
}


HITACHI_SPRINK2000::~HITACHI_SPRINK2000()
{
    //Empty
}


void HITACHI_SPRINK2000::DoOnEvent(std::tr1::shared_ptr<Event> _event)
{
    std::cout << "Agent: " << GetID() << " Received " << _event->GetType() << " ";
    std::cout << _event->GetTimestamp() << " ";
    std::cout << _event->GetRoom() << " ";
    std::cout << _event->GetFloor() << std::endl;
}

void HITACHI_SPRINK2000::DoRoutine()
{
    while(1)
    {
        std::tr1::shared_ptr<Event> event = PopEvent();
    
        DoOnEvent(event);
    }                          
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
