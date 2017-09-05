
#include "../inc/PCPQconfig.h"
#include <unistd.h>

struct Params
{
	size_t m_numOfProds;
	size_t m_numOfCons;
	size_t m_numOfMsgs;
	size_t m_speed;
	size_t m_verbosity;
};

void DoPCPQconfig(int _argc, char* argv[], Params* _params)
{
	int opt;
	
	/*
	 Set defaults:
	*/
	_params->m_numOfProds = 5;
	_params->m_numOfCons = 5;
	_params->m_numOfMsgs = 5;
	_params->m_speed = 100000;
	_params->m_verbosity = 1;
	
	
	
	
	while ((opt = getopt(_argc, _argv, "p:c:n:s:v:")) != -1) {
	   switch (opt) 
	   {
		case 'p':
			_params->m_numOfProds = atoi(optarg);
		   break;
		   
		case 'c':
			msgctl(atoi(optarg), IPC_RMID, NULL);
		   break;
		   
		case 'n':
			_params->m_numOfMsgs = atoi(optarg);
		   break;
		   
		case 's':
			_params->m_eofMode = atoi(optarg);
		   break;
		   
		case 'v':
			_params->m_verbosityMode = atoi(optarg);
		   break;
		   	
		default: 
		fprintf(stderr, "Usage: %s [-c create] [-d destroy] [-n numOfMsgs] [-e EOFtype] [-v verbosity] [-s speed] [-f filename]\n", _argv[0]);
		exit(EXIT_FAILURE);
	   }
	}
	
	if (1 == _argc)
	{
		_params->m_createMQFlag = 1;
		_params->m_deleteMQFlag = 0;
		_params->m_numOfMsgs = 5;
		_params->m_eofMode = 0;
		_params->m_verbosityMode = 1;
		_params->m_speed = 1000000;
		_params->m_ftokFilename = "SMQ";
	}
}


