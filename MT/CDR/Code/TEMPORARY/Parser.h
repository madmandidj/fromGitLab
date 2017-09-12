#ifndef __PARSER_H__
#define __PARSER_H__

typedef struct Parser Parser;

#include "Record.h"


/*
FOR Parser.c FILE:
--------------------
#include "Parser.h"
#include "Logger.h"


struct Parser
{
	unsigned int		m_magicNum;
	char*				m_CDR;
	Record				m_record;
};
*/

Parser*		ParserCreate(/*TODO: add parameters*/);

void		ParserDestroy(/*TODO: add parameters*/);

/*TODO: add return*/	ParserDoParse(/*TODO: add parameters*/);

/*TODO: add return*/	ParserPause(/*TODO: add parameters*/);

/*TODO: add return*/	ParserResume(/*TODO: add parameters*/);

/*TODO: add return*/	ParserShutdown(/*TODO: add parameters*/);


#endif /* __PARSER_H__ */






