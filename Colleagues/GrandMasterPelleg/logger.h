#ifndef __LOGGER_H__
#define __LOGGER_H__

#include "../LOGGER/LoggerConfig/LoggerConfig.h"

#include <sys/types.h>
#include <stdio.h>
/**********************************/
#define MAX_MODULE_NAME		(32)

typedef struct Log Log;

typedef enum LoggerLevel
{
	LOG_TRACE,
	LOG_DEBUG,
	LOG_INFO,
	LOG_WARNING,
	LOG_ERROR,
	LOG_CRITICAL,
	LOG_SEVERE,
	LOG_FATAL,
	LOG_NONE
} LoggerLevel;

typedef enum LoggerResult
{
	LOGGER_SUCCESS,
	LOGGER_UNINITIALIZED,
	LOGGER_INV_ARG,
	LOGGER_MSG_LEVEL_EXCLUDED
} LoggerResult;

/**********************************/


/**
 * @brief retrieve a pointer to a log to start writing in it
 * @note writing will continue from the end a previously created log or create a new one 
 * @param[in] _moduleName -> name of logging module
 * @param[in] _configFileName name of logger configuration file:
 * configuration file should include the following section:
	[#]
	Level​ ​ = ​ ​ #log_level
	Path​ ​ = ​ ​ #log_base_directory
	File​ ​ = ​ ​ #log_file_name
 * #log_level should be one of the above-listed Logger-Level (defined in enum above). this refers to the minimum level of log messages that will be written to the log 
 * @warning if _configFileName is not the name of a validly-written configuration file or one of the configuration parameters in the file is not provided, the following default configurations will apply:
 *  log file name: "log"
 *	lo file path: ":/"
 * 	log level: LOG_TRACE
 * @warning log retrieval may fail, in which case function returns NULL
 */
Log* GetLog(char* _configFileName, char* _moduleName);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#pragma GCC diagnostic ignored "-Wvariadic-macros"
/**
 * @brief write a message to the log
 * @param[in] LOG-> the log to which the message will be written
 * @param[in] LOG_LEVEL-> level of current log message, see enum Logger_Level
 * @param[in] ... -> formatted message string + format variables as needed, see for example printf function: https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm
 * @retval LOGGER_SUCCESS on success
 * @retval LOGGER_UNINITIALIZED if _log is invalid
 * @retval LOGGER_INV_ARG if one of the arguments is invalid
 * @retval LOGGER_MSG_LEVEL_EXCLUDED if the logged message level is lower than the logger's required minimum level
 * @note this macro calls the function LogWrite. user is advised to use this macro rather than LogWrite function
 */
 #define LOG_WRITE(LOG, MSG_LEVEL, ...) \
 LogWrite((LOG), (MSG_LEVEL), __FILE__, __FUNCTION__, __LINE__, __VA_ARGS__)
 
 #pragma GCC diagnostic pop

 
/********************************************/
/**********AUXILLIARY FUNCTIONS**************/
LoggerResult LogWrite(Log* _log, LoggerLevel _msgLevel, const char* _file, const char* _function, const int _line, const char* _message, ...);

/********************************************/
/**********UNIT TEST FUNCTIONS**************/
/*THIS FUNCTION SHOULD NOT BE USED OTHER THAN FOR TESTING*/
/********************************************/
void	LogClose();
/**********************************/
#endif /*#ifndef __LOGGER_H__*/
