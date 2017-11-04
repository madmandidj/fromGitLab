#include "Hub.h"
#include "../Agent/Agent.h"
#include "../AgentAttr/AgentAttr.h"
#include "../EventAttr/EventAttr.h"
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

    EventAttr* eventAttr = new EventAttr("", "SMOKE_DETECTOR", "12_D", "3");
    EventAttr* eventAttr2 = new EventAttr("", "SMOKE_DETECTOR", "12_D", "6");

    hub->AddSubscription(eventAttr, agent1);

//    hub->AddSubscription(eventAttr, agent1);
    hub->AddSubscription(eventAttr2, agent1);
    hub->RemoveSubscription(eventAttr2, agent1);
    hub->AddSubscription(eventAttr2, agent1);
    hub->RemoveSubscription(eventAttr2, agent1);
    
    string str = agent1->GenerateTimestamp();
    
    cout << "THIS IS: " << str << endl;

    delete agent1;                                       
    delete agent2;
    delete eventAttr;
    delete hub;

    return 0;
}










