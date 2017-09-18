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



void DoGetOpt(int _argc, char* _argv[], Params* _params)
{
	int opt;
	
	while ((opt = getopt(_argc, _argv, "n:")) != -1) {
	   switch (opt) 
	   {
		case 'n':
			_params->m_numOfRecords = atoi(optarg);
		   break;
		   
		default: 
		fprintf(stderr, "Usage: %s [-n num of records]\n", _argv[0]);
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



void GenerateCDRFile(int _numOfRecords)
{
	FILE* fp;
	char str[128];
	char numOfRecStr[32];
	char fileNumStr[128];
	char fileName[128];
	char filePath[128];
	size_t index;
	
	InitGenerate();
	
	sprintf(numOfRecStr, "%d", _numOfRecords);
	GetRandomIntString(fileNumStr, 3);
	strcpy(fileName, "CDR_");
	strcat(fileName, fileNumStr);
	strcat(fileName, ".cdr");
	
	fp = fopen(fileName, "w+");
	
	if (NULL != fp)
	{
		strcat(numOfRecStr, "\n");
		fputs(numOfRecStr, fp);

		for(index = 0; index < _numOfRecords; ++index)
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
	}
	
	fclose(fp);
	strcpy(filePath, "../Feeder/NewFileWatcher/NEW/");
	strcat(filePath, fileName);
	rename(fileName, filePath);
	
	return;
}












