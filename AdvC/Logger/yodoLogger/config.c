#include "config.h"

# include <stdio.h>
# include <stdlib.h>
#include <string.h>




ConfigData parsing(FILE* _fdConfig,ConfigData _m_config)
{
    char a[64];
    char filename[64];
    char buffer[64];
    int flag=0;
    
    
    while(!feof(_fdConfig))
    {
        fgets (buffer ,64, _fdConfig);
        sscanf(buffer," [ \n%[^] \n ]",a);
        if(strcmp(a,"#")== 0)
        {
            fgets (buffer ,64, _fdConfig);
            sscanf(buffer,"  %[^ =] = %[^ ]",a,filename);/*add more while*/
            while(!feof(_fdConfig))
            {

                
                if(strcmp(a,"File")==0)
                {
                   strcpy(_m_config.m_LogName,filename);
                   flag++;
                }
                if(strcmp(a,"Level")==0)
                {
                  strcpy(_m_config.m_stringLevel,filename);
                  flag++;
                }
                if(flag==2)
                {
                    return _m_config;
                } 
                fgets (buffer ,64, _fdConfig);
                sscanf(buffer,"[%[^ =] = %[^ \n]",a,filename);/*add more while*/  
            }
            
       }      
       
    } 
    return _m_config;  
}


ConfigData GetConfig(char* _fdConfigName,ConfigData _m_config)
{
    FILE* fdConfig;
    char fileName[128];
    fdConfig = fopen(_fdConfigName,"r");
    
    if (fdConfig == NULL)
    {
        printf("unable to open file\n");
        return _m_config; 
        
    }
    
    _m_config = parsing(fdConfig,_m_config);
    if(NULL == fileName)
    {
       fclose(fdConfig);
       return _m_config;     
    }
    
    fclose(fdConfig);
    
    return _m_config;
}








