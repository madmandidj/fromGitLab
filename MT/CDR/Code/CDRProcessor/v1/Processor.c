#include "../../inc/Processor.h"
#include "../../inc/Accumulator.h"
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
	/*Subscriber			m_subscriber;
	Operator			m_operator;*/
	Accumulator*		m_accum;
	/*FeederServer*		m_feedServer;*/
};



Processor* ProcessorCreate(unsigned int _numOfThreads)
{
	Processor* proc;
	
	proc = malloc(sizeof(Processor));
	if (!proc)
	{
		return NULL;
	}
	
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
	Subscriber* subscriber;
	Operator* operator;		
	Record record = {"111111111111111", 
						"222222222222222",
						"333333333333333",
						"CellCom Israel",
						123456,
						MOC,
						"17/01/1984",
						444, 
						555, 
						666, 
						777, 
						"888888888888888",
						654321		 
	}; 
	
	/*
	LOOP FROM HERE TILL END OF ROUTINE FOREVER OR UNTILL SHUTDOWN IS RECEIVED
	*/
	
	subscriber = malloc(sizeof(Subscriber));
	operator = malloc(sizeof(Operator));
	
	
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
	
	
	/*
	Parse record into operator and subscriber
	*/
	strcpy(subscriber->m_imsi, record.m_imsi);
	strcpy(subscriber->m_msisdn, record.m_msisdn);

	
	switch(record.m_callType)
	{
		case MOC:
			if (record.m_operatorMCCMNC == record.m_partyMCCMNC)
			{
				subscriber->m_outVoiceWithinOp = record.m_duration;
			}
			else
			{
				subscriber->m_outVoiceOutsideOp = record.m_duration;
			}
			break;
		
		case MTC:
			if (record.m_operatorMCCMNC == record.m_partyMCCMNC)
			{
				subscriber->m_inVoiceWithinOp = record.m_duration;
			}
			else
			{
				subscriber->m_inVoiceOutsideOp = record.m_duration;
			}
			break;
		
		case SMS_MO:
			if (record.m_operatorMCCMNC == record.m_partyMCCMNC)
			{
				subscriber->m_outSmsWithinOp = 1;
			}
			else
			{
				subscriber->m_outSmsOutsideOp = 1;
			}
			break;
		
		case SMS_MT:
			if (record.m_operatorMCCMNC == record.m_partyMCCMNC)
			{
				subscriber->m_inSmsWithinOp = 1;
			}
			else
			{
				subscriber->m_inSmsOutsideOp = 1;
			}
			break;
		
		case GPRS:
				subscriber->m_downloadMB = record.m_downloadMB;
				subscriber->m_uploadMB = record.m_uploadMB;
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



















