#include <stdio.h>
#include "Logger.h"


int main()
{
	Log* log;
	log = GetLog("LConfig.txt");
	WRITELOG(log, 'I', "LogMod", "TestMsg");
	return 0;
}
