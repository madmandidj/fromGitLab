#include "DataGenerator.h"
#include <stdlib.h>
#include <time.h>


#define IMSI_LENGTH 16
#define MSISDN_LENGTH 16






static void InitGenerate()
{
	static unsigned int initOccured = 0;
	
	if (0 == initOccured)
	{
		srand(time(NULL));
		++initOccured;	
	}
	
	return;
}




void GenerateRecord(Record* _recordPtr)
{

	return;
}

void GenerateSubscriber(Subscriber* _subPtr)
{
	Subscriber sub;
	size_t index;
	char charset[11] = "0123456789";
	
	InitGenerate();
	
	_subPtr->m_outVoiceWithinOp = rand() % 10 + 1;
	_subPtr->m_inVoiceWithinOp = rand() % 10 + 1;
	_subPtr->m_outVoiceOutsideOp = rand() % 10 + 1;
	_subPtr->m_inVoiceOutsideOp = rand() % 10 + 1;
	_subPtr->m_outSmsWithinOp = rand() % 10 + 1;
	_subPtr->m_inSmsWithinOp = rand() % 10 + 1;
	_subPtr->m_outSmsOutsideOp = rand() % 10 + 1;
	_subPtr->m_inSmsOutsideOp = rand() % 10 + 1;
	_subPtr->m_downloadMB = rand() % 10 + 1;
	_subPtr->m_uploadMB = rand() % 10 + 1;
	
	for (index = 0; index < 15; ++index)
	{
		size_t key = rand() % (sizeof(charset) - 1);
		_subPtr->m_imsi[index] = charset[key];
	}
	_subPtr->m_imsi[IMSI_LENGTH] = '\0';
	
	for (index = 0; index < 15; ++index)
	{
		size_t key = rand() % (sizeof(charset) - 1);
		_subPtr->m_msisdn[index] = charset[key];
	}
	_subPtr->m_msisdn[MSISDN_LENGTH] = '\0';
	
	return;
}

void GenerateOperator(Operator* _opPtr)
{
	
	return;
}















