#include "ConfigModule.h"



Configger* ReadConfig(char* _configFile)
{
	FILE* fdConf;
	fdConf = fopen(_configFile, "r");
	while(1)
    {
	   c = fgetc(fp);
	   if( feof(fp) )
	   { 
	      break ;
	   }
	   printf("%c", c);
    }
    fclose(fp);
/*
	Open config file
	while not end of file
		while not found #
	parse remaining lines
	return extracted values or return defaults
*/
}


/*
%[^ =] = %[^ /n]"
*/
