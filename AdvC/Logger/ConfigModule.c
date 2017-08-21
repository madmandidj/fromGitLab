#include <string.h>
#include "ConfigModule.h"



void GetConfig(char* _configFile, Configger* _configger)
{
	FILE* fdConf;
	char line[128];
	char tokName[64];
	char tokVal[64];
	char hashSymbol;
	
	fdConf = fopen(_configFile, "r");
	
	
	
	while (!feof(fdConf) || '#' != hashSymbol)
	{
		fgets(line, 128, fdConf);
		sscanf(line, "[%[^ ]\n]", &hashSymbol);
	}
	
	if (!('#' == hashSymbol))
	{
		return;
	}
	
	while(!feof(fdConf))
	{
		fgets(line, 128, fdConf);
		sscanf(line, "[%[^ =] = %[^\n]", tokName, tokVal);
		if (!strcmp(tokName, "Level"))
		{
			strcpy(_configger->m_level, tokVal);
		}
		else if (!strcmp(tokName, "File"))
		{
			strcpy(_configger->m_logName, tokVal);
		}
		/*
		switch(tokName)
		{
			case "Level":
				strcpy(*_configger->m_level, tokVal);
				break;
			case "File":
				strcpy(*_configger->m_logName, tokVal);
				break;
			default:
				break;
		}
		*/
	}
	
	
	
	fclose(fdConf);
	return;
}
