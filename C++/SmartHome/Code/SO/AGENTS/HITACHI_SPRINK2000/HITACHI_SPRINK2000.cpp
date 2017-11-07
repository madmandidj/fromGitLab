#include "HITACHI_SPRINK2000.h"
#include "../../../Agent/Agent.h"
#include "../../../AgentAttr/AgentAttr.h"
#include "../../../Event/Event.h"
#include "../../../HubInterface/HubInterface.h"
#include<unistd.h>
#include<string>
#include<exception>
#include<iostream>


HITACHI_SPRINK2000::HITACHI_SPRINK2000(AgentAttr* _agentAttr, HubInterface* _hub) : Agent::Agent(_agentAttr, _hub)
{
	if (0 == _agentAttr || 0 == _hub)
	{
		throw std::runtime_error("HITACHI_SPRINK2000::HITACHI_SPRINK2000 invalid parameters");
	}
	if (_agentAttr->GetConfig() != "") 	
	{ 		
		std::string config = _agentAttr->GetConfig(); 		
		std::string eventType; 		
		std::string eventRoom; 		
		std::string eventFloor; 		
		size_t curPos = 0; 		
		size_t nextPos = 0;
		size_t newTokenPos = 0; 
		unsigned int subscriptionCount = 0;		
		while (std::string::npos != nextPos) 		
		{ 	
			newTokenPos = config.find_first_of("|", curPos);
//			std::cout << "newTokenPos" << newTokenPos << std::endl;
//			std::cout << "nextPos" << nextPos << std::endl;
			while(nextPos < newTokenPos)
			{
				nextPos = config.find_first_of(",", curPos);
				if (nextPos == std::string::npos)
				{
					return;
				}
				switch(subscriptionCount)
				{
					case 0:
						eventType = config.substr(curPos, nextPos-curPos); 			
						curPos = nextPos + 1;
						++subscriptionCount;
						continue;
						
					case 1:
//						nextPos = config.find_first_of(",", curPos); 			
						eventFloor = config.substr(curPos, nextPos-curPos); 			
						curPos = nextPos + 1; 
						++subscriptionCount;
						continue;
					
					case 2:
//						nextPos = config.find_first_of(",", curPos); 			
						eventRoom = config.substr(curPos, nextPos-curPos); 			
						curPos = nextPos + 2;
						subscriptionCount = 0;
						break;
					default:
						return;
				}
				Subscribe(eventType.c_str(), eventRoom.c_str(), eventFloor.c_str());
			}
			
//			Subscribe(eventType.c_str(), eventRoom.c_str(), eventFloor.c_str()); 		
					
//			nextPos = config.find_first_of(",", curPos); 			
//			eventType = config.substr(curPos, nextPos-curPos); 			
//			curPos = nextPos + 1;
//			 										
//			nextPos = config.find_first_of(",", curPos); 			
//			eventFloor = config.substr(curPos, nextPos-curPos); 			
//			curPos = nextPos + 1; 
//			
//			nextPos = config.find_first_of(",", curPos); 			
//			eventRoom = config.substr(curPos, nextPos-curPos); 			
//			curPos = nextPos + 1; 
															
//			Subscribe(eventType.c_str(), eventRoom.c_str(), eventFloor.c_str()); 		
		} 			
	}
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


extern "C" HITACHI_SPRINK2000* CreateAgent(AgentAttr* _agentAttr, HubInterface* _hub)
{
    HITACHI_SPRINK2000* hitSprink2000 = new HITACHI_SPRINK2000(_agentAttr, _hub);
    
    return hitSprink2000;
}
