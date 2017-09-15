/*#include "../../Comms/ChannelDefs/ChannelDefs.h"*/
/*#include "../../Comms/MsgQueue/MsgType.h"*/
#include "../../Comms/Receiver/Receiver.h"
#include "../Accumulator/Accumulator.h"
#include "../Processor/Processor.h"
#include "ProcessingManager.h"
#include <stdlib.h>
#include <stdio.h>


struct ProcessingManager
{
	Accumulator* 	m_accum;
	Processor* 		m_proc;
	Receiver*		m_rcvr;

};




ProcessingManager* ProcessingManagerCreate(size_t _numOfProcThreads)
{
	ProcessingManager* procMngr;
	
	procMngr = malloc(sizeof(procMngr));
	if (!procMngr)
	{
		return NULL;
	}
	
	procMngr->m_accum = AccumulatorCreate();
	if (!procMngr->m_accum)
	{
		free(procMngr);
		return NULL;
	}
	
	procMngr->m_rcvr = ReceiverCreate();
	if (!procMngr->m_rcvr)
	{
		AccumulatorDestroy(procMngr->m_accum);
		free(procMngr);
		return NULL;
	}
	
	procMngr->m_proc = ProcessorCreate(procMngr->m_accum, procMngr->m_rcvr, _numOfProcThreads);
	if (!procMngr->m_rcvr)
	{
		ReceiverDestroy(procMngr->m_rcvr);
		AccumulatorDestroy(procMngr->m_accum);
		free(procMngr);
		return NULL;
	}

	return procMngr;
}





void ProcessingManagerDestroy(ProcessingManager* _procMngr)
{
	if (!_procMngr)
	{
		return;
	}
	
	ReceiverDestroy(_procMngr->m_rcvr);
	AccumulatorDestroy(_procMngr->m_accum);
	ProcessorDestroy(_procMngr->m_proc);
	free(_procMngr);
	
	return;
}






int main()
{
	size_t numOfProcThreads = 1;
	ProcessingManager* procMngr;
	
	procMngr = ProcessingManagerCreate(numOfProcThreads);
	ProcessorRun(procMngr->m_proc);
	printf("here");
	
	return 0;

}

/*
int ProcessingManagerRun(ProcessingManager* _procMngr)
{
	ProcessorRun(_procMngr->m_proc);
	return 1;
}
*/



