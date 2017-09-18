#include "DataGenerator.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdio.h>


#define IMSI_STR_LENGTH 15
#define MSISDN_STR_LENGTH 15
#define IMEI_STR_LENGTH 15
#define OPBRAND_STR_LENGTH 7
#define OPMCCMNC_STR_LENGTH 6
/*#define CALLTYPE_STR_LENGTH */
/*#define CALLDATE_STR_LENGTH 10*/
/*#define CALLTIME_STR_LENGTH 8*/
#define DURATION_STR_LENGTH 7
#define DOWNLOAD_STR_LENGTH 10
#define UPLOAD_STR_LENGTH 10
#define PARTYMSISDN_STR_LENGTH 15
#define PARTYOP_STR_LENGTH 15


#define RECORDS_NUM 1000000
#define RECORDS_NUM_STR "1000000\n"


static void InitGenerate()
{
	static unsigned int initOccured = 0;
	
	if (0 == initOccured)
	{
		srand((unsigned int)time(NULL));
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
		size_t key = (unsigned int)rand() % (sizeof(numCharset) - 1);
		_strPtr[index] = numCharset[key];
	}
	_strPtr[_strLength] = '\0';
	
	return;
}


/*
static void GetRandomFloatString(char* _strPtr)
{
    char numCharset[11] = "0123456789";
    size_t wholeNumOfDigits;
    size_t fractionNumOfDigits;
	size_t wholeIndex;
	size_t fractionIndex;
	
	wholeNumOfDigits = (unsigned int)rand() % 6;
	fractionNumOfDigits = 2;
	
	for (wholeIndex = 0; wholeIndex < wholeNumOfDigits; ++wholeIndex)
	{
		size_t key = (unsigned int)rand() % (sizeof(numCharset) - 1);
		_strPtr[wholeIndex] = numCharset[key];
	}
	
	_strPtr[wholeIndex] = '.';
	fractionIndex = wholeIndex + 1;
	
	for (fractionIndex = 0; fractionIndex < fractionNumOfDigits; ++fractionIndex)
	{
		size_t key = (unsigned int)rand() % (sizeof(numCharset) - 1);
		_strPtr[fractionIndex] = numCharset[key];
	}
	
	_strPtr[fractionIndex] = '\0';
	
	return;
}
*/


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
		size_t key = (unsigned int)rand() % (sizeof(letterCharset) - 1);
		_strPtr[index] = letterCharset[key];
	}
	_strPtr[_strLength] = '\0';
	
	return;
}


void GenerateCDRFile()
{
	FILE* fp;
/*	Record rec;*/
	char str[128];
/*	size_t numOfRecords = 10000000;*/
/*	char numOfRecordsStr[] = "10000000\n";*/
	
	/*
	With 10 processor threads, it takes 24 seconds to read, process and store 1,000,000 records, hashSize of 10,000 for subs and 1,000 for operators
	with 100 processor threads, it takes 20 seconds ... not sure that performance has increased significantly
	
	with 100 processor threads and hashSize of 100,000 for subs and 10,000 for operators, 1,000,000 records in 10 seconds
	*/
	
	
	size_t index;
/*	unsigned int randomInt;*/
	
	fp = fopen("TestCDRFile.cdr", "w+");
	
	if (NULL != fp)
	{
		fputs(RECORDS_NUM_STR, fp);
		
		for(index = 0; index < RECORDS_NUM; ++index)
		{
			GetRandomIntString(str, IMSI_STR_LENGTH);
			strcat(str, "|");
			fputs(str, fp);
		
			GetRandomIntString(str, MSISDN_STR_LENGTH);
			strcat(str, "|");
			fputs(str, fp);
			
			GetRandomIntString(str, IMEI_STR_LENGTH);
			strcat(str, "|");
			fputs(str, fp);
			
			GetRandomIntString(str, OPBRAND_STR_LENGTH);
			strcat(str, "|");
			fputs(str, fp);
			
			GetRandomIntString(str, OPMCCMNC_STR_LENGTH);
			strcat(str, "|");
			fputs(str, fp);
			
			switch (rand() % 5) /* 5 CallType enum members (in Record.h) */
			{
				case 0:
					fputs("MOC|", fp);
					break;
				
				case 1:
					fputs("MTC|", fp);
					break;
				
				case 2:
					fputs("SMS_MO|", fp);
					break;
				
				case 3:
					fputs("SMS_MT|", fp);
					break;
				
				case 4:
					fputs("GPRS|", fp);
					break;
			}
			
			fputs("17/01/1984|", fp);
			fputs("23:59:59|" , fp);
			
			GetRandomIntString(str, DURATION_STR_LENGTH);
			strcat(str, "|");
			fputs(str, fp);
			
			GetRandomIntString(str, DOWNLOAD_STR_LENGTH);
			strcat(str, "|");
			fputs(str, fp);
			
			GetRandomIntString(str, UPLOAD_STR_LENGTH);
			strcat(str, "|");
			fputs(str, fp);
			
			GetRandomIntString(str, PARTYMSISDN_STR_LENGTH);
			strcat(str, "|");
			fputs(str, fp);
			
			GetRandomIntString(str, PARTYOP_STR_LENGTH);
			strcat(str, "\n");
			fputs(str, fp);
		}
		
		
		/*
		put number of CDR files
		for (number of CDR files)
		{
			generate record
			write record to file
		]
		*/
		
		
/*		fputs("test1\n", fp);*/
/*		fputs("test3\n", fp);*/
/*		fputs("test2\n", fp);*/
	}
	
	fclose(fp);
	
	rename("TestCDRFile.cdr", "../Feeder/NewFileWatcher/NEW/TestCDRFile.cdr");
	
	return;
}





void GenerateRecord(Record* _recordPtr)
{
	InitGenerate();
	
	GetRandomIntString(_recordPtr->m_imsi, IMSI_STR_LENGTH);

	
	GetRandomIntString(_recordPtr->m_msisdn, MSISDN_STR_LENGTH);
	
	GetRandomIntString(_recordPtr->m_imei, 15);

	GetRandomCharString(_recordPtr->m_operatorBrand, 10);
	
	GetRandomIntString(_recordPtr->m_operatorMCCMNC, 6);
	
	_recordPtr->m_callType =  (unsigned int)rand() % 5;
	
	strcpy(_recordPtr->m_callDate, "17/01/1984");

	strcpy(_recordPtr->m_callTime, "23:59:59");
	
	_recordPtr->m_duration = (unsigned int)rand() % 10000;
	
	GetRandomFloat(&_recordPtr->m_downloadMB);
	
	GetRandomFloat(&_recordPtr->m_uploadMB);
	
	GetRandomIntString(_recordPtr->m_partyMsisdn, IMSI_STR_LENGTH);
	
	GetRandomIntString(_recordPtr->m_partyMCCMNC, 6);

	return;
}



void GenerateSubscriber(Subscriber* _subPtr)
{
/*	size_t index;*/
	
	InitGenerate();
	
	_subPtr->m_outVoiceWithinOp = (unsigned int)rand() % 10 + 1;
	
	_subPtr->m_inVoiceWithinOp = (unsigned int)rand() % 10 + 1;
	
	_subPtr->m_outVoiceOutsideOp = (unsigned int)rand() % 10 + 1;
	
	_subPtr->m_inVoiceOutsideOp = (unsigned int)rand() % 10 + 1;
	
	_subPtr->m_outSmsWithinOp = (unsigned int)rand() % 10 + 1;
	
	_subPtr->m_inSmsWithinOp = (unsigned int)rand() % 10 + 1;
	
	_subPtr->m_outSmsOutsideOp = (unsigned int)rand() % 10 + 1;
	
	_subPtr->m_inSmsOutsideOp = (unsigned int)rand() % 10 + 1;
	
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















