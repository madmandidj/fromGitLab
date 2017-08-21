#ifndef __CONFIGMODULE_H__
#define __CONFIGMODULE_H__

#include <stdio.h>

typedef struct Configger
{
	char m_level[128];
	char m_logName[128];
}Configger;

void GetConfig(char* _configFile, Configger* _configger);




#endif /* #ifndef __CONFIGMODULE_H__ */
