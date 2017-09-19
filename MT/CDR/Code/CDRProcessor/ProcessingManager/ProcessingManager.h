#ifndef __PROCESSING_MANAGER_H__
#define __PROCESSING_MANAGER_H__
/** 
 *  @file ProcessingManager.h
 *
 *  @brief ProcessingManager creates a processor, accumulator and receiver, then calls ProcessorRun
 *
 *  @author Eyal Alon  (eyal171@yahoo.com)
 * 
 *  @bug Blasphemy 
*/



typedef struct ProcessingManager ProcessingManager;



/** 
 * @brief Create new ProcessingManager
 *
 * @param[in] _numOfProcThreads - Number of processor threads to create
 *  
 * @return  pointer to allocated ProcessingManager instance
 *
 * @retval	NULL upon create fail
 *
 * @retval	!NULL upon create success
 */
ProcessingManager* ProcessingManagerCreate(size_t _numOfProcThreads);



/** 
 * @brief Destroy a ProcessingManager instance
 *
 * @param[in] _procMngr - ProcessingManager instance to destroy
 *  
 * @return  void
 */
void ProcessingManagerDestroy(ProcessingManager* _procMngr);



#endif /* #ifndef __PROCESSING_MANAGER_H__ */



