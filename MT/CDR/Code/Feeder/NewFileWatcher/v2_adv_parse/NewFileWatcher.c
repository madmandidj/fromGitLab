#include "NewFileWatcher.h"
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>


#define NEW_FILE_PATH "./NEW/"
#define WORKING_FILE_PATH "./WORKING/"
#define DONE_FILE_PATH "./DONE/"


struct NewFileWatcher
{
	unsigned int	m_systemMode;
};


/*NewFileWatcher* NewFileWatcherCreate()*/
/*{*/
/*	NewFileWatcher* newFileWatcher;*/
/*	*/
/*	newFileWatcher = malloc(sizeof(NewFileWatcher));*/
/*	if (!newFileWatcher)*/
/*	{*/
/*		return NULL;*/
/*	}*/
/*	*/
/*	newFileWatcher->m_systemMode = 1;*/
/*	*/
/*	return newFileWatcher;*/
/*}*/



static void* NewFileWatcherRoutine()
{
	struct dirent** nameList;
	int numOfFiles;
	char* fileName;
	char* fileExt;
	size_t index;
	char newFilePath[] = NEW_FILE_PATH;
	char workingFilePath[] = WORKING_FILE_PATH;
	char donePath[] = DONE_FILE_PATH;
	char oldFile[128];
	char newFile[128];

	numOfFiles = scandir(NEW_FILE_PATH, &nameList, NULL, NULL);
	
	if (numOfFiles < 0)
	{
		perror("scandir");
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
		
		fileExt = strtok(NULL, "");
		
		if (0 == strcmp(fileExt, "cdr"))
		{
			strcpy(oldFile, NEW_FILE_PATH);
			strcat(oldFile, fileName);
			strcat(oldFile, ".");
			strcat(oldFile, fileExt);
			
			strcpy(newFile, WORKING_FILE_PATH);
			strcat(newFile, fileName);
			strcat(newFile, ".");
			strcat(newFile, fileExt);
			
			printf("%s\n", oldFile);
			printf("%s\n", newFile);
			rename(oldFile, newFile);
			/* transmit message to feederManager */
		}
		
		
		printf("End of parse\n");
	}
	
	
	for (index = 0; index < numOfFiles; ++index)
	{
		free(nameList[index]);
	}
	free(nameList);
   
	
	return NULL;
}








int main()
{
	NewFileWatcherRoutine();
	
	return 0;
}













