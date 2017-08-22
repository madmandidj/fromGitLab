#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include "Logger.h"
#include "ConfigModule.h"
#define NANO_TO_MILLI(N) ((N)/ 1000000)

Log* g_log;




struct Log
{
	FILE* m_log;
	char m_level;
	int m_pid;
};

/*
TODO: Static Function Description
TODO: add declaration to top of file so can move this underenath
*/
static void LogClose()
{
	LogDestroy(&g_log);
	return;
}

static Log* LogCreate(char* _configName)
{
	Configger configger;
	if (!(g_log = calloc(1, sizeof(Log))))
	{
		return NULL;
	}
	GetConfig(_configName, &configger);
	g_log->m_log = fopen(configger.m_logName, "a");
	switch (configger.m_level)
	{
		case 0:
			g_log->m_level = 'T';
			break;
		default:
			break;
	}
	// g_log->m_level = configger.m_level;
	g_log->m_pid = getpid();
	atexit(LogClose);
	return g_log;
}




void LogDestroy(Log** _log)
{
	if (NULL == _log)
	{
		return;
	}
	
	fclose(*_log->m_log);
	free(*_log)
	*_log = NULL;
	return;
}









Log* GetLog(char* _configName)
{
	if (NULL == g_log)
	{
		g_log = LogCreate();
	}
	return g_log;
}




/*
TODO: Static Function Description
*/
static void GetTime (char* _timeStr)
{
	time_t milli;
	struct timespec curTime;
	struct tm* info;
	
	clock_gettime(CLOCK_REALTIME, &curTime);
	milli = NANO_TO_MILLI(curTime.tv_nsec);
	
	info = localtime(&curTime.tv_sec);
	sprintf(_timeStr, "%d-%d-%d %d:%d:%d.%03d", 1900 + info->tm_year, info->tm_mon, info->tm_mday, info->tm_hour, info->tm_min,\
	info->tm_sec,  (int)milli);	
}





void LogWrite(Log* _log, char* _fileName, const char* _funcName, int _lineNum, char _level, char* _moduleName, char* _message)
{
	char timeStr[128];
	pid_t pid;
	pthread_t tid;
	
	pid = getpid();
	tid = pthread_self();
	
	if (NULL == _log)
	{
		return;
	}
	
	GetTime(timeStr);
	fprintf(_log, "%s %d %lu %c %s %s@%s:%d %s\n", timeStr, pid, tid, _level, _moduleName, _funcName, _fileName, _lineNum, _message);
	return;
}








