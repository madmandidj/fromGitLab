#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include "Logger.h"
#define NANO_TO_MILLI(N) ((N)/ 1000000)


Log* g_log = NULL;




/*
TODO: Static Function Description
*/
static Log* LogCreate()
{
	g_log = fopen("default_log.txt", "a");

	return g_log;
}




void LogDestroy(Log** _log)
{
	if (NULL == _log)
	{
		return;
	}
	
	fclose(*_log);
	*_log = NULL;
	return;
}




/*
TODO: Static Function Description
*/
static void LogClose()
{
	LogDestroy(&g_log);
	return;
}




Log* GetLog()
{
	Log* tempLog;
	if (NULL == g_log)
	{
		tempLog = LogCreate();
	}
	atexit(LogClose);
	return tempLog;
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








