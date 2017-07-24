#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


static void ReadCommand(char* _token, char** _params, char* _str)
{
	size_t numOfTokens = 0;
	const char delimiters[] = " \n";
	fgets(_str, 128, stdin);
	_token = strtok(_str, delimiters);
	while (_token != NULL)
	{
		_params[numOfTokens] = _token;
		_token = strtok(NULL, delimiters);
		++numOfTokens;
	}
	_params[numOfTokens] = NULL;
	return;
}

int main()
{
	char str[128];
	char* params[50];
	char* token = NULL;
	int status;
	int pid;
	while(1)
	{
		printf("EyalsShell:");
		ReadCommand(token, params, str);
		if (!strcmp("exit", params[0]))
		{
			printf("Goodbye! :-)\n");
			return 1;
		}
		pid = fork();
		/*
		Fork failed
		*/
		if (pid < 0)
		{
			return 1;
		}
		/*
		Father
		*/
		if (pid > 0)
		{
			waitpid(-1, &status, 0);
			/* can use status to determine status of child */
		}
		/*
		Child
		*/
		else
		{
			execvp(params[0], params);
			printf("Unknown command\n");
			return 1;
		}
	}
	return 1;
}


