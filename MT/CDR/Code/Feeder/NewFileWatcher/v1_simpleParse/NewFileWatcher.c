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


/*static void* NewFileWatcherRoutine(NewFileWatcher* _newFileWatcher)*/
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
		printf("%s\n", nameList[index]->d_name);
	}
	
	
	for (index = 0; index < numOfFiles; ++index)
	{
/*		strcpy(oldFile, "");*/
/*		strcpy(newFile, "");*/
		fileName = strtok(nameList[index]->d_name, ".");
		if (NULL == fileName || 0 == strlen(fileName))
		{
			while (NULL != fileName)
			{
				fileName = strtok(NULL, ".");
			}
			continue;
		}
/*		printf("fileName = %s\n", fileName);*/
		
		fileExt = strtok(NULL, "");
/*		printf("fileExt = %s\n", fileExt);*/
		
		if (0 == strcmp(fileExt, "cdr"))
		{
			strcpy(oldFile, NEW_FILE_PATH);
			strcat(oldFile, fileName);
			strcat(oldFile, ".");
			strcat(oldFile, fileExt);
			
/*			strcat(newFilePath ,nameList[index]->d_name);*/
/*			strcat(WORKING_FILE_PATH ,nameList[index]->d_name);*/
/*			rename(cdr)*/
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













