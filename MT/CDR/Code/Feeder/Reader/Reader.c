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
	int cdrNumOfLines = 0;
	char curCwd[1024];
	
	
/*	Record record = {0};*/
	
	printf("cwd = %s\n", getcwd(curCwd, sizeof(curCwd)));
	fp = fopen(_reader->m_cdrPath, "r");
	fseek(fp, 0, 0);
	
/*	while (1 == _reader->m_systemMode && !feof(fp))*/
/*	while (1 == _reader->m_systemMode)*/
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
			cdrNumOfLines = atoi(token);
			printf("cdrNumOfLines int = %d\n", cdrNumOfLines);
		}
		
		while (1)
    	{
        	if (feof(fp))
        	{
        		isFeof = 1;
            	break;
        	}
        	else
        	{
/*        		++lineNum;*/
/*				fgets(cdrLine, 512, fp);*/
/*				token = strtok(cdrLine,"|");*/
/*				*/
/*				if (1 == lineNum)*/
/*				{*/
/*					cdrNumOfLines = atoi(token);*/
/*					printf("cdrNumOfLines int = %d\n", cdrNumOfLines);*/
/*					continue;*/
/*				}*/
				fgets(cdrLine, 512, fp);
				
				token = strtok(cdrLine, "|");
				
				while(NULL != token)
				{
					printf("token string = %s\n", token);
					token = strtok(NULL, "|");	
				}
			}
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







