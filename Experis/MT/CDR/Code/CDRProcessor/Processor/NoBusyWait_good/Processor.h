#ifndef __PROCESSOR_H__
#define __PROCESSOR_H__
#include "../Accumulator/Accumulator.h"
#include "../../Comms/Receiver/Receiver.h"
#include "../../CDRDataTypes/Record.h"
#include "../../CDRDataTypes/Operator.h"
#include "../../CDRDataTypes/Subscriber.h"
/** 
 *  @file Processor.h
 *
 *  @brief Processor receives formatted records from feeder, parse into subscriber and operator, then call accumulator to store
 *
 *  @author Eyal Alon  (eyal171@yahoo.com)
 * 
 *  @bug Blasphemy 
*/



typedef struct Processor Processor;



/** 
 * @brief Create new Processor
 *
 * @param[in] _accum - Accumulator instance to be used to Processor
 *
 * @param[in] _rcvr - Receiver instance to be used by Processor
 *
 * @param[in] _numOfThreads - Number of processor threads to create. Each processor thread can receive record, parse, and store independantly
 *  
 * @return  pointer to allocated Processor instance
 *
 * @retval	NULL upon create fail
 *
 * @retval	!NULL upon create success
 */
Processor* 		ProcessorCreate(Accumulator* _accum, Receiver* _rcvr, unsigned int _numOfThreads);



/** 
 * @brief Destroy Processor instance
 *
 * @param[in] _processor - Processor instance to destroy
 *  
 * @return  void
 */
void			ProcessorDestroy(Processor* _processor);



/** 
 * @brief Run processors
 *
 * @param[in] _processor - Processor instance to use for running
 *  
 * @return  Success ?
 *
 * @retval	0 if fail - _proc == NULL || pthread_create failed
 *
 * @retval	1 if success
 */
int 			ProcessorRun(Processor* _proc);



#endif /* #ifndef __PROCESSOR_H__ */








