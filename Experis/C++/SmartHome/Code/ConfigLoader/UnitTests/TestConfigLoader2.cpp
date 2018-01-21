#include "ConfigLoader.h"
#include "../Agent/Agent.h"
#include "../Hub/Hub.h"

using namespace std;

int main()
{
	ConfigLoader* configLoader = new ConfigLoader("../SO/", "../INI/Config.ini");
	
	Hub* hub = new Hub();
	
	vector<Agent*> agentVec;
	
	configLoader->LoadConfig(agentVec, hub);
	
	delete configLoader;
	return 0;
}
