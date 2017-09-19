#include "../inc/logger.h"
#include "../inc/mu_test.h"
#include <stdio.h>

UNIT(logMessagesOverLogLevel)
	int i;
	LoggerResult retVal; 
	Log* testLog;
	
	testLog = GetLog("./configFiles/testLogConfig", "TestModule");
	
	for (i = 0; i < 10; i += 1)
	{
		retVal = LOG_WRITE(testLog, LOG_CRITICAL, "MESSAGE OVER LOG LEVEL");
		ASSERT_THAT(retVal == LOGGER_SUCCESS);
	}
	LogClose();
END_UNIT

UNIT(logMessagesAtLogLevel)
	int i;
	LoggerResult retVal; 
	Log* testLog;
	
	testLog = GetLog("./configFiles/testLogConfig", "TestModule");
	
	for (i = 0; i < 10; i += 1)
	{
		retVal = LOG_WRITE(testLog, LOG_WARNING, "MESSAGE AT MINIMUM LOG LEVEL");
		ASSERT_THAT(retVal == LOGGER_SUCCESS);
	}
	LogClose();
END_UNIT

UNIT(logMessagesUnderLogLevel)
	int i;
	LoggerResult retVal; 
	Log* testLog;
	
	testLog = GetLog("./configFiles/testLogConfig", "TestModule");
	
	for (i = 0; i < 10; i += 1)
	{
		retVal = LOG_WRITE(testLog, LOG_TRACE, "MESSAGE UNDER LOG LEVEL - SHOULD NOT APPEAR!!!!");
		ASSERT_THAT(retVal == LOGGER_MSG_LEVEL_EXCLUDED);
	}
	LogClose();
END_UNIT

UNIT(defaultLogName)
	int i;
	LoggerResult retVal; 
	Log* testLog;
	
	testLog = GetLog("./configFiles/configNoFileName", "TestModule");
	
	for (i = 0; i < 10; i += 1)
	{
		retVal = LOG_WRITE(testLog, LOG_WARNING, "default log name %d", i);
		ASSERT_THAT(retVal == LOGGER_SUCCESS);
	}
	LogClose();
END_UNIT

UNIT(defaultLogPath)
	int i;
	LoggerResult retVal; 
	Log* testLog;
	
	testLog = GetLog("./configFiles/configNoPath", "TestModule");
	
	for (i = 0; i < 10; i += 1)
	{
		retVal = LOG_WRITE(testLog, LOG_WARNING, "default path %d", i);
		ASSERT_THAT(retVal == LOGGER_SUCCESS);
	}
	LogClose();
END_UNIT

UNIT(defaultLogLevel)
	int i;
	LoggerResult retVal; 
	Log* testLog;
	
	testLog = GetLog("./configFiles/configNoLevel", "TestModule");
	
	for (i = 0; i < 10; i += 1)
	{
		retVal = LOG_WRITE(testLog, LOG_INFO, "default level %d", i);
		ASSERT_THAT(retVal == LOGGER_SUCCESS);
	}
	LogClose();
END_UNIT
/*****************************/

TEST_SUITE(loggerTest)
	TEST(logMessagesOverLogLevel)
	TEST(logMessagesAtLogLevel)
	TEST(logMessagesUnderLogLevel)	
	
	TEST(defaultLogName)
	
	TEST(defaultLogPath)
	
	TEST(defaultLogLevel)
	
END_SUITE

