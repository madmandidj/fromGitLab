#ifndef __NEW_FILE_WATCHER_H__
#define __NEW_FILE_WATCHER_H__
#include <pthread.h>



/** 
 *  @file NewFileWatcher.h
 *
 *  @brief The NewFileWatcher retrieves the name of .cdr files within the relevant directory
 *
 *  @author Eyal Alon  (eyal171@yahoo.com)
 * 
 *  @bug Blasphemy 
*/



/** 
 * @brief Get new cdr file name
 *
 * @param[in-out] _fileName - string to store found cdr filename (e.g. upon success "cdrfile.cdr")
 *
 * @param[in] _newFileMutex - mutex to ensure that only 1 thread can access file names at a given time
 * 
 * @return  File found?
 *
 * @retval  0 file not found
 *
 * @retval  1 file found
 */
int	GetNewFilePath(char* _fileName, pthread_mutex_t* _newFileMutex);



#endif /*#ifndef __NEW_FILE_WATCHER_H__*/




