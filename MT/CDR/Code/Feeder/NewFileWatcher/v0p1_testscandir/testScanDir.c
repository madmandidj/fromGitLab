#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

/*int scandir(const char *dirp, struct dirent ***namelist, int (*filter)(const struct dirent *), int (*compar)(const struct dirent **, const struct dirent **)); */



int main()
{
	struct dirent** nameList;
	int numOfFiles;
	char* fileName;
	char* fileExt;
	size_t index;

	/*   n = scandir(".", &namelist, NULL, alphasort);*/
	numOfFiles = scandir(".", &nameList, NULL, NULL);
	
	if (numOfFiles < 0)
	{
		perror("scandir");
	}
	
	
	for (index = 0; index < numOfFiles; ++index)
	{
		printf("%s\n", nameList[index]->d_name);
	}
	
	
	for (index = 0; index < numOfFiles; ++index)
	{
		fileName = strtok(nameList[index]->d_name, ".");
		if (NULL == fileName || 0 == strlen(fileName))
		{
			while (NULL != fileName)
			{
				fileName = strtok(NULL, ".");
			}
			continue;
		}
		printf("fileName = %s\n", fileName);
		
		fileExt = strtok(NULL, "");
		printf("fileExt = %s\n", fileExt);
		printf("End of parse\n");
	}
	
	
	for (index = 0; index < numOfFiles; ++index)
	{
		free(nameList[index]);
	}
	free(nameList);
	
	
	
	

	return 0;
   
}

