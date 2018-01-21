#ifndef __ACCUMULATOR_H__
#define __ACCUMULATOR_H__
#include "../../CDRDataTypes/Operator.h"
#include "../../CDRDataTypes/Subscriber.h"
#include <stddef.h>
/** 
 *  @file Accumulator.h
 *
 *  @brief Accumulator is responsible for inserting, updating and retrieving container elements
 *
 *  @author Eyal Alon  (eyal171@yahoo.com)
 * 
 *  @bug Blasphemy 
*/



typedef struct Accumulator Accumulator;



/** TODO update this
 * @brief Create new Accumulator instance
 *  
 * @return  pointer to allocated Accumulator instance
 *
 * @retval	NULL upon create fail
 *
 * @retval	!NULL upon create success
 */
Accumulator* AccumulatorCreate(size_t _subHashSize, size_t _opHashSize);



/** 
 * @brief Destroy Accumulator instance
 *
 * @param[in] _accum - Accumulator instance to destroy
 *  
 * @return  void
 */
void AccumulatorDestroy(Accumulator* _accum); 



/** 
 * @brief Get Subscriber
 *
 * @param[in] _accum - Accumulator instance to be used to get subscriber
 *
 * @param[in] _key - subscriber MSISDN
 *
 * @param[in-out] _subFound - Address of Subscriber pointer to hold address of retrieved Subscriber
 *  
 * @return  Success ?
 *
 * @retval	0 if fail - NULL == _accum || NULL == _key || NULL == _subFound, or if Subscriber not found
 *
 * @retval	1 if success
 */
int AccumulatorGetSubscriber(Accumulator* _accum, char* _key, Subscriber** _subFound);



/** 
 * @brief Get Operator
 *
 * @param[in] _accum - Accumulator instance to be used to get subscriber
 *
 * @param[in] _key - subscriber MSISDN
 *
 * @param[in-out] _operFound - Address of Operator pointer to hold address of retrieved Operator
 *  
 * @return  Success ?
 *
 * @retval	0 if fail - NULL == _accum || NULL == _key || NULL == _subFound, or if Operator not found
 *
 * @retval	1 if success
 */
int AccumulatorGetOperator(Accumulator* _accum, char* _key, Operator** _operFound);



/** 
 * @brief Update Subscriber
 *
 * @param[in] _accum - Accumulator instance to be used to update/insert subscriber
 *
 * @param[in] _sub - Subscriber to insert or update. If no subscriber with identical MSISDN is found, a new one is inserted
 *  
 * @return  Success ?
 *
 * @retval	0 if fail - NULL == _accum || NULL == _sub
 *
 * @retval	1 if success
 */
int AccumulatorUpdateSubscriber(Accumulator* _accum, Subscriber* _sub);



/** 
 * @brief Update Operator
 *
 * @param[in] _accum - Accumulator instance to be used to update/insert operator
 *
 * @param[in] _oper - Operator to insert or update. If no operator with identical MSISDN is found, a new one is inserted
 *  
 * @return  Success ?
 *
 * @retval	0 if fail - NULL == _accum || NULL == _oper
 *
 * @retval	1 if success
 */
int AccumulatorUpdateOperator(Accumulator* _accum, Operator* _oper);



/** 
 * @brief Print all subscribers
 *
 * @param[in] _accum - Accumulator instance
 *  
 * @return number of unique subscribers
 */
size_t AccumulatorPrintAllSubscribers(Accumulator* _accum);




#endif /* #ifndef __ACCUMULATOR_H__ */





