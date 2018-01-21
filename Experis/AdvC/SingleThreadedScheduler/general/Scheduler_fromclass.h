/*************************/
	/*STRUCTURES*/
/*************************/

typedef Heap PriorityQueue;

typedef struct PeriodicExecutor
{
	PriorityQueue*	m_priorityQ;
	size_t		m_runCycles;
	int		m_pauseRequest;
	const char*	m_name;
	clockid_t	m_clockID;
};

typedef int (*TaskFunction) (void* _context); 

typedef struct Task
{
	TaskFunction	m_task;
	void*		m_context;
	Time		m_nextTime;
	Time		m_interval;
};

/*************************/
/*SCHEDULER API FUNCTIONS*/
/*************************/
/**
 * @brief:
 * @openissues:	what is name? how do u actually use _clck_id?
 */
PeriodicExecutor* PeriodicExecutorCreate(const char* _name,
clockid_t ​_clk_id);

void PeriodicExecutorDestroy(PeriodicExecutor* _executor);

/**
 */
int PeriodicExecutorAdd(PeriodicExecutor* _executor, TaskFunction _task, void* _context, int _period_ms);

size_t PeriodicExecutorRun(PeriodicExecutor* _executor);

size_t PeriodicExecutorPause(PeriodicExecutor* _executor);

/*************************/
/*Task API FUNCTIONS*/
/*************************/

Task*	TaskCreate(Task _task, void* _context, size_t _period_ms, const clockid_t m_clockID);

void	TaskDestroy(Task*);

void	TaskCalculateNext(Task* _Task, const clockid_t m_clockID);

int	TaskExecute(Task*);

int	TaskCompare(Task*, Task*);

/*************************/
/*TIME API FUNCTIONS*/
/*************************/

typedef struct Time Time;

struct Time
{
	struct timespec	m_time;
};

Time*	TimeCreate(int _milliSecs)

Time*	TimeGetCurrent(const clockid_t _clockID)

void	TimeDestroy(Time*);

int	TimeCompare(const Time*, const Time*)

void	TimeSleepUntil(const Time*)

void	TimeAdd(Time* _result, const Time* _added);
	
	










