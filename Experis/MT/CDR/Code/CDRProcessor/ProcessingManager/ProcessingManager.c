#include "../../Comms/Receiver/Receiver.h"
#include "../Accumulator/Accumulator.h"
#include "../Processor/Processor.h"
#include "ProcessingManager.h"
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>



struct ProcessingManager
{
	Accumulator* 	m_accum;
	Processor* 		m_proc;
	Receiver*		m_rcvr;

};



void DoGetOpt(int _argc, char* _argv[], ProcMngrParams* _params)
{
	int opt;
	
	while ((opt = getopt(_argc, _argv, "n:s:o:")) != -1) {
	   switch (opt) 
	   {
		case 'n':
			_params->m_numOfProcessors = (size_t)atoi(optarg);
		   break;
		   
		case 's':
			_params->m_subHashSize = (size_t)atoi(optarg);
		   break;
		   
		case 'o':
			_params->m_opHashSize = (size_t)atoi(optarg);
		   break;
		   
		default: 
		fprintf(stderr, "Usage: %s [-n num of processors]\n", _argv[0]);
		exit(EXIT_FAILURE);
	   }
	}
   
	return;
}



ProcessingManager* ProcessingManagerCreate(ProcMngrParams _params)
{
	ProcessingManager* procMngr;
	
	procMngr = malloc(sizeof(procMngr));
	if (!procMngr)
	{
		return NULL;
	}
	
	procMngr->m_accum = AccumulatorCreate(_params.m_subHashSize, _params.m_opHashSize);
	if (!procMngr->m_accum)
	{
		free(procMngr);
		
		return NULL;
	}
	
	procMngr->m_rcvr = ReceiverCreate("../Comms/MsgQueue/MQ");
	if (!procMngr->m_rcvr)
	{
		AccumulatorDestroy(procMngr->m_accum);
		
		free(procMngr);
		
		return NULL;
	}
	
	procMngr->m_proc = ProcessorCreate(procMngr->m_accum, procMngr->m_rcvr, _params.m_numOfProcessors);
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



int main(int argc, char* argv[])
{
	ProcMngrParams params;
	ProcessingManager* procMngr;
	
	printf("***CDR Processor***\n");
	
	DoGetOpt(argc, argv, &params);
	
	procMngr = ProcessingManagerCreate(params);
	
	printf("Running processor\n");
	
	ProcessorRun(procMngr->m_proc);
	
	ProcessingManagerDestroy(procMngr);
	
	return 0;
}

