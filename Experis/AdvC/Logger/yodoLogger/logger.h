#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <stdio.h>
#include "config.h"

#pragma​ ​ GCC​ ​ diagnostic​ ​ push
#pragma​ ​ GCC​ ​ diagnostic​ ​ ignored​ ​ "-Wvariadic-macros"

#define MYFPRINTF(...) fprintf (g_log -> m_logFile, __VA_ARGS__)

#pragma​ ​ GCC​ ​ diagnostic​ ​ pop


typedef struct Log Log;


typedef enum
{
    LOG_TRACE=0,
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR,
    LOG_CRITICAL,
    LOG_SEVERE,
    LOG_FATAL,
    LOG_NONE
} logLevels;




#define LOGWRITE(LOG,LEVEL,MESSAGE)  LogWrite(LOG,LEVEL, __func__,__LINE__, __FILE__,MESSAGE)
 
 
 
 
/**  
 * @brief get the Log pointer.
 * @param[in] configName - config file name.
 * @return struct pointer/ 
 */ 
Log* GetLog(char* _configName);


/**  
 * @brief write to the log.
 * @param[in] g_log - pointer to struct.
 * @param[in] level - lever of verbusoty.
 * @param[in] _funcName - the name of the function that the log ther.
 * @param[in] line - the line number in the file.
 * @param[in] fileName - the name of the source file.
 */
void LogWrite(Log* g_log,logLevels level, const char* _funcName, int _line,const char* _fileName,char* _messege);


#endif /*end of__LOGGER_H__*/
