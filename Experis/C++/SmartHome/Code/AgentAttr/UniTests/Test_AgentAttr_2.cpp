#include "AgentAttr.h"
#include<iostream>


using namespace std;

int main()
{
    
    AgentAttr* agentAttr = new AgentAttr("SONY_SD101",
                                            "SMOKE_DETECTOR",
                                            "11_B",
                                            "2",
                                            "SMOKE_LOG",
                                            "sensitivity = 80");
                                            
    cout << agentAttr->GetID() << endl;                                            
                                            
    return 0;
}



