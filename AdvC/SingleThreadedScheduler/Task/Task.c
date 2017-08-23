#include "Task.h"

typedef struct Task
{
	TaskFunction	m_task;
	void*		m_context;
	Time		m_nextTime;
	Time		m_interval;
};
