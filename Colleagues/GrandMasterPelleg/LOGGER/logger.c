/**
 * TODO atexit has retval -> check and fix accordingly
 * TODO more tests
 */
#include "logger.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>
#include <assert.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>
/**********************************/
/*definitions*/
#define MSG_MAX_LENGTH 			1024
#define DEFAULT_LOGGER_NAME		"log.log"
#define DEFAULT_LOGGER_LEVEL	LOG_TRACE
#define DEFAULT_LOGGER_PATH		"./logs/"
struct Log
{
	FILE* 			m_logFile;
	char	 		m_moduleName[MAX_MODULE_NAME]; 
	pid_t 			m_processId; 
	LoggerLevel 	m_logLevel;
};

static char logLevelHashSet[9]={'T', 'D', 'I', 'W', 'E', 'C', 'S', 'F', 'N'};
/**********************************/
/*MACROS*/
#define DOES_HAVE_FD(LOG)	((LOG).m_logFile != NULL)

#define LOG_FORMAT			"%s %d %lu %c %s %s@%s:%d %s\n"
/**********************************/
/*global logger variable*/
static Log g_log={0};
/**********************************/
/*AUXILLIARY FUNCTION DECLARATIONS*/
static void	LogCreate();
static void	LogDestroy(Log* _log);
static void CheckConfigParams(ConfigParams* _configParameters);
static LoggerLevel StringToLogLevel(char* _logLevel);
static void GetTimeAndDate(char* _timeAndDate);
static char LogLevelChar(LoggerLevel _lvl);
/**********************************/
/*API FUNCTIONS*/
/**********************************/
Log* GetLog(char* _configFileName, char* _moduleName)
{
	if (!DOES_HAVE_FD(g_log))
	{
		LogCreate(_configFileName, _moduleName);
	}

	return &g_log;
}
/**********************************/
LoggerResult LogWrite(Log* _log, LoggerLevel _msgLevel, const char* _file, const char* _function, const int _line, const char* _message, ...)
{
	char timeAndDate[64];
	char formattedMessage[MSG_MAX_LENGTH]; 
	va_list argptr;
	
	/*argument checking*/
	if (!_log || !DOES_HAVE_FD(*_log))
	{
		return LOGGER_UNINITIALIZED;
	}
	
	if (!_message || _msgLevel<LOG_TRACE || _msgLevel > LOG_NONE)
	{
		return LOGGER_INV_ARG;
	}
	
	if (_msgLevel < _log->m_logLevel)
	{	
		return LOGGER_MSG_LEVEL_EXCLUDED;
	}
	
	/*calculate needed parameters*/	
	GetTimeAndDate(timeAndDate);
	
	va_start(argptr, _message);
	vsnprintf(formattedMessage, MSG_MAX_LENGTH, _message, argptr);
	va_end(argptr);
	
	/*write to log*/
	fprintf(_log->m_logFile, LOG_FORMAT, timeAndDate, _log->m_processId, syscall(SYS_gettid), logLevelHashSet[_log->m_logLevel],_log->m_moduleName, _function, _file, _line, formattedMessage);
	
	fflush(_log->m_logFile);
	
	return LOGGER_SUCCESS;
}
/**********AUXILLIARY FUNCTIONS**********/
/*configures global log variable. returns 0 if failed to open file, 1 if success*/
static void	LogCreate(char* _configFileName, char* _moduleName)
{
	LoggerLevel logLvl;
	ConfigParams configParameters;
	char filePathAndName[MAX_LOG_PATH+MAX_LOG_NAME];
	
	ReadConfiguration(_configFileName, &(configParameters));
	
	/*check for read errors, in which case assign defaults*/
	CheckConfigParams(&configParameters);
	
	logLvl = StringToLogLevel(configParameters.m_loggerLevel);
	if (logLvl == -1)
	{/*error reading log level, use default*/
		logLvl = DEFAULT_LOGGER_LEVEL;
	}

	
	/*configure logger parameters*/
	g_log.m_logLevel = logLvl;
	
	strcpy(filePathAndName, configParameters.m_logPath);
	strcat(filePathAndName, configParameters.m_logName);
	
	g_log.m_logFile = fopen(filePathAndName, "w");
	
	if (!g_log.m_logFile)
	{
		return;
	}
	
	strcpy (g_log.m_moduleName, _moduleName);
	g_log.m_processId = getpid();
	
	atexit(LogClose); 
}
/**********************************/
void	LogClose()
{
	if (DOES_HAVE_FD(g_log))
	{
		LogDestroy(&g_log);
	}
}
/**********************************/
static void	LogDestroy(Log* _log)
{	
	fclose(_log->m_logFile);
	_log->m_logFile = NULL;
}
/**********************************/
/**
 * @brief check for parameters symbolizing configuration file read error and assign default values as needed
 * @note to avoid rechecking logger level, the retrieved value is already set to the global log structure
*/
static void CheckConfigParams(ConfigParams* _configParameters)
{	
	if (_configParameters->m_logName[0] == '\0')
	{
		strcpy(_configParameters->m_logName, DEFAULT_LOGGER_NAME);
	}
	if (_configParameters->m_logPath[0] == '\0')
	{
		strcpy(_configParameters->m_logPath, DEFAULT_LOGGER_PATH);
	}	
}
/**********************************/
static LoggerLevel StringToLogLevel(char* _logLevel)
{

	int i;
	
	for (i = 0; i < 9; i += 1)
	{
		if (_logLevel[4] == logLevelHashSet[i])
		{
			return (LoggerLevel) i;
		}
	}
	
	return -1;
}
/**********************************/
static void GetTimeAndDate(char* _timeAndDate)
{
	time_t now;
	struct tm* now_tm;
	struct timeval tv; 
	double milliSecs; 
	
	time(&now);
	now_tm = localtime(&now);
	
	gettimeofday(&tv, NULL);
	milliSecs = (tv.tv_usec) / 1000;
	
	strftime (_timeAndDate, 64, "%Y-%m-%d %H:%M:%S", now_tm);
	
	sprintf(_timeAndDate, "%s.%d", _timeAndDate, (int)milliSecs);
}
