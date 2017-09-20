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



/** 
 * @brief Get user input for Data generator variables
 *
 * @param[in] _argc - number of arguments in argv
 *
 * @param[in] _argv[] - user input values
 *
 * @param[in-out] _params - parameters object to store user values
 *  
 * @return  void
 */
void DoGetOpt(int _argc, char* _argv[], Params* _params);



void GenerateCDRFile(int _numOfRecords);



#endif /*#ifndef __RECORD_GENERATOR_H__*/



