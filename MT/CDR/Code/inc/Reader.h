#ifndef __READER_H__
#define __READER_H__

typedef struct Reader Reader;


/*
FOR Reader.c FILE:
--------------------
#include "Reader.h"
#include "Logger.h"


struct Reader
{
	unsigned int		m_magicNum;
	int					m_cdrFileDescriptor;
	char*				m_CDR;
};
*/




Reader*		ReaderCreate(/*TODO: add parameters*/);

void		ReaderDestroy(/*TODO: add parameters*/);

char*		ReaderGetCDR(/*TODO: add parameters*/);

/*TODO: add return*/	ReaderRun(/*TODO: add parameters*/);

/*TODO: add return*/	ReaderPause(/*TODO: add parameters*/);

/*TODO: add return*/	ReaderResume(/*TODO: add parameters*/);

/*TODO: add return*/	ReaderShutdown(/*TODO: add parameters*/);




#endif /* #ifndef __READER_H__ */



