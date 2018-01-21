#include "logger.h"



   
int main()
{
    Log* log=NULL;
    int i;
    for(i=0; i<5014; i++)
    {   
        if(log == NULL)
        {
            log = GetLog("config");
        }
        
        LOGWRITE(log,3,"until whine");
    } 
return 0;      
}
