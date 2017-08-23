#ifndef __TASK_H__
#define __TASK_H__






Task* TaskCreate(Task _task, void* _context, size_t _period_ms, const clockid_t m_clockID);

void TaskDestroy(Task*);

void TaskCalculateNext(Task* _Task, const clockid_t m_clockID);

int	TaskExecute(Task*);

int	TaskCompare(Task*, Task*);

#endif /* #ifndef __TASK_H__ */
