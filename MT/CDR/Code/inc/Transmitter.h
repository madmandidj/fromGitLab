#ifndef __TRANSMITTER_H__
#define __TRANSMITTER_H__

#include "Record.h"

typedef struct Transmitter Transmitter;


/*
FOR Transmitter.c FILE:
--------------------
#include "MessageQueue.h"
#include "Logger.h"



struct Transmitter
{
	unsigned int		m_magicNum;
	pthread_t			m_threadIDs;
	HashMap* 			m_Storage;
};
*/

Transmitter* 	TransmitterCreate(/*TODO: add parameters*/);

void			TransmitterDestroy(/*TODO: add parameters*/);

/*TODO: Add return*/ TransmitterSend(/*TODO: add parameters*/);

/*TODO: Add return*/ TransmitterGet(/*TODO: add parameters*/);

/*TODO: Add return*/ TransmitterPause(/*TODO: add parameters*/);

/*TODO: Add return*/ TransmitterResume(/*TODO: add parameters*/);

/*TODO: Add return*/ TransmitterShutdown(/*TODO: add parameters*/);






#endif /* #ifndef __TRANSMITTER_H__ */







