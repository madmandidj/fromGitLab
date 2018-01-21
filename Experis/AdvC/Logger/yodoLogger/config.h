#ifndef __CONFIG_H__
#define __CONFIG_H__






typedef struct ConfigData ConfigData;

struct ConfigData {
    char m_LogName[64];
    char m_stringLevel[64];
    char m_module[64];
    
};

/**  
 * @brief open the config file and retreve the loger file name, level of verbosity.
 * @param[in] _fdConfigName - config file name.
 * @param[in] _configValue - struct of three string.
 * @return the struct, 
 */
 ConfigData GetConfig(char* _fdConfigName,ConfigData _configValue);



#endif /*end of if __CONFIG_H__*/    
