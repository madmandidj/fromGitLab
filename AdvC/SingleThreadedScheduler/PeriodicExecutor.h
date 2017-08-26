#ifndef __PERIODIC_EXECUTOR_H__
#define __PERIODIC_EXECUTOR_H__

#include <stdlib.h>
#include <time.h>

/** 
 *  @file PeriodicExecutor.h
 *  @brief The Periodic executor is a facility that can execute periodic recurrent tasks. This facility behaves like a single threaded scheduler for running repeating tasks
 *	
 *  @details  The Periodic executor will execute tasks added to it. Each task can be executed more than one time. The period of the recurrence is set per task and each task can specify if it needs more execution cycles or it has finished.
 *
 *  @author Eyal Alon  (eyal171@yahoo.com)
 * 
 *  @bug Zero bug approach 
 */
 
 
 
 typedef struct PE PE;




/** 
 * @brief User Task Functions prototype
 *
 * @param[in] _context - 1. int*: used as num of task repetitions
 						2. PE*: used to call the PeriodicExecutor_Pause function from within taskFunc
 						3. void*: used for additional functionality
 * 
 * @retval 0 Task will be called again afer interval has passed
 *
 * @retval !0 Task will be removed from executor 
 */
typedef int (*TaskFunction) (void* _context); 





/** 
 * @brief Create a Periodic Executor
 *
 * @param[in] _name - name of Logger config file: e.g. "loggerconfig.txt"
 *
 * @param[in] clockid_t - recommended value: CLOCK_REALTIME
 * 
 * @return  Periodic executor pointer
 *
 * @warning NULL returned of creation failed
 */
PE* 	PeriodicExecutor_Create		(const char* _name, clockid_t _clk_id);





/** 
 * @brief Destroy a Periodic Executor
 *
 * @param[in] _executor - Periodic executor pointer to be destroyed
 * 
 * @return  void
 */
void 	PeriodicExecutor_Destroy	(PE* _executor);





/** 
TODO: continue from here
 * @brief Create a Periodic Executor
 *
 * @param[in] _executor - name of Logger config file: e.g. "loggerconfig.txt"
 *
 * @param[in] clockid_t - recommended value: CLOCK_REALTIME
 * 
 * @return  Periodic executor pointer
 *
 * @warning NULL returned of creation failed
 */
int 	PeriodicExecutor_Add		(PE* _executor, TaskFunction _taskFunc, void* _context, int _period_ms);

size_t 	PeriodicExecutor_Run		(PE* _executor);

size_t 	PeriodicExecutor_Pause		(PE* _executor);

#endif /* #ifndef __PERIODIC_EXECUTOR_H__ */






