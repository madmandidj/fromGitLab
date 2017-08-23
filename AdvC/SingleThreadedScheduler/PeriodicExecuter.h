#ifndef __PERIODIC_EXECUTER_H__
#define __PERIODIC_EXECUTER_H__


typedef int (*TaskFunction) (void* _context); 


PeriodicExecutor* PeriodicExecutorCreate(const char* _name, clockid_t ​_clk_id);

void PeriodicExecutorDestroy(PeriodicExecutor* _executor);

int PeriodicExecutorAdd(PeriodicExecutor* _executor, TaskFunction _task, void* _context, int _period_ms);

size_t PeriodicExecutorRun(PeriodicExecutor* _executor);

size_t PeriodicExecutorPause(PeriodicExecutor* _executor);

#endif /* #ifndef __PERIODIC_EXECUTER_H__ */






