#ifndef __PROCESSOR_MANAGER_H__
#define __PROCESSOR_MANAGER_H__


typedef struct ProcessorManager ProcessorManager;


/*
FOR ProcessorManager.c FILE
---------------------------
#include "ProcessorManager.h"
#include "Transceiver.h"
#include "Processor.h"
#include "Storer.h"
#include "UIServer.h"
#include "FeederServer.h"
#include "Logger.h"

struct ProcessorManager
{
	unsigned int	m_magicNum;
	Transceiver* 	m_transceiver;
	Processor* 		m_processor;
	Storer*			m_storer;
	UIServer*		m_uiServer;
	FeederServer*	m_feederServer;
}
*/


ProcessorManager* ProcessorManagerCreate(Processor* _proc, Storer* _stor, Transceiver* _trans, ...);

void ProcessorManagerDestroy(ProcessorManager* _procMan);

int ProcessorManagerPause(ProcessorManager* _procMan);

int ProcessorManagerResume(ProcessorManager* _procMan);

int ProcessorManagerStop(ProcessorManager* _procMan);






#endif /* __PROCESSOR_MANAGER_H__ */






