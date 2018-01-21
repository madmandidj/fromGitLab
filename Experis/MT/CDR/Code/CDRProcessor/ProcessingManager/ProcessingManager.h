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



typedef struct ProcMngrParams
{
	size_t m_numOfProcessors;
	size_t m_subHashSize;
	size_t m_opHashSize;
}ProcMngrParams;



/** 
 * @brief Get user input for processing manager variables
 *
 * @param[in] _argc - number of arguments in argv
 *
 * @param[in] _argv[] - user input values
 *
 * @param[in-out] _params[] - parameters object to store user values
 *  
 * @return  void
 */
void DoGetOpt(int _argc, char* _argv[], ProcMngrParams* _params);



/** TODO update this
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
ProcessingManager* ProcessingManagerCreate(ProcMngrParams _params);



/** 
 * @brief Destroy a ProcessingManager instance
 *
 * @param[in] _procMngr - ProcessingManager instance to destroy
 *  
 * @return  void
 */
void ProcessingManagerDestroy(ProcessingManager* _procMngr);



#endif /* #ifndef __PROCESSING_MANAGER_H__ */



