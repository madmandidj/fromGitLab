#ifndef __FEEDER_MANAGER_H__
#define __FEEDER_MANAGER_H__
#include "../../CDRDataTypes/Record.h"
#include "../../Comms/MsgQueue/MsgType.h"



/** 
 *  @file FeederManager.h
 *
 *  @brief FeederManager creates Reader, Transmitter and Receiver, and then runs the Reader
 *
 *  @author Eyal Alon  (eyal171@yahoo.com)
 * 
 *  @bug Blasphemy 
*/



typedef struct FeederManager FeederManager;

/** 
 * @brief Create new FeederManager
 *
 * @param[in] _numOfReaders - number of reader threads. Each thread can simultaneously read 1 cdr and send to processor
 * 
 * @return  pointer to allocated FeederManager instance
 *
 * @retval	NULL upon create fail
 *
 * @retval	!NULL upon create success
 */
FeederManager* FeederManagerCreate(size_t _numOfReaders);



/** 
 * @brief Destroy FeederManager
 *
 * @param[in] _feederManager - FeederManager instance to destroy
 * 
 * @return  void
 */
void FeederManagerDestroy(FeederManager* _feederManager);



#endif /* #ifndef __FEEDER_MANAGER_H__ */

