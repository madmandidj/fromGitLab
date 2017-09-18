#ifndef __NEW_FILE_WATCHER_H__
#define __NEW_FILE_WATCHER_H__



typedef struct NewFileWatcher NewFileWatcher;


NewFileWatcher* NewFileWatcherCreate();

void NewFileWatcherDestroy();

int NewFileWatcherRun(NewFileWatcher* _NewFileWatcher);

int	GetNewFilePath(char* _fileName);


#endif /*#ifndef __NEW_FILE_WATCHER_H__*/













