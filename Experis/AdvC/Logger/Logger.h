#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <stdio.h>

#define WRITELOG(_log, _level, _module, _message) LogWrite(_log, __FILE__, __FUNCTION__, __LINE__, _level, _module, _message)

typedef struct Log Log;

typedef enum{
    LOG_TRACE = 0,
    LOG_DEBUG,
	LOG_INFO,
	LOG_WARNING,
	LOG_ERROR,
	LOG_CRITICAL,
	LOG_SEVERE,
	LOG_FATAL,
	LOG_NONE
}LogLevel;

Log* GetLog();

void LogWrite(Log* _log, char* _fileName, const char* _funcName, int _lineNum, char _level, char* _moduleName, char* _message);



#endif /* #ifndef __LOGGER_H__ */
