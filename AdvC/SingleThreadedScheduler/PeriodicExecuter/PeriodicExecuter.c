#include "Heap.h"
#include "PeriodicExecuter.h"
#include <stdlib.h>

typedef Heap PriorityQueue;

typedef struct PeriodicExecutor
{
	PriorityQueue*	m_priorityQ;
	size_t		m_runCycles;
	int		m_pauseRequest;
	const char*	m_name;
	clockid_t	m_clockID;
};
