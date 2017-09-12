#ifndef __TRANSMITTER_H__
#define __TRANSMITTER_H__

#include "Record.h"

typedef struct Transceiver Transceiver;


/*
FOR Transmitter.c FILE:
--------------------
#include "MessageQueue.h"
#include "Logger.h"



struct Transmitter
{
	unsigned int		m_magicNum;
	MessageQueue*		m_queue;
	long				m_channel;
	void*				m_msg;
};
*/

Transmitter* 	TransmitterCreate(/*TODO: add parameters*/);

void			TransmitterDestroy(/*TODO: add parameters*/);

/*TODO: Add return*/ TransmitterSend(/*TODO: add parameters*/);

/*TODO: Add return*/ TransmitterRecieve(Transmitter* _txObject);

/*
TransmitterPause();

TransmitterResume();

TransmitterShutdown();
*/





#endif /* #ifndef __TRANSMITTER_H__ */







