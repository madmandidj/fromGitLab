#ifndef __PERIODIC_EXECUTER_H__
#define __PERIODIC_EXECUTER_H__

#include <stdlib.h>
#include <time.h>

typedef int (*TaskFunction) (void* _context); 

typedef struct PE PE;

PE* 	PeriodicExecutor_Create		(const char* _name, clockid_t _clk_id);

void 	PeriodicExecutor_Destroy	(PE* _executor);

int 	PeriodicExecutor_Add		(PE* _executor, TaskFunction _taskFunc, void* _context, int _period_ms);

size_t 	PeriodicExecutor_Run		(PE* _executor);

size_t 	PeriodicExecutor_Pause		(PE* _executor);

#endif /* #ifndef __PERIODIC_EXECUTER_H__ */






