#include <stdio.h>
#include "Logger.h"


int main()
{
	Log* log;
	log = GetLog();
	WRITELOG(log, 'I', "LogMod", "TestMsg");
	return 0;
}
