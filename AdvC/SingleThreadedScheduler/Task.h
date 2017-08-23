#ifndef __TASK_H__
#define __TASK_H__

typedef struct Task Task


Task* TaskCreate(Task _task, void* _context, size_t _period_ms, const clockid_t m_clockID);

void TaskDestroy(Task* _task);

void TaskCalculateNext(Task* _Task, const clockid_t m_clockID);

int	TaskExecute(Task* _task);

int	TaskCompare(Task* _task1, Task* _task2);

#endif /* #ifndef __TASK_H__ */
