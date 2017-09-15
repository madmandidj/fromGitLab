#include "DataGenerator.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>


#define IMSI_STR_LENGTH 15
#define MSISDN_STR_LENGTH 15


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



static void GetRandomIntString(char* _strPtr, size_t _strLength)
{
	char numCharset[11] = "0123456789";
	size_t index;
	
	for (index = 0; index < _strLength; ++index)
	{
		size_t key = rand() % (sizeof(numCharset) - 1);
		_strPtr[index] = numCharset[key];
	}
	_strPtr[_strLength] = '\0';
	
	return;
}



static void GetRandomFloatString(char* _strPtr)
{
    char numCharset[11] = "0123456789";
    size_t wholeNumOfDigits;
    size_t fractionNumOfDigits;
	size_t wholeIndex;
	size_t fractionIndex;
	
	wholeNumOfDigits = rand() % 6;
	fractionNumOfDigits = 2;
	
	for (wholeIndex = 0; wholeIndex < wholeNumOfDigits; ++wholeIndex)
	{
		size_t key = rand() % (sizeof(numCharset) - 1);
		_strPtr[wholeIndex] = numCharset[key];
	}
	
	_strPtr[wholeIndex] = '.';
	fractionIndex = wholeIndex + 1;
	
	for (fractionIndex = 0; fractionIndex < fractionNumOfDigits; ++fractionIndex)
	{
		size_t key = rand() % (sizeof(numCharset) - 1);
		_strPtr[fractionIndex] = numCharset[key];
	}
	
	_strPtr[fractionIndex] = '\0';
	
	return;
}



static void GetRandomFloat(float* _floatPtr)
{
    float maxRandRange = 1000.0;
    
	*_floatPtr = (((float)rand()/(float)(RAND_MAX)) * maxRandRange);
        
    return;
}



static void GetRandomCharString(char* _strPtr, size_t _strLength)
{
	char letterCharset[53] = "abcdefghijklmnopqestuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	size_t index;
	
	for (index = 0; index < _strLength; ++index)
	{
		size_t key = rand() % (sizeof(letterCharset) - 1);
		_strPtr[index] = letterCharset[key];
	}
	_strPtr[_strLength] = '\0';
	
	return;
}


void GenerateSingleCDR()
{


}





void GenerateRecord(Record* _recordPtr)
{
	size_t index;

	InitGenerate();
	
	GetRandomIntString(_recordPtr->m_imsi, IMSI_STR_LENGTH);
	
	GetRandomIntString(_recordPtr->m_msisdn, MSISDN_STR_LENGTH);
	
	GetRandomIntString(_recordPtr->m_imei, 15);

	GetRandomCharString(_recordPtr->m_operatorBrand, 10);
	
	GetRandomIntString(_recordPtr->m_operatorMCCMNC, 6);
	
	_recordPtr->m_callType =  rand() % 5;
	
	strcpy(_recordPtr->m_callDate, "17/01/1984");

	strcpy(_recordPtr->m_callTime, "23:59:59");
	
	_recordPtr->m_duration = rand() % 10000;
	
	GetRandomFloat(&_recordPtr->m_downloadMB);
	
	GetRandomFloat(&_recordPtr->m_uploadMB);
	
	GetRandomIntString(_recordPtr->m_partyMsisdn, IMSI_STR_LENGTH);
	
	GetRandomIntString(_recordPtr->m_partyMCCMNC, 6);

	return;
}



void GenerateSubscriber(Subscriber* _subPtr)
{
	size_t index;
	
	InitGenerate();
	
	_subPtr->m_outVoiceWithinOp = rand() % 10 + 1;
	
	_subPtr->m_inVoiceWithinOp = rand() % 10 + 1;
	
	_subPtr->m_outVoiceOutsideOp = rand() % 10 + 1;
	
	_subPtr->m_inVoiceOutsideOp = rand() % 10 + 1;
	
	_subPtr->m_outSmsWithinOp = rand() % 10 + 1;
	
	_subPtr->m_inSmsWithinOp = rand() % 10 + 1;
	
	_subPtr->m_outSmsOutsideOp = rand() % 10 + 1;
	
	_subPtr->m_inSmsOutsideOp = rand() % 10 + 1;
	
	GetRandomFloat(&_subPtr->m_downloadMB);
	
	GetRandomFloat(&_subPtr->m_uploadMB);
	
	GetRandomIntString(_subPtr->m_imsi, IMSI_STR_LENGTH);
	
	GetRandomIntString(_subPtr->m_msisdn, MSISDN_STR_LENGTH);
	
	return;
}



void GenerateOperator(Operator* _opPtr)
{
	
	return;
}















