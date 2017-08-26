#ifndef __TASK_H__
#define __TASK_H__

#include <time.h>
#include <sys/types.h>
typedef struct Task Task;
typedef int (*TaskFunction)(void* _context);

Task* TaskCreate(TaskFunction _taskFunc, void* _context, int _periodMillis, const clockid_t _clockID);

void TaskDestroy(Task* _task);

void TaskGetNextRunTime(Task* _task, const clockid_t _clockID);

int	TaskExecute(Task* _task, const clockid_t _clockID);

int	TaskCompare(Task* _task1, Task* _task2);

#endif /* #ifndef __TASK_H__ */
