#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>


void MySignalAction(int _sig, siginfo_t* _info, void* _ucontext)
{
	write(0, "1done\n", 6);
	usleep(1000000);
	kill(_info->si_pid, SIGUSR2);
	/* printf("pid: %d\n", _info->si_pid); */
	return;
}

void MySignalAction2(int _sig, siginfo_t* _info, void* _ucontext)
{
	write(0, "2done\n", 6);
	/* printf("pid: %d\n", _info->si_pid); */
	return;
}


int main()
{
	
	siginfo_t si;
	struct sigaction sa1;
	struct sigaction sa2;
	char s[200];
	int n;
	
	sa1.sa_flags = SA_SIGINFO;
	sa1.sa_sigaction = MySignalAction;	
	
	sa2.sa_flags = SA_SIGINFO;
	sa2.sa_sigaction = MySignalAction2;
	
	sigaction(SIGUSR1, &sa1, NULL);
	sigaction(SIGUSR2, &sa2, NULL);

	n = fork();
	
	
	
	if (n > 0)
	{
		usleep(1000000);
		kill(n, SIGUSR1);
		pause();
		printf("father awake\n");
	}
	if (n == 0)
	{
		pause();
		printf("son awake\n");
	}
	/*
	printf("Enter a string:\n");
    if (fgets(s, sizeof s, stdin) == NULL)
        perror("fgets");
    else 
        printf("You entered: %s\n", s);
	*/
	
	return 0;
}



















