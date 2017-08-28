#define _POSIX_C_SOURCE 199309L 	/* siginfo_t */
#define _DEFAULT_SOURCE				/* usleep()  _BSD_SOURCE ---- deprecated*/
#include <stdio.h>					/* printf() */
#include <unistd.h>					/* fork() */
#include <signal.h>					/* sigaction */
#include <sys/types.h>				/*  pid_t */	
#include <time.h>					/*  timespec */
#include <stdlib.h>					/* exit() */
#include <assert.h>

/****************************
"unknown type name ‘siginfo_t’"
*****************************
These compile and run:
#define _GNU_SOURCE
#define _POSIX_C_SOURCE 199309L

Thise doesnt:
#define _XOPEN_SOURCE


 
TODO:
Read more in errno.h and about errno
man7.org/linux/man-pages/man7/signal-safety.7.html  - async signal safe functions as required by POSIX.1
man7.org/linux/man-pages/man2/sigaction.2.html		- sigaction
*/

#define ONE_SECOND_USEC 1000000


static void MyAction(int _sig, siginfo_t* _info, void* _ucontext)
{
	write(0, "*** MyAction done\n", 19);
	
	return;
}







static void ParentRoutine(const pid_t _pid)
{
		printf("* parent going to sleep\n");
		usleep(ONE_SECOND_USEC);
		/* 
		Send SIGUSR1 signal to child 
		*/
		printf("* parent sending signal to child\n");
		kill(_pid, SIGUSR1);
		printf("* parent pausing\n");
		pause();
		printf("* parent woke up\n");
		return;
}






static void ChildRoutine(const pid_t _pid)
{
		printf("** child pausing\n");
		pause();
		
		printf("** child going to sleep\n");
		usleep(ONE_SECOND_USEC);
		
		printf("** child sending signal to parent\n");
		kill(getppid(), SIGUSR1);
		
		printf("** child woke up\n");
		return;
}






static void PrintElapsedTime(char* _string, struct timespec* _startTime)
{
	struct timespec curTime;
	assert(_startTime);

	clock_gettime(CLOCK_REALTIME, &(curTime));
	printf(_string, curTime.tv_sec - _startTime->tv_sec, (curTime.tv_nsec - _startTime->tv_nsec) / 1000000);
	return;
}







static void SigActionInit(struct sigaction* sa)
{
	/*
	If SA_SIGINFO flag is set, then the signal-catching function prototype is: void func(int, siginfo_t, void*);
	If SA_SIGINFO flag is not set, then the signal-catching function proto is: void func(int signo); , using sa.sa_handler
	*/
	sa->sa_flags = SA_SIGINFO;
	sa->sa_sigaction = MyAction;	
	
	/* 
	Specify the action to be associated with SIGUSR1, and check for error ( == -1) 
	*/
	if (-1 == sigaction(SIGUSR1, &(*sa), NULL))
	{
		perror("sigaction");
		exit(1);
	}
	
	
	return;
}







int main()
{
	struct sigaction sa;
	pid_t pid;
	struct timespec startTime;
	
	/*
	Get program start time. **Currently used only for monitoring/debug
	*/
	clock_gettime(CLOCK_REALTIME, &(startTime));
	/*
	Initialize the signal action variable, and specify associated action
	*/
	SigActionInit(&sa);
		
	pid = fork();
	
	if (pid > 0)
	{
		
		PrintElapsedTime("* \tparent start: \t%lu s, %lu ns\n", &startTime);
		
		ParentRoutine(pid);
		
		PrintElapsedTime("* \tparent end: \t%lu s, %lu ns\n", &startTime);
	}
	
	if (pid == 0)
	{
		PrintElapsedTime("* \tchild start: \t%lu s, %lu ns\n", &startTime);
		
		ChildRoutine(pid);
		
		PrintElapsedTime("* \tchild end: \t%lu s, %lu ns\n", &startTime);
	}

	return 0;
}



















