#include "DataGenerator.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 10000






int main(int argc, char* argv[])
{
	Params params;
	
/*	srand((unsigned int)time(NULL));*/
	
	DoGetOpt(argc, argv, &params);
	
	GenerateCDRFile(params.m_numOfRecords);
	
	return 0;
}


