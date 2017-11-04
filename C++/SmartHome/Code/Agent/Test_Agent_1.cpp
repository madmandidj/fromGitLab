#include "Agent.h"
#include "../AgentAttr/AgentAttr.h"
#include "../Hub/Hub.h"
#include<iostream>
#include<string>

using namespace std;




int main()
{
    Hub* hub = new Hub();
    
    AgentAttr* agentAttr = new AgentAttr("SONY_SD101",
                                            "SMOKE_DETECTOR",
                                            "11_B",
                                            "2",
                                            "SMOKE_LOG",
                                            "sensitivity = 80");   
    
    AgentAttr* agentAttr2 = new AgentAttr("SONY_SPRINK1",
                                            "SPRINKLERS",
                                            "11_B",
                                            "2",
                                            "SPRINKLERS_LOG",
                                            "speed = 50"); 
    
    Agent* agent1 = new Agent(agentAttr, hub);
    Agent* agent2 = new Agent(agentAttr2, hub);
    
    delete agent1;                                       
    delete agent2;
    delete hub;
    
    return 0;
}


