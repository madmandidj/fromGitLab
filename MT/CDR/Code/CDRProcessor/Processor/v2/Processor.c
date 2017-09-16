#include "Processor.h"
#include "../../Comms/MsgQueue/MsgType.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define PROCESSOR_MAGIC 0x0C111111

struct Processor
{
	unsigned int 		m_magicNum;
	unsigned int		m_numOfThreads;
	pthread_t*			m_threadIDs;
	Accumulator*		m_accum;
	Receiver*			m_rcvr;
};



Processor* ProcessorCreate(Accumulator* _accum, Receiver* _rcvr, unsigned int _numOfThreads)
{
	Processor* proc;
	
	proc = malloc(sizeof(Processor));
	if (!proc)
	{
		return NULL;
	}
	
	proc->m_accum = _accum;
	
	proc->m_rcvr = _rcvr;
	
	proc->m_numOfThreads = _numOfThreads;
	
	proc->m_threadIDs = malloc(proc->m_numOfThreads * sizeof(pthread_t));
	if (!proc->m_threadIDs)
	{
		free(proc);
		return NULL;
	}
	
	proc->m_magicNum = PROCESSOR_MAGIC;

	return proc;
}







void ProcessorDestroy(Processor* _proc)
{
	if (!_proc)
	{
		return;
	}
	
	free(_proc->m_threadIDs);
	free(_proc);
	return;
}







typedef void* (*ThreadRoutine)(void*);


void* ProcessorRoutine(Processor* _proc)
{
	Msg msg;
	Record record;	
	Subscriber sub;
		
	/*
	Check valid parameters
	*/
	
	if (!_proc)
	{
		return NULL;
	}
	
	/*
	Repeat the following untill shutdown received
	
	*/
	
	/*
	Get record from Feeder Server
	*/
/*	ReceiverReceive(_proc->m_rcvr, &msg, sizeof(Record), FEEDER_TO_PROCESSOR_CH, 0);*/
	ReceiverReceive(_proc->m_rcvr, &msg, sizeof(Data), FEEDER_TO_PROCESSOR_CH, 0);

/*	record = *(Record*)msg.m_data;*/
	record = msg.m_data.m_rec;

	/*
	Parse record into operator and subscriber
	*/
	strcpy(sub.m_imsi, record.m_imsi);
	strcpy(sub.m_msisdn, record.m_msisdn);

	
	switch(record.m_callType)
	{
		case MOC:
			if (record.m_operatorMCCMNC == record.m_partyMCCMNC)
			{
				sub.m_outVoiceWithinOp = record.m_duration;
			}
			else
			{
				sub.m_outVoiceOutsideOp = record.m_duration;
			}
			break;
		
		case MTC:
			if (record.m_operatorMCCMNC == record.m_partyMCCMNC)
			{
				sub.m_inVoiceWithinOp = record.m_duration;
			}
			else
			{
				sub.m_inVoiceOutsideOp = record.m_duration;
			}
			break;
		
		case SMS_MO:
			if (record.m_operatorMCCMNC == record.m_partyMCCMNC)
			{
				sub.m_outSmsWithinOp = 1;
			}
			else
			{
				sub.m_outSmsOutsideOp = 1;
			}
			break;
		
		case SMS_MT:
			if (record.m_operatorMCCMNC == record.m_partyMCCMNC)
			{
				sub.m_inSmsWithinOp = 1;
			}
			else
			{
				sub.m_inSmsOutsideOp = 1;
			}
			break;
		
		case GPRS:
				sub.m_downloadMB = record.m_downloadMB;
				sub.m_uploadMB = record.m_uploadMB;
			break;
			
		default:
				printf("Wrong Processor Routine Parsing");
			break;
	}
	

	/*
	MUTEX_LOCK
	Call accumulator get subscriber
	Call accumulator update subscriber
	Call accumulator get operator
	Call accumulator update operator
	MUTEX_UNLOCK
	*/
	
	return NULL;
}


int ProcessorRun(Processor* _proc)
{
	size_t index;
	
	if (NULL == _proc)
	{
		return 1;
	}
	
	for (index = 0; index < _proc->m_numOfThreads; ++index)
	{
		if (pthread_create(_proc->m_threadIDs + index, NULL, (ThreadRoutine)ProcessorRoutine, _proc))
		{
			return 1;
		}
	}
	
	pthread_join(_proc->m_threadIDs[0], NULL);
	
	return 0;
}



















