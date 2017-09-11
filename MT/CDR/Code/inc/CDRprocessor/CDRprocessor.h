#ifndef __CDR_PROCESSOR_H__
#define __CDR_PROCESSOR_H__


typedef struct CDRprocessor CDRprocessor;


/*
FOR CDRProcessor.c FILE
---------------------------
#include "ProcessorManager.h"

struct CDRprocessor
{
	unsigned int	m_magicNum;
	Transceiver* 	m_ProcessorManager;
};
*/


CDRProcessor*	CDRprocessorCreate(void);

void	CDRprocessorDestroy(CDRprocessor* _cdrProcessor);




#endif /* #ifndef __CDR_PROCESSOR_H__ */



