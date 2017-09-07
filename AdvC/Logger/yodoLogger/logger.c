#include "logger.h"
#include "config.h"



#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <pthread.h>/*thread id*/
#include <sys/types.h>
#include <unistd.h>
#include <sys/syscall.h>





struct Log
{
    FILE* m_logFile;/*pointer to the log file*/
    logLevels m_level;/*level of wornnig for the log*/
    int m_pid;/*proces id*/
    ConfigData m_config;/*modoule name fo the log entre: loger,comfig...*/
};


struct tm * timeinfo;    

static Log* g_log;



static Log* Init(Log* log);
static void LogCreate(const char* _fileName,Log* _log);
static void LogDestroy(Log* log);
static void LogClose();
static int Verbusity(char* _level);

/*****************************************************/
Log* GetLog(char* _configName)/*the func need to get the config file name*/
{
    char fileName[64];
    g_log = malloc(sizeof(Log));
    if (NULL == g_log)
    {
        printf("unable to create log file\n");
        return NULL;
    }
    
    Init(g_log);
    g_log->m_config = GetConfig(_configName,g_log->m_config);
    g_log-> m_level = Verbusity(g_log->m_config.m_stringLevel);   
    LogCreate(g_log->m_config.m_LogName,g_log);

    return g_log;
}

/*****************************************************/
static void LogCreate(const char* _fileName,Log* g_log)
{
    int flag;      
    g_log->m_logFile = fopen(_fileName,"a+");
 
    flag = atexit(LogClose);
    
    if(flag != 0)
    {
        printf("failed to close log");
    }
    
}

/*****************************************************/
/*update signeter add struct pointer and remove file name and moudole*/
void LogWrite(Log* g_log,logLevels level, const char* _funcName, int _line,const char* _fileName,char* _messege)
{   
    time_t rawtime;
    struct tm * timeinfo;  
     
    pthread_t x;
    char buffer[80];
    if(level<g_log->m_level)
    {
        return;
    }
    time (&rawtime); 
    timeinfo = localtime (&rawtime);
    strftime (buffer,80,"%F  %T ",timeinfo);
    x = pthread_self(); 
      
   /* fprintf(_g_log, "%s %d %lu %s %s@%s:%d %s\n",buffer,_log->m_pid,x,_log->m_module,_funcName,_fileName,_line,_messege);*/
   
     MYFPRINTF("%s %d %lu %s %s@%s:%d %s\n",buffer,g_log->m_pid,x,g_log->m_config.m_module,_funcName,_fileName,_line,_messege);


}
/**************************************************/
static Log* Init(Log* g_log)
{
    
    g_log -> m_pid = getpid();
    strcpy(g_log -> m_config.m_LogName, "log"__TIME__);
    strcpy(g_log -> m_config.m_stringLevel, "LOG_TRACE");
    strcpy(g_log -> m_config.m_module,"Log");
    g_log -> m_level = 0;
    return g_log;
}
/**************************************************/
static int Verbusity(char* _level)
{
    char arr[8]={'T','D','I','W','E','C','S','F'};
    int i=0;
    
    for(i=0; i<8; i++)
    {
         if(_level[4] == arr[i])
         {
            return i;
         }
    } 
    return i;  
}


/*****************************************************/
static void LogDestroy(Log* g_log)
{
   
   fclose(g_log->m_logFile);
   free(g_log);
    g_log = NULL;
}
/*****************************************************/
                
static void LogClose()
{

    LogDestroy(g_log);

}

