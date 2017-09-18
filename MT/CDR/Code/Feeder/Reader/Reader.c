#include "Reader.h"
#include "../../Comms/MsgQueue/MsgType.h"
#include "../../Comms/ChannelDefs/ChannelDefs.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>


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
	
	reader->m_trans = _trans;
	
	reader->m_rcvr = _rcvr;
	
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
	char* cdrLinePtr;
	char* token;
	Record record = {0};
	Data data = {0};
	Msg msg = {0};
	
	
	msg.m_channel = FEEDER_TO_PROCESSOR_CH;
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
/*			token = strtok(cdrLine, "|\n");*/
			token = strtok_r(cdrLine, "|\n", &cdrLinePtr);
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
/*			token = strtok(cdrLine, "|");*/
			token = strtok_r(cdrLine, "|", &cdrLinePtr);
			strcpy(record.m_imsi, token);
			
			/* Get MSISDN */
			token = strtok_r(NULL, "|", &cdrLinePtr);
			strcpy(record.m_msisdn, token);
			
			/* Get IMEI */
			token = strtok_r(NULL, "|", &cdrLinePtr);
			strcpy(record.m_imei, token);
			
			/* Get OpBrand */
			token = strtok_r(NULL, "|", &cdrLinePtr);
			strcpy(record.m_operatorBrand, token);
			
			/* Get OPMccMnc */
			token = strtok_r(NULL, "|", &cdrLinePtr);
			strcpy(record.m_operatorMCCMNC, token);
			
			/* Get Call type */
			token = strtok_r(NULL, "|", &cdrLinePtr);
			if (!strcmp(token, "MOC"))
			{
				record.m_callType = 0;
			}
			else if (!strcmp(token, "MTC"))
			{
				record.m_callType = 1;
			}
			else if (!strcmp(token, "SMS_MO"))
			{
				record.m_callType = 2;
			}
			else if (!strcmp(token, "SMS_MT"))
			{
				record.m_callType = 3;
			}
			else /* GPRS */
			{
				record.m_callType = 4;
			}

			/* Get Call Date */
			token = strtok_r(NULL, "|", &cdrLinePtr);
			strcpy(record.m_callDate, token);
			
			/* Get Call Time */
			token = strtok_r(NULL, "|", &cdrLinePtr);
			strcpy(record.m_callTime, token);
			
			/* Get Duration */
			token = strtok_r(NULL, "|", &cdrLinePtr);
			record.m_duration = (unsigned int)atoi(token);
			
			/* Get Download */
			token = strtok_r(NULL, "|", &cdrLinePtr);
			record.m_downloadMB = strtof(token, NULL);
			
			/* Get Upload */
			token = strtok_r(NULL, "|", &cdrLinePtr);
			record.m_uploadMB = strtof(token, NULL);
			
			/* Get Party MSISDN */
			token = strtok_r(NULL, "|", &cdrLinePtr);
			strcpy(record.m_partyMsisdn, token);
			
			/* Get Party Operator */
			token = strtok_r(NULL, "|\n", &cdrLinePtr);
			strcpy(record.m_partyMCCMNC, token);
			
			/* Send Record to processor */
			data.m_rec = record;
			msg.m_data = data;
			TransmitterSend(_reader->m_trans, &msg, sizeof(Data), FEEDER_TO_PROCESSOR_CH);
		}
		
		
		
		/*
		Send to msgQ for processor
		*/	 
	}
	
	rename("./Reader/WORKING/TestCDRFile.cdr", "./Reader/DONE/TestCDRFile.cdr");
	
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







