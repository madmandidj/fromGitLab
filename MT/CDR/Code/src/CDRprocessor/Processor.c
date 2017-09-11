#include "Processor.h"

#define PROCESSOR_MAGIC 0x0C111111

struct Processor
{
	unsigned int 		m_magicNum;
	unsigned int		m_numOfThreads;
	pthread_t*			m_threadIDs;
	Subscriber*			m_subscriber;
	Operator*			m_operator;
};



Processor* 		ProcessorCreate(/*TODO: add parameters*/)

