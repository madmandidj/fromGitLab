#ifndef __TASK_H__
#define __TASK_H__

#include <time.h>
#include <sys/types.h>

/*
TODO: Add documentation for this module and functions
*/

typedef struct Task Task;
typedef int (*RunFunction)(void* _context);

Task* TaskCreate(RunFunction _taskFunc, void* _context, int _periodMillis, const clockid_t _clockID);

void TaskDestroy(Task* _task);

void TaskGetNextRunTime(Task* _task, const clockid_t _clockID);

int	TaskExecute(Task* _task, const clockid_t _clockID);

int	TaskCompare(Task* _task1, Task* _task2);

#endif /* #ifndef __TASK_H__ */
