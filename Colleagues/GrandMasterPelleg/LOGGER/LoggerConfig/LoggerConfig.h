#ifndef __LOG_CONFIG_H__
#define __LOG_CONFIG_H__

#include "../../inc/logger.h"


#define MAX_LOG_NAME	(32)
#define MAX_LOG_PATH	(64)
#define MAX_LOGER_LEVEL (16)

typedef struct 
{
	char 			m_logName[MAX_LOG_NAME];
	char 			m_logPath[MAX_LOG_PATH];
	char			m_loggerLevel[MAX_LOGER_LEVEL];
}ConfigParams;

/**
 * @brief read logger configuration parameters from given file
 * configuration file should include the following section:
	[#]
	Level​ ​ = ​ ​ #default_log_level
	Path​ ​ = ​ ​ #log_base_directory
	File​ ​ = ​ ​ #default_log_file_name
 * #log_level should be one of the above-listed Logger-Level (defined in enum above). this refers to the minimum level of log messages that will be written to the log 
 * @param[in] _configFileName name of configuration file to be read
 * @retval ConfigParams, which include: 
 * log name, log path and logging level (see enum defined in logger.h)
 * @warning if _configFileName is not the name of a validly-written configuration file or one of the configuration parameters in the file is not provided, the following default configurations will apply:
 *  log file name: "log"
 *	lo file path: ":/"
 * 	log level: LOG_TRACE
 */
void ReadConfiguration(char* _configFileName, ConfigParams* _configParams);

#endif /*#ifndef __LOG_CONFIG_H__*/
