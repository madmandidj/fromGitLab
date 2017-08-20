#ifndef __CONFIGMODULE_H__
#define __CONFIGMODULE_H__


typedef struct Configger
{
	int m_level;
	char* m_logName;
}Configger;

Configger* ReadConfig(char* _configFile);




#endif /* #ifndef __CONFIGMODULE_H__ */
