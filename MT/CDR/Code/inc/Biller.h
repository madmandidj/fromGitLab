#ifndef __BILLER_H__
#define __BILLER_H__

typedef struct Biller Biller;

/*
FOR Biller.c FILE:
--------------------
#include "Biller.h"
#include "Processor.h"
#include "Storer.h"
#include "Transmitter.h
#include "Logger.h"


struct Biller
{
	unsigned int		m_magicNum;
	Processor* 			m_processor;
	Storer*				m_subscribers;
	Storer*				m_operators;
	Transmitter*		m_transmitter;
};
*/

Biller* BillerCreate(/*TODO: add parameters*/);

void BillerDestroy(/*TODO: add parameters*/);

/*TODO: Add return*/ BillerCreateThreads(/*TODO: add parameters*/);

/*TODO: Add return*/ BillerDestroyThreads(/*TODO: add parameters*/);

/*TODO: Add return*/ BillerRun(/*TODO: add parameters*/);

/*TODO: Add return*/ BillerPause(/*TODO: add parameters*/);

/*TODO: Add return*/ BillerResume(/*TODO: add parameters*/);

/*TODO: Add return*/ BillerExport(/*TODO: add parameters*/);




#endif /* #ifndef __BILLER_H__ */



