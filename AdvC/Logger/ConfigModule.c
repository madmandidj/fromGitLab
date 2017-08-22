#include <string.h>
#include "ConfigModule.h"



void GetConfig(char* _configFile, Configger* _configger)
{
	FILE* fdConf;
	char line[128];
	char tokName[64];
	char tokVal[64];
	char hashSymbol;
	// LogLevel levels[9] ={LOG_TRACE, LOG_DEBUG, LOG_INFO, LOG_WARNING, LOG_ERROR, LOG_CRITICAL, LOG_SEVERE, LOG_FATAL, LOG_NONE};
	size_t index;

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
			if (!strcmp(tokVal, "LOG_TRACE"))
			{
				_configger->m_level = 0;
			}
			// if (tokVal == LOG_TRACE)
			// {
			// 	_configger->m_level = 'T';
			// }
			
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
