#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


static void ReadCommand(char* token, char** params, char* str)
{
	size_t numOfTokens = 0;
	fgets(str, 128, stdin);
	token = strtok(str, " \n");
	while (token != NULL)
	{
		params[numOfTokens] = token;
		token = strtok(NULL, " \n");
		++numOfTokens;
	}
	params[numOfTokens] = NULL;
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
		if (pid < 0)
		{
			return 1;
		}
		if (pid > 0)
		{
			waitpid(-1, &status, 0);
		}
		else
		{
			execvp(params[0], params);
			printf("Unknown command\n");
			return 1;
		}
	}
	return 1;
}


