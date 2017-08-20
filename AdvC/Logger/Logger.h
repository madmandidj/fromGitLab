#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <stdio.h>

#define WRITELOG(_log, _level, _module, _message) LogWrite(_log, __FILE__, __FUNCTION__, __LINE__, _level, _module, _message)

typedef FILE Log;

Log* GetLog();

void LogWrite(Log* _log, char* _fileName, const char* _funcName, int _lineNum, char _level, char* _moduleName, char* _message);



#endif /* #ifndef __LOGGER_H__ */
