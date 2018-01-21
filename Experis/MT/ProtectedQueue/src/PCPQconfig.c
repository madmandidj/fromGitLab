
#include "../inc/PCPQconfig.h"
#include <unistd.h>
#include <getopt.h>
#include <stdio.h>

struct Params
{
	size_t m_numOfProds;
	size_t m_numOfCons;
	size_t m_numOfMsgs;
	size_t m_speed;
	size_t m_verbosity;
};



Params* CreateParams()
{
	Params* params;
	
	params = malloc(sizeof(Params));
	
	if(NULL == params)
	{
		return NULL;
	}
	
	return params;
}



void DestroyParams(Params* _params)
{
	if (NULL == _params)
	{
		return;
	}
	
	free (_params);
	return;
}



void DoPCPQconfig(int _argc, char* _argv[], Params* _params)
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
			_params->m_numOfProds = (size_t)atoi(optarg);
		   break;
		   
		case 'c':
			_params->m_numOfCons = (size_t)atoi(optarg);
		   break;
		   
		case 'n':
			_params->m_numOfMsgs = (size_t)atoi(optarg);
		   break;
		   
		case 's':
			_params->m_speed = (size_t)atoi(optarg);
		   break;
		   
		case 'v':
			_params->m_verbosity = (size_t)atoi(optarg);
		   break;
		   	
		default: 
		fprintf(stderr, "Usage: %s [-p Producers #] [-c Consumers #] [-n Messages #] [-s Speed (us)] [-v verbosity (0/1)] \n", _argv[0]);
		exit(EXIT_FAILURE);
	   }
	}

	return;
}



size_t GetNumOfProds(Params* _params)
{
	return _params->m_numOfProds;
}



size_t GetNumOfCons(Params* _params)
{
	return _params->m_numOfCons;
}



size_t GetNumOfMsgs(Params* _params)
{
	return _params->m_numOfMsgs;
}



size_t GetSpeed(Params* _params)
{
	return _params->m_speed;
}



size_t GetVerbosity(Params* _params)
{
	return _params->m_verbosity;
}








