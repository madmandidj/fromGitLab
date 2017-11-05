#include "../Agent/Agent.h"
#include "../AgentAttr/AgentAttr.h"
#include "../Hub/Hub.h"
#include "../Event/Event.h"
#include "../EventAttr/EventAttr.h"
#include <iostream>
#include <dlfcn.h>
#include <string>
#include <unistd.h>

using namespace std;

typedef Agent* (*CreateAgentFunc)(AgentAttr* _eventAttr, Hub* _hub);

int main()
{
    string soName = "/SONY_SD101.so";
    string relativePath = "/home/eyalalon2/Desktop/compMove/Experis/work/C++/SmartHome/Code/AGENTS/SONY_SD101";
    
    string cwd = relativePath + soName;
    
    cout << cwd << endl;
    
    void* myso = dlopen(cwd.c_str(), RTLD_NOW); 
    
    CreateAgentFunc func = (CreateAgentFunc)dlsym(myso, "CreateAgent");
    
    Hub* hub = new Hub();
    
    AgentAttr* agentAttr = new AgentAttr("SONY_SD101_1",
                                            "SMOKE_DETECTOR",
                                            "11_B",
                                            "2",
                                            "SMOKE_LOG",
                                            "sensitivity = 80");
                                            
    AgentAttr* agentAttr2 = new AgentAttr("SONY_SD101_2",
                                            "SMOKE_DETECTOR",
                                            "11_B",
                                            "2",
                                            "SMOKE_LOG",
                                            "sensitivity = 80");        
    
    Agent* newAgent = func(agentAttr, hub);
    
    Agent* newAgent2 = func(agentAttr2, hub);
    
    Event* event = new Event("12:59:59", "SMOKE_DETECTED", "12_B", "3");
    
//    EventAttr* eventAttr = new EventAttr("", "SMOKE_DETECTED", "12_B", "3");
    
    newAgent->Subscribe("SMOKE_DETECTED", "12_B", "3");
    
    newAgent2->Subscribe("SMOKE_DETECTED", "12_B", "3");
    
    newAgent2->PublishEvent(event);

    delete newAgent;
    
    delete newAgent2;
    
    delete hub;
    
    delete event;
    
    dlclose(myso);
	
	return 0;
}







