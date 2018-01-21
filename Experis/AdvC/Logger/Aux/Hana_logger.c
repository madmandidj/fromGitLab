#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

#include "Logger.h"


#define NANO_TO_MILLI(N) ((N)/ 1000000)

static void FileLogCreate();
static void FileLogClose();
static void getTime (char* _timeStr);

/*static? */
Log g_log = NULL; 



Log LogGet()
{
	if (NULL == g_log)
	{
		FileLogCreate();
	}
	atexit(FileLogClose);
	
	return g_log;
}

void LogWrite(Log _log, const char* _funcName ,const char* _fileName, int _lineNum, char* _module, char* _message)
{
	char timeStr[32];
	pid_t processID = 0;
	pthread_t threadID = 0;
	
	getTime(timeStr);
	processID = getpid();
	threadID = pthread_self();
	#ifndef NDEBUG
	fprintf(_log, "%s  %d %d %s %s\n", timeStr, (int)processID, (int)threadID, _module, _message);
	return;
	#endif
	
	fprintf(_log, "%s  %d %d %s %s@%s:%d %s\n", timeStr, (int)processID, (int)threadID, _module, _funcName, _fileName, _lineNum, _message);
}



static void FileLogCreate()
{
	/*the caller of the function (at this point of the project) does not need to read data from log, therefore a and not a+ */
	/*The name of the file should be informative, but for that the function needs to get parameters? */
	g_log = fopen("mudule_name.txt", "a");
	/*check fopen failure? */
}

static void FileLogClose()
{
	char timeStr[32];
	getTime(timeStr);
	fprintf(g_log, "File closed on: %s\n", timeStr);
	flose(g_log);
	/*check flocse failure? */
}



static void getTime (char* _timeStr)
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












 
