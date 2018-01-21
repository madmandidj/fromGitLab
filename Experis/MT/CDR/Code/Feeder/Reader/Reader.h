#ifndef __READER_H__
#define __READER_H__
#include "../../CDRDataTypes/Record.h"
#include "../../Comms/Receiver/Receiver.h"
#include "../../Comms/Transmitter/Transmitter.h"
/** 
 *  @file Reader.h
 *
 *  @brief Reader will read cdr entries from cdr file and send to processor
 *
 *  @author Eyal Alon  (eyal171@yahoo.com)
 * 
 *  @bug Blasphemy 
*/



typedef struct Reader Reader;



/** 
 * @brief Create new Reader
 *
 * @param[in] _numOfThreads - number of reader threads. Each thread can simultaneously read 1 cdr and send to processor
 * 
 * @param[in] _cdrPath - cdr file path directory
 * 
 * @param[in] _trans - Transmitter instance
 * 
 * @param[in] _rcvr - Receiver instance
 *  
 * @return  pointer to allocated Reader instance
 *
 * @retval	NULL upon create fail
 *
 * @retval	!NULL upon create success
 */
Reader* ReaderCreate(unsigned int _numOfThreads, char* _cdrPath, Transmitter* _trans, Receiver* _rcvr);



/** 
 * @brief Destroy Reader
 *
 * @param[in] _reader - Reader instance to destroy
 * 
 * @return  void
 */
void ReaderDestroy(Reader* _reader);



/** 
 * @brief Run all readers
 *
 * @param[in] _reader - Reader instance to use for running. A thread for each reader are created here.
 * 
 * @return  Success/Fail
 * 
 * @retval  0 Fail when _reader == NULL or pthread_create fails
 * 
 * @retval  1 Success 
 */
int ReaderRun(Reader* _reader);



#endif /* #ifndef __READER_H__ */



