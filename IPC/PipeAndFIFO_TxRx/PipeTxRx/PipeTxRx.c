#define _POSIX_C_SOURCE 199309L 	/* siginfo_t */
#define _DEFAULT_SOURCE				/* usleep() */
#include <stdio.h>					/* printf() */
#include <sys/wait.h>				/* wait() */
#include <unistd.h>					/* fork(), pipe() */
#include <signal.h>					/* kill */ 
#include <limits.h>					/* PIPE_BUF */
#include <errno.h>					/* errno */
#include <string.h>					/* strerror() */
#include <stdlib.h>					/* malloc(), exit() */


#define ONE_SECOND_USEC 1000000
#define ERR_VAL -1


typedef struct Params
{
	size_t m_txCycles;
	size_t m_bufSize;
}Params;



static void DoGetOpt(int _argc, char* _argv[], size_t* _bufSize, size_t* _txCycles)
{
	int opt;
	
	while ((opt = getopt(_argc, _argv, "s:c:")) != -1) {
	   switch (opt) {
	   case 's':
		   *_bufSize = (size_t)atoi(optarg);
		   break;
	   case 'c':
		   *_txCycles = (size_t)atoi(optarg);
		   break;
	   default: 
		   fprintf(stderr, "Usage: %s [-s bufSize] [-n] txCycles\n", _argv[0]);
		   exit(EXIT_FAILURE);
	   }
	}
	
	if (1 == _argc)
	{
		*_txCycles = 2;
		*_bufSize = 10;
	}
   
	return;
}




static void CreatePipe(int* _pipefd, int* _pipeErr)
{
	if (ERR_VAL == (*_pipeErr = pipe(_pipefd)))
	{
		printf("pipe() ERROR: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
		/*TODO: how to test error from pipe() ?*/
	}
		
	return;
}






static void ServerRoutine(pid_t _pid, int* _pipefd, Params _params)
{
	char buf[PIPE_BUF];
	size_t curCycle;
	int curChar;
	/* int killErr; */
	
	/* Close server Rx */
	usleep(ONE_SECOND_USEC);
	close(_pipefd[0]);
	
	for(curCycle = 0; curCycle < _params.m_txCycles; ++curCycle)
	{
		for(curChar = 0; curChar < _params.m_bufSize; ++curChar)
		{
			buf[curChar] = (char) ((curChar + (int)curCycle) % 26 + 97);
		}
		buf[curChar + 1] = '\0';
		/* TODO: handle write errors: full pipe / broken pipe */
		write(_pipefd[1], buf, _params.m_bufSize);
		/*usleep(ONE_SECOND_USEC); */
	}
	
	usleep(ONE_SECOND_USEC);
	
	/* Close server Tx */
	close(_pipefd[1]);
	
	/*
	if (ERR_VAL == (killErr = kill(_pid, SIGKILL)))
	{
		
		printf("kill() ERROR: %s\n", strerror(errno));
	}
	*/
	wait(NULL);
	
	return;
}





static void ClientRoutine(pid_t _pid, int* _pipefd, Params _params)
{
	char buf[PIPE_BUF];	
	ssize_t numRead;
	
	/* Close client Tx */
	close(_pipefd[1]);
	
	for(;;)
	{
		/* TODO: handle read errors: empty pipe / broken pipe */
		/* usleep(ONE_SECOND_USEC); */
		numRead = read(_pipefd[0], &buf, _params.m_bufSize);
		if (numRead <= 0) 
		{
			break;
		}
		printf("%s\n", buf);
		/* usleep(ONE_SECOND_USEC); */
	}
	/* Close client Rx */
	close(_pipefd[0]);
	
	return;
}







int main(int argc, char* argv[])
{
	int pipefd[2];
	pid_t pid;
	int pipeErr;
	Params params;
	
	
	DoGetOpt(argc, argv, &params.m_bufSize, &params.m_txCycles);
	/*
	buf = CreateBuffer(params.m_bufSize);
	*/
	CreatePipe(pipefd, &pipeErr);
	
	pid = fork();
	
	if (pid > 0)
	{
		ServerRoutine(pid, pipefd, params);
	}

	if (pid == 0)
	{
		ClientRoutine(pid, pipefd, params);
	}
	
	return 0;
}





















