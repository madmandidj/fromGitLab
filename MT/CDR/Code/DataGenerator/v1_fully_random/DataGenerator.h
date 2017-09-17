#ifndef __DATA_GENERATOR_H__
#define __DATA_GENERATOR_H__

#include "../CDRDataTypes/Record.h"
#include "../CDRDataTypes/Subscriber.h"
#include "../CDRDataTypes/Operator.h"


void GenerateRecord(Record* _recordPtr);

void GenerateSubscriber(Subscriber* _subPtr);

void GenerateOperator(Operator* _opPtr);

void GenerateCDRFile();




#endif /*#ifndef __RECORD_GENERATOR_H__*/



