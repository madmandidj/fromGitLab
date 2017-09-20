#ifndef __DATA_GENERATOR_H__
#define __DATA_GENERATOR_H__

#include "../CDRDataTypes/Record.h"
#include "../CDRDataTypes/Subscriber.h"
#include "../CDRDataTypes/Operator.h"
#include <stdlib.h>


typedef struct DataGenParams
{
	int m_numOfRecords;
	size_t m_subMsisdnLength;
	size_t m_opMsisdnLength;
}DataGenParams;



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
void DoGetOpt(int _argc, char* _argv[], DataGenParams* _params);



void GenerateCDRFile(DataGenParams _params);



#endif /*#ifndef __RECORD_GENERATOR_H__*/



