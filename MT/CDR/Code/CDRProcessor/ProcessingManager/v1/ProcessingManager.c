#include "../../Comms/ChannelDefs/ChannelDefs.h"
#include "../../Comms/MsgQueue/MsgType.h"
#include "../Accumulator/Accumulator.h"
#include "../Processor/Processor.h"
#include "ProcessingManager.h"


struct ProcessingManagerCreate
{
	Accumulator* 	m_accum;
	Processor* 		m_proc;
	Receiver*		m_rcvr;

};




ProcessingManager* ProcessingManagerCreate()
{
	ProcessingManager* procMngr;
	
	procMngr = malloc(sizeof(procMngr));
	if (!procMngr)
	{
		return NULL;
	}
	
	procMngr->m_rcvr = ReceiverCreate();
	if (!procMngr->m_rcvr)
	{
		return NULL;
	}

	

}




