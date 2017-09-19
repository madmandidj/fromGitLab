#include "LoggerConfig.h"
#include <stdio.h>
#include <string.h>

#define MAX_LINE 1024

static void ReadParameters (ConfigParams* _readParams, FILE* _configFile);

void ReadConfiguration(char* _configFileName, ConfigParams* _configParams)
{
	FILE* configFile;
	char readItem[32];
	char readLine[MAX_LINE];  
	int retVal;
	
	/*initialize parameters to values symbolizing read failure*/
	_configParams->m_logName[0] = '\0';
	_configParams->m_logPath[0] = '\0';
	_configParams->m_loggerLevel[0] = '\0'; 

	configFile = fopen (_configFileName, "r");
	if (!configFile)
	{
		return;
	}
	
	while(fgets(readLine, MAX_LINE, configFile))
	{
		retVal = sscanf(readLine, " [%s] ", readItem);
		if (retVal == 1 && readItem[0] == '#')
		{
			ReadParameters(_configParams, configFile);
			fclose(configFile);
			return;
		}
	}
	fclose(configFile);
}

static void ReadParameters (ConfigParams* _readParams, FILE* _configFile)
{
	int retVal; 
	char readLine[MAX_LINE]; 
	char readParamName[64];
	char readItem[64];
	char didGetLevel = 0, didGetPath = 0, didGetFile = 0;
	
	while (fgets(readLine, MAX_LINE, _configFile))
	{
		retVal = sscanf(readLine, " %s = %s", readParamName, readItem);
		if (retVal == 2)
		{
			if (strcmp(readParamName, "Level") == 0 && !didGetLevel)
			{
				strcpy(_readParams->m_loggerLevel, readItem);
				didGetLevel = 1;
			}
			if (strcmp(readParamName, "Path") == 0 && !didGetPath)
			{
				strcpy(_readParams->m_logPath, readItem);
				didGetPath = 1;
			}
			if (strcmp(readParamName, "File") == 0 && !didGetFile)
			{
				strcpy(_readParams->m_logName, readItem);
				didGetFile = 1;
			}
		}
		if (didGetFile && didGetPath && didGetLevel)
		{
			return;
		}
	}
}



