#include <stdio.h>
#include <unistd.h>


int g_var = 0;


int main()
{
	int l_var = 0;
	int i;
	int fatherRep = 5;
	int sonRep = 5;
	int n;
	n = fork();
	if (n < 0)
	{
		/* ERROR */
	}
	else if (n > 0)
	{
		/* Parent code */
		for (i = 0; i < fatherRep; ++i)
		{
			++g_var;
			printf("Father g_var: %d\n", g_var);
			++l_var;
			printf("Father l_var: %d\n", g_var);
			sleep(5);
		}
		printf("\n");
	}
	else
	{
		/* Child code */
		for (i = 0; i < fatherRep; ++i)
		{
			--g_var;
			printf("Child g_var: %d\n", g_var);
			--l_var;
			printf("Child l_var: %d\n", g_var);
			sleep(1);
		}
		printf("\n");
	}
	return 1;
}
