#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "ArgVArgC.h"

int main(int argc, char* argv[])
{
	int i;
	int isAge;
	int isFName;
	int isNameFound = 0;
	int isAgeFound = 0;
	int nameInd;
	int ageInd;
	if (argc != 3)
	{
		printf("Invalid number of parameters\n");
		return 0;
	}	
	else
	{
		for (i = 1; i < argc; ++i)
		{
			if (isNameFound == 0)
			{
				isFName = IsFirstName(argv[i]);
				if (isFName == 1)
				{
					isNameFound = 1;
					nameInd = i;
				}
			}
			if (isAgeFound == 0)
			{
				isAge = IsAge(argv[i]);
				if (isAge > 0)
				{
					isAgeFound = 1;
					ageInd = i;
				}
			}
		}
	}
	if (isNameFound == 0 || isAgeFound == 0)
	{
		printf("One or both parameters are invalid\n");
	}
	else
	{
		printf("Name is: %s\n", argv[nameInd]);
		printf("Age is: %d\n", isAge);
	}
	return 0;
}
