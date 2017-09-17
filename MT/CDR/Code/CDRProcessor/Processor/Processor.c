#include "Processor.h"
#include "../../Comms/MsgQueue/MsgType.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <syscall.h> /* syscall gettid */

#define PROCESSOR_MAGIC 0x0C111111

struct Processor
{
	unsigned int 		m_magicNum;
	unsigned int		m_systemMode;
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
	
	proc->m_systemMode = 1;

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
	static unsigned int numOfMsgsRxed = 0;
	ssize_t err;
	Msg msg = {0};
	Msg uiMsg = {0};
	Record record = {0};	
	Subscriber sub = {0};
	Operator oper = {0};
	size_t numOfSubs = 0;
		
	if (!_proc)
	{
		return NULL;
	}

	while(1 == _proc->m_systemMode)
	{
		err = ReceiverReceive(_proc->m_rcvr, &uiMsg, sizeof(Data), UI_TO_PROCESSOR, IPC_NOWAIT);
		if (err > -1)
		{
			++numOfMsgsRxed;
			if (666 == uiMsg.m_data.m_uiCommand.m_command)
			{
				_proc->m_systemMode = 0;
				continue;
			}
			if (100 == uiMsg.m_data.m_uiCommand.m_command)
			{
				numOfSubs = AccumulatorPrintAllSubscribers(_proc->m_accum);
				printf("Number of Subscribers = %u\n", numOfSubs);
				continue;
			}
		}
		
		err = ReceiverReceive(_proc->m_rcvr, &msg, sizeof(Data), FEEDER_TO_PROCESSOR_CH, IPC_NOWAIT);
		if (err > -1)
		{
			printf("tid = %ld\n", syscall(SYS_gettid));
			++numOfMsgsRxed;
			record = msg.m_data.m_rec;
			strcpy(sub.m_imsi, record.m_imsi);
			strcpy(sub.m_msisdn, record.m_msisdn);
			strcpy(oper.m_operatorBrand, record.m_operatorBrand);
			strcpy(oper.m_operatorMCCMNC, record.m_operatorMCCMNC);
	
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
			
					oper.m_outVoice = record.m_duration;
			
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
			
					oper.m_inVoice = record.m_duration;
			
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
			
					oper.m_outSms = 1;
			
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
			
					oper.m_inSms = 1;
			
					break;
		
				case GPRS:
						sub.m_downloadMB = record.m_downloadMB;
						sub.m_uploadMB = record.m_uploadMB;
						oper.m_downloadMB = record.m_downloadMB;
						oper.m_uploadMB = record.m_uploadMB;
					break;
			
				default:
						printf("Wrong Processor Routine Parsing");
					break;
			}
			
			AccumulatorUpdateSubscriber(_proc->m_accum, &sub);

			AccumulatorUpdateOperator(_proc->m_accum, &oper);
		}	
	}

	return NULL;
}


int ProcessorRun(Processor* _proc)
{
	size_t index;
	
	if (NULL == _proc)
	{
		return 0;
	}
	
	for (index = 0; index < _proc->m_numOfThreads; ++index)
	{
		if (pthread_create(_proc->m_threadIDs + index, NULL, (ThreadRoutine)ProcessorRoutine, _proc))
		{
			return 0;
		}
	}
	
	for (index = 0; index < _proc->m_numOfThreads; ++index)
	{
		pthread_join(_proc->m_threadIDs[index], NULL);
	}
	
	return 1;
}



















