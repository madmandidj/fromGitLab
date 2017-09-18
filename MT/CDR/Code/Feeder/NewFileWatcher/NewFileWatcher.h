#ifndef __NEW_FILE_WATCHER_H__
#define __NEW_FILE_WATCHER_H__

#include <pthread.h>


typedef struct NewFileWatcher NewFileWatcher;


NewFileWatcher* NewFileWatcherCreate();

void NewFileWatcherDestroy();

int NewFileWatcherRun(NewFileWatcher* _NewFileWatcher);

int	GetNewFilePath(char* _fileName, pthread_mutex_t* _newFileMutex);


#endif /*#ifndef __NEW_FILE_WATCHER_H__*/













