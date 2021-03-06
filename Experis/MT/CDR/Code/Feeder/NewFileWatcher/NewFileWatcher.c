#define _POSIX_C_SOURCE 200809L
#include "NewFileWatcher.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#define NEW_FILE_PATH "./NewFileWatcher/NEW/"
#define WORKING_FILE_PATH "./NewFileWatcher/WORKING/"
#define DONE_FILE_PATH "./NewFileWatcher/DONE/"



int	GetNewFilePath(char* _fileName, pthread_mutex_t* _newFileMutex)
{
	struct dirent** nameList;
	int numOfFiles;
	char* fileName;
	char* fileExt;
	size_t index;
	char oldFile[128];
	char newFile[128];

	pthread_mutex_lock(_newFileMutex);
	
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
			strcpy(_fileName, nameList[index]->d_name);
			strcat(_fileName, ".cdr");
			
			strcpy(oldFile, NEW_FILE_PATH);
			strcat(oldFile, fileName);
			strcat(oldFile, ".");
			strcat(oldFile, fileExt);
			
			strcpy(newFile, WORKING_FILE_PATH);
			strcat(newFile, fileName);
			strcat(newFile, ".");
			strcat(newFile, fileExt);
			
			printf("New file detected: %s\n", newFile);
			rename(oldFile, newFile);
			for (index = 0; index < numOfFiles; ++index)
			{
				free(nameList[index]);
			}
			free(nameList);
			pthread_mutex_unlock(_newFileMutex);
			return 1;
		}
	}
	
	
	for (index = 0; index < numOfFiles; ++index)
	{
		free(nameList[index]);
	}
	free(nameList);
   
   pthread_mutex_unlock(_newFileMutex);
	return 0;
}




