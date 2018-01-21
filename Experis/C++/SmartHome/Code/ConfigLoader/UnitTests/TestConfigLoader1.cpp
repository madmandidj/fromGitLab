#include "ConfigLoader.h"




int main()
{
	ConfigLoader* configLoader = new ConfigLoader("../SO/", "../INI/Config.ini");
	
	configLoader->LoadConfig();
	
	delete configLoader;
	return 0;
}
