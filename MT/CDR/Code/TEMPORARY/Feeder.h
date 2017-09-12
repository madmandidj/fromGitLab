#ifndef __FEEDER_H__
#define __FEEDER_H__

typedef struct Feeder Feeder;

/*
FOR Feeder.c FILE:
--------------------
#include "Feeder.h"
#include "Reader.h"
#include "Parser.h"
#include "Transmitter.h"
#include "ImportManager.h"
#include "Logger.h"


struct Feeder
{
	unsigned int		m_magicNum;
	Reader*				m_reader;
	Feeder*				m_feeder;
	ImportManager*		m_importManager;
};
*/

Feeder*		FeederCreate(/*TODO: add parameters*/);

void		FeederDestroy(Feeder* _feeder);

/*TODO: add return*/	FeederRun(/*TODO: add parameters*/);

/*TODO: add return*/	FeederPause(/*TODO: add parameters*/);

/*TODO: add return*/	FeederResume(/*TODO: add parameters*/);

/*TODO: add return*/	FeederShutdown(/*TODO: add parameters*/);
















#endif /* #ifndef __FEEDER_H__ */













