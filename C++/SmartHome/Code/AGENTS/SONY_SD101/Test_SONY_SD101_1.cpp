#include "../../Agent/Agent.h"
#include "../../AgentAttr/AgentAttr.h"
#include "../../Hub/Hub.h"
#include "../../Event/Event.h"
#include "SONY_SD101.h"
#include <iostream>
#include <dlfcn.h>
#include <string>
#include <unistd.h>

using namespace std;

typedef Agent* (*CreateAgentFunc)(AgentAttr* _eventAttr, Hub* _hub);

int main()
{
    string soName = "/SONY_SD101.so";
    
    string cwd = get_current_dir_name() + soName;
    
    cout << cwd << endl;
    
    void* myso = dlopen(cwd.c_str(), RTLD_NOW);
    
//    void* myso = dlopen("/home/eyalalon2/Desktop/compMove/Experis/work/C++/SmartHome/Code/AGENTS/SONY_SD101/SONY_SD101.so", RTLD_NOW);
    
//    cout << "hmmm" << endl; 
    
//    cout << dlerror() << endl;
    
    
    cout << "hmmm" << endl;    
    CreateAgentFunc func = (CreateAgentFunc)dlsym(myso, "CreateAgent");
    
    Hub* hub = new Hub();
    
    AgentAttr* agentAttr = new AgentAttr("SONY_SD101",
                                            "SMOKE_DETECTOR",
                                            "11_B",
                                            "2",
                                            "SMOKE_LOG",
                                            "sensitivity = 80");
    
    Agent* newAgent = func(agentAttr, hub);
    
    string yo = newAgent->GetID();
    
    cout << yo << endl;
    
    Event* event = new Event("12:59:59", "SMOKE_DETECTED", "12_B", "3");
    
    newAgent->DoOnEvent(event);

    delete newAgent;
    
    delete hub;
    
    delete event;
    
    dlclose(myso);
	
	return 0;
}
