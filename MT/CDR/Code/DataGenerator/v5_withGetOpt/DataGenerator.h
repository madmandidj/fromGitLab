#ifndef __DATA_GENERATOR_H__
#define __DATA_GENERATOR_H__

#include "../CDRDataTypes/Record.h"
#include "../CDRDataTypes/Subscriber.h"
#include "../CDRDataTypes/Operator.h"
#include <stdlib.h>


typedef struct Params Params;

struct Params
{
	int m_numOfRecords;
};


void DoGetOpt(int _argc, char* _argv[], Params* _params);

void GenerateRecord(Record* _recordPtr);

void GenerateSubscriber(Subscriber* _subPtr);

void GenerateOperator(Operator* _opPtr);

void GenerateCDRFile(int _numOfRecords);




#endif /*#ifndef __RECORD_GENERATOR_H__*/



