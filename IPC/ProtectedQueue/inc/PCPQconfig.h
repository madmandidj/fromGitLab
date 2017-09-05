#ifndef __PCPQ_CONFIG__
#define __PCPQ_CONFIG__

#include <stdlib.h>

typedef struct Params Params;

Params* CreateParams();

void	DestroyParams(Params* _params);

void 	DoPCPQconfig(int _argc, char* argv[], Params* _params);

size_t 	GetNumOfProds(Params* _params);

size_t 	GetNumOfCons(Params* _params);

size_t 	GetNumOfMsgs(Params* _params);

size_t 	GetSpeed(Params* _params);

size_t 	GetVerbosity(Params* _params);

#endif /* #ifndef __PCPQ_CONFIG__ */
