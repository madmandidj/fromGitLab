#include "Reader.h"
#include "../../Comms/MsgQueue/MsgType.h"
#include "../../Comms/ChannelDefs/ChannelDefs.h"
#include "../NewFileWatcher/NewFileWatcher.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>



struct Reader
{
	unsigned int		m_systemMode;
	unsigned int		m_numOfThreads;
	char				m_cdrPath[256];
	pthread_t*			m_threadIDs;
	Transmitter*		m_trans;
	Receiver*			m_rcvr;
	pthread_mutex_t		m_newFileMutex;
};



typedef void* (*ThreadRoutine)(void*);



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
	
	if (pthread_mutex_init(&reader->m_newFileMutex, NULL))
	{
		free(reader->m_threadIDs);
		free(reader);
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
	
	pthread_mutex_destroy(&_reader->m_newFileMutex);
	free(_reader->m_threadIDs);
	free(_reader);
	
	return;
}



static void HandleUIMsg(Reader* _reader, Msg* _uiMsg, FILE* _fp)
{
	ssize_t err; 
	
	err = ReceiverReceive(_reader->m_rcvr, _uiMsg, sizeof(Data), UI_TO_FEEDER, IPC_NOWAIT);
	if (err > -1)
	{
		switch (_uiMsg->m_data.m_uiCommand.m_command)
		{	
			case PAUSE:
				/*
				TODO: use pcond_wait to pause?
				*/
				break;
		
			case RESUME:
				/*
				TODO: use pcond_signal to resume?
				*/
				break;
		
			case SHUTDOWN:
				if (!_fp)
				{
					fclose(_fp);	/* Check if this can corrupt file/data */
				}
				printf("reader received shutdown\n");
				_reader->m_systemMode = 0;
				return;
		}
	}
	
	return;	
}



static Record ParseCDRToRecord(char* _cdrLine, char* _cdrLinePtr)
{
	char* token;
	Record record;
	
	/* Get IMSI */
	token = strtok_r(_cdrLine, "|", &_cdrLinePtr);
	
	strcpy(record.m_imsi, token);

	/* Get MSISDN */
	token = strtok_r(NULL, "|", &_cdrLinePtr);
	
	strcpy(record.m_msisdn, token);

	/* Get IMEI */
	token = strtok_r(NULL, "|", &_cdrLinePtr);
	
	strcpy(record.m_imei, token);

	/* Get OpBrand */
	token = strtok_r(NULL, "|", &_cdrLinePtr);
	
	strcpy(record.m_operatorBrand, token);

	/* Get OPMccMnc */
	token = strtok_r(NULL, "|", &_cdrLinePtr);
	
	strcpy(record.m_operatorMCCMNC, token);

	/* Get Call type */
	token = strtok_r(NULL, "|", &_cdrLinePtr);
	
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
	token = strtok_r(NULL, "|", &_cdrLinePtr);
	
	strcpy(record.m_callDate, token);

	/* Get Call Time */
	token = strtok_r(NULL, "|", &_cdrLinePtr);
	
	strcpy(record.m_callTime, token);

	/* Get Duration */
	token = strtok_r(NULL, "|", &_cdrLinePtr);
	
	record.m_duration = (unsigned int)atoi(token);

	/* Get Download */
	token = strtok_r(NULL, "|", &_cdrLinePtr);
	
	record.m_downloadMB = strtof(token, NULL);

	/* Get Upload */
	token = strtok_r(NULL, "|", &_cdrLinePtr);
	
	record.m_uploadMB = strtof(token, NULL);

	/* Get Party MSISDN */
	token = strtok_r(NULL, "|", &_cdrLinePtr);
	
	strcpy(record.m_partyMsisdn, token);

	/* Get Party Operator */
	token = strtok_r(NULL, "|\n", &_cdrLinePtr);
	
	strcpy(record.m_partyMCCMNC, token);
	
	return record;
}



void* ReaderRoutine(Reader* _reader)
{
	Msg uiMsg = {0};
	FILE* fp;
	int isFeof = 0;
	char cdrLine[512];
	char* cdrLinePtr;
	char* token;
	Record record = {0};
	Data data = {0};
	Msg msg = {0};
	int isNewFile = 0;
	char fopenFileName[64];
	char newFileName[64];
	char workPathName[64];
	char donePathName[64];
	
	msg.m_channel = FEEDER_TO_PROCESSOR_CH;
	
	while (1)
	{
		/* Check if new cdr file is in directory */
		isNewFile = GetNewFilePath(newFileName, &_reader->m_newFileMutex);
		
		/* If no new file than go into listentoUI/waitfornewfile mode */
		while(!isNewFile)
		{
			sleep(1);
			if (!_reader->m_systemMode)
			{
				return NULL;
			}
			isNewFile = GetNewFilePath(newFileName, &_reader->m_newFileMutex);
			HandleUIMsg(_reader, &uiMsg, fp);
		}
		
		isFeof = 0;
		
		strcpy(fopenFileName, _reader->m_cdrPath);
		
		strcat(fopenFileName, newFileName);
		
		fp = fopen(fopenFileName, "r");
		
		fseek(fp, 0, 0);
		
		printf("Starting to read from: %s\n", fopenFileName);
		
		while (!isFeof)
		{
			HandleUIMsg(_reader, &uiMsg, fp);

			if (feof(fp))
			{
				isFeof = 1;
		    	break;
			}
			else
			{
				fgets(cdrLine, 512, fp);
				token = strtok_r(cdrLine, "|\n", &cdrLinePtr);
				printf("Number of entries in this file = %s\n", token);
			}
		
			while (1)
			{
				HandleUIMsg(_reader, &uiMsg, fp);
				
				fgets(cdrLine, 512, fp);
				if (feof(fp))
				{
					isFeof = 1;
			    	break;
				}
				
				/*Parse CDR to Record*/
				record = ParseCDRToRecord(cdrLine, cdrLinePtr);
			
				/* Send Record to processor */
				data.m_rec = record;
				
				msg.m_data = data;
				
				TransmitterSend(_reader->m_trans, &msg, sizeof(Data), FEEDER_TO_PROCESSOR_CH);
			}
		}
		strcpy(workPathName, "./NewFileWatcher/WORKING/");
		
		strcat(workPathName, newFileName);
		
		strcpy(donePathName, "./NewFileWatcher/DONE/");
		
		strcat(donePathName, newFileName);
		
		rename(workPathName, donePathName);
		
		fclose(fp);	
		
		printf("Finished reading from: %s\n", fopenFileName);	
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






