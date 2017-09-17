#include "Reader.h"
#include "../../Comms/MsgQueue/MsgType.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> /*getcwd()*/


struct Reader
{
	unsigned int		m_systemMode;
	unsigned int		m_numOfThreads;
	char				m_cdrPath[256];
	pthread_t*			m_threadIDs;
	Transmitter*		m_trans;
	Receiver*			m_rcvr;
	/* Parser*			m_parser */
};




Reader* ReaderCreate(unsigned int _numOfThreads, char* _cdrPath, Transmitter* _trans, Receiver* _rcvr)
{
	Reader* reader;
	
	reader = malloc(sizeof(Reader));
	if (!reader)
	{
		return NULL;
	}
	
	reader->m_numOfThreads = _numOfThreads;
	
	reader->m_threadIDs = malloc(reader->m_numOfThreads * sizeof(pthread_t));
	if (!reader->m_threadIDs)
	{
		free(reader);
		return NULL;
	}
	
	reader->m_systemMode = 1;
	
	strcpy(reader->m_cdrPath, _cdrPath);
	
	return reader;
}




void ReaderDestroy(Reader* _reader)
{
	if (!_reader)
	{
		return;
	}
	
	free(_reader->m_threadIDs);
	free(_reader);
	
	return;
}









typedef void* (*ThreadRoutine)(void*);





void* ReaderRoutine(Reader* _reader)
{
	ssize_t err;
	Msg uiMsg = {0};
	FILE* fp;
	int isFeof = 0;
	char cdrLine[512];
	char* token;
/*	int lineNum = 0;*/
/*	int cdrNumOfLines = 0;*/
	char curCwd[1024];
	
	
	Record record = {0};
	
	printf("cwd = %s\n", getcwd(curCwd, sizeof(curCwd)));
	fp = fopen(_reader->m_cdrPath, "r");
	fseek(fp, 0, 0);
	
	while (!isFeof)
	{
		err = ReceiverReceive(_reader->m_rcvr, &uiMsg, sizeof(Data), UI_TO_FEEDER, IPC_NOWAIT);
		if (err > -1)
		{
			if (666 == uiMsg.m_data.m_uiCommand.m_command)
			{
				_reader->m_systemMode = 0; /* TODO: this does nothing in feeder for now */
				continue;
			}
		}
		
		if (feof(fp))
    	{
    		isFeof = 1;
        	break;
    	}
    	else
    	{
			fgets(cdrLine, 512, fp);
			token = strtok(cdrLine, "|\n");
/*			cdrNumOfLines = atoi(token);*/
/*			printf("cdrNumOfLines int = %d\n", cdrNumOfLines);*/
		}
		
		while (1)
    	{
			fgets(cdrLine, 512, fp);
			if (feof(fp))
	    	{
	    		isFeof = 1;
	        	break;
	    	}
			
			/* Get IMSI */
			token = strtok(cdrLine, "|");
			strcpy(record.m_imsi, token);
			
			/* Get MSISDN */
			token = strtok(NULL, "|");
			strcpy(record.m_msisdn, token);
			
			/* Get IMEI */
			token = strtok(NULL, "|");
			strcpy(record.m_imei, token);
			
			/* Get OpBrand */
			token = strtok(NULL, "|");
			strcpy(record.m_operatorBrand, token);
			
			/* Get OPMccMnc */
			token = strtok(NULL, "|");
			strcpy(record.m_operatorMCCMNC, token);
			
			/* Get Call type TODO: convert to correct enum int */
			token = strtok(NULL, "|");
			if (!strcmp(token, "MOC"))
			{
				record.m_callType = 0;
			}
			
			/* Get Call Date */
			token = strtok(NULL, "|");
			strcpy(record.m_callDate, token);
			
			/* Get Call Time */
			token = strtok(NULL, "|");
			strcpy(record.m_callTime, token);
			
			/* Get Duration */
			token = strtok(NULL, "|");
			record.m_duration = (unsigned int)atoi(token);
			
			/* Get Download TODO: convert to float */
			token = strtok(NULL, "|");
			record.m_downloadMB = strtof(token, NULL);
			
			/* Get Upload TODO: convert to float */
			token = strtok(NULL, "|");
			record.m_uploadMB = strtof(token, NULL);
			
			/* Get Party MSISDN */
			token = strtok(NULL, "|");
			strcpy(record.m_partyMsisdn, token);
			
			/* Get Party Operator */
			token = strtok(NULL, "|\n");
			strcpy(record.m_partyMCCMNC, token);
			
			
			
			
/*			while(NULL != token)*/
/*			{*/
/*				printf("token string = %s\n", token);*/
/*				token = strtok(NULL, "|\n");	*/
/*			}*/
		}
		/*
		Read line from CDR file
		Parse to record
		Send to msgQ for processor
		*/	 
	}
	
	return NULL;
}











int ReaderRun(Reader* _reader)
{
	size_t index;
	
	if (!_reader)
	{
		return 0;
	}
	
	for (index = 0; index < _reader->m_numOfThreads; ++index)
	{
		if (pthread_create(_reader->m_threadIDs + index, NULL, (ThreadRoutine)ReaderRoutine, _reader))
		{
			return 0;
		}
	}
	
	for (index = 0; index < _reader->m_numOfThreads; ++index)
	{
		pthread_join(_reader->m_threadIDs[index], NULL);
	}
	
	return 1;
}







