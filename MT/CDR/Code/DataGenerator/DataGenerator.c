#include "DataGenerator.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <getopt.h>

#define IMSI_STR_LENGTH 15
#define MSISDN_STR_LENGTH 15
#define IMEI_STR_LENGTH 15
#define OPBRAND_STR_LENGTH 7
#define OPMCCMNC_STR_LENGTH 6
#define DURATION_STR_LENGTH 7
#define DOWNLOAD_STR_LENGTH 10
#define UPLOAD_STR_LENGTH 10
#define PARTYMSISDN_STR_LENGTH 15
#define PARTYOP_STR_LENGTH 15



void DoGetOpt(int _argc, char* _argv[], DataGenParams* _params)
{
	int opt;
	
	while ((opt = getopt(_argc, _argv, "n:s:o:")) != -1) {
	   switch (opt) 
	   {
		case 'n':
			_params->m_numOfRecords = atoi(optarg);
		   break;
		
		case 's':
			_params->m_subMsisdnLength = (size_t)atoi(optarg);
		   break;
		   
		case 'o':
			_params->m_opMsisdnLength = (size_t)atoi(optarg);
		   break;
		   
		default: 
		fprintf(stderr, "Usage: %s [-n num of records] [-s subscriber msisdn num length] [-o operator msisdn num length]\n", _argv[0]);
		exit(EXIT_FAILURE);
	   }
	}
   
	return;
}



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



void GenerateCDRFile(DataGenParams _params)
{
	FILE* fp;
	char str[128];
	char numOfRecStr[32];
	char fileNumStr[128];
	char fileName[128];
	char filePath[128];
	size_t index;
	
	InitGenerate();
	
	sprintf(numOfRecStr, "%d", _params.m_numOfRecords);
	GetRandomIntString(fileNumStr, 3);
	strcpy(fileName, "CDR_");
	strcat(fileName, fileNumStr);
	strcat(fileName, ".cdr");
	
	fp = fopen(fileName, "w+");
	
	if (NULL != fp)
	{
		strcat(numOfRecStr, "\n");
		fputs(numOfRecStr, fp);

		for(index = 0; index < _params.m_numOfRecords; ++index)
		{
			GetRandomIntString(str, IMSI_STR_LENGTH);
			strcat(str, "|");
			fputs(str, fp);
		
			GetRandomIntString(str, _params.m_subMsisdnLength);
			strcat(str, "|");
			fputs(str, fp);
			
			GetRandomIntString(str, IMEI_STR_LENGTH);
			strcat(str, "|");
			fputs(str, fp);
			
			GetRandomIntString(str, OPBRAND_STR_LENGTH);
			strcat(str, "|");
			fputs(str, fp);
			
			GetRandomIntString(str, _params.m_opMsisdnLength);
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
			
/*			GetRandomIntString(str, DURATION_STR_LENGTH);*/
			strcpy(str, "1|");
			fputs(str, fp);
			
/*			GetRandomIntString(str, DOWNLOAD_STR_LENGTH);*/
			strcpy(str, "1.0|");
			fputs(str, fp);
			
/*			GetRandomIntString(str, UPLOAD_STR_LENGTH);*/
			strcpy(str, "1.0|");
			fputs(str, fp);
			
			GetRandomIntString(str, _params.m_subMsisdnLength);
			strcat(str, "|");
			fputs(str, fp);
			
			GetRandomIntString(str, _params.m_opMsisdnLength);
			strcat(str, "\n");
			fputs(str, fp);
		}
	}
	
	fclose(fp);
	strcpy(filePath, "../Feeder/NewFileWatcher/NEW/");
	strcat(filePath, fileName);
	rename(fileName, filePath);
	
	return;
}







void GeneratePredictableCDRFile(DataGenParams _params)
{
	FILE* fp;
	char str[128];
	char numOfRecStr[32];
	char fileNumStr[128];
	char fileName[128];
	char filePath[128];
	size_t index;
	
	InitGenerate();
	
	sprintf(numOfRecStr, "%d", _params.m_numOfRecords);
	GetRandomIntString(fileNumStr, 3);
	strcpy(fileName, "CDR_");
	strcat(fileName, fileNumStr);
	strcat(fileName, ".cdr");
	
	fp = fopen(fileName, "w+");
	
	if (NULL != fp)
	{
		strcat(numOfRecStr, "\n");
		fputs(numOfRecStr, fp);

		for(index = 0; index < _params.m_numOfRecords; ++index)
		{
			
/*			GetRandomIntString(str, IMSI_STR_LENGTH);*/
			sprintf(str, "%u", index);
			strcat(str, "|");
			fputs(str, fp);
		
/*			GetRandomIntString(str, _params.m_subMsisdnLength);*/
			sprintf(str, "%u", index);
			strcat(str, "|");
			fputs(str, fp);
			
/*			GetRandomIntString(str, IMEI_STR_LENGTH);*/
			sprintf(str, "%u", index);
			strcat(str, "|");
			fputs(str, fp);
			
/*			GetRandomIntString(str, OPBRAND_STR_LENGTH);*/
			sprintf(str, "%u", index);
			strcat(str, "|");
			fputs(str, fp);
			
/*			GetRandomIntString(str, _params.m_opMsisdnLength);*/
			sprintf(str, "%u", index);
			strcat(str, "|");
			fputs(str, fp);
			
			switch (index % 5) /* 5 CallType enum members (in Record.h) */
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
			
/*			GetRandomIntString(str, DURATION_STR_LENGTH);*/
			strcpy(str, "1|");
			fputs(str, fp);
			
/*			GetRandomIntString(str, DOWNLOAD_STR_LENGTH);*/
			strcpy(str, "1.0|");
			fputs(str, fp);
			
/*			GetRandomIntString(str, UPLOAD_STR_LENGTH);*/
			strcpy(str, "1.0|");
			fputs(str, fp);
			
/*			GetRandomIntString(str, _params.m_subMsisdnLength);*/
			sprintf(str, "%u", index);
			strcat(str, "|");
			fputs(str, fp);
			
/*			GetRandomIntString(str, _params.m_opMsisdnLength);*/
			sprintf(str, "%u", index);
			strcat(str, "\n");
			fputs(str, fp);
		}
	}
	
	fclose(fp);
	strcpy(filePath, "../Feeder/NewFileWatcher/NEW/");
	strcat(filePath, fileName);
	rename(fileName, filePath);
	
	return;
}







