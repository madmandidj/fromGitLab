#ifndef __HASHSET_H__
#define __HASHSET_H__
/*
Filename: 		HashSet.h 
Description:	Contains HashSet API
Created: 		19/07/17
Created by:		Eyal Alon
Last modified: 	29/07/17
Modified by:	Eyal Alon
*/
#include "ADTDefs.h"
#include <stdlib.h>

/*
TODO:
* Add description of Hash struct
* Remove redundant ERR types: ERR_HASH_FULL should be ERR_OVERFLOW
*/

typedef struct Hash Hash;

/*
Desc:	Create new Hash instance	
In:		size_t original size of hash		
Out:	Hash*
Err: 	NULL
*/
Hash* 	HashCreate(const size_t _size);
/*
Desc:	Destroy Hash instance	
In:		Hash*		
Out:	void
Err: 	NA. Double-free protection
*/
void 	HashDestroy(Hash* _hash);
/*
Desc:	Insert data to Hash	
In:		Hash*, integer value to insert		
Out:	ERR_OK,  ERR_HASH_FULL, ERR_VAL_EXISTS
Err: 	ERR_NOT_INITIALIZED
*/
ADTErr	HashInsert(Hash* _hash, int _data);
/*
Desc:	Remove data from Hash	
In:		Hash*, integer value to remove		
Out:	ERR_OK, ERR_UNDERFLOW, ERR_VAL_EXISTS
Err: 	ERR_NOT_INITIALIZED
*/
ADTErr	HashRemove(Hash* _hash, int _data);
/*
Desc:	Find if integer value is in hash	
In:		Hash*, integer value to find		
Out:	1 if found. 0 if not found.
Err: 	0
*/
int 	HashIsFound(const Hash* _hash, int _data);
/*
Desc:	Get original size of hash	
In:		Hash*		
Out:	size_t size
Err: 	0
*/
size_t 	HashCapacity(const Hash* _hash);
/*
Desc:	Get average number of collisions (total collisions / number of insertions)	
In:		Hash*		
Out:	size_t size
Err: 	0
*/
double	HashAverageCollisions(const Hash* _hash);
/*
Desc:	Get maximum number of collisions	
In:		Hash*		
Out:	size_t size
Err: 	0
*/
size_t	HashMaxCollisions(const Hash* _hash);
/*
Desc:	Print the hash
In:		Hash*		
Out:	NA
Err: 	NA 
*/
void	HashPrint(Hash* _hash);

#endif /* #ifndef __HASHSET_H__ */
