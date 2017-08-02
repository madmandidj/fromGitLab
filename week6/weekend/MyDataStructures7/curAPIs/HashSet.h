#ifndef __HASHSET_H__
#define __HASHSET_H__
/*
Filename: 		HashSet.h 
Description:	Contains HashSet API given by Ronny.
Created: 		19/07/17
Created by:		Eyal Alon
Last modified: 	28/07/17
Modified by:	Eyal Alon
*/
#define MAGIC_NUM 17
#define NOT_MAGIC_NUM 99
#include "ADTDefs.h"
#include <stdlib.h>


typedef struct Hash Hash;

/*
Desc:		
In:				
Out:	
Err: 	
*/
Hash* 	HashCreate(const size_t _size);
void 	HashDestroy(Hash* _hash);
ADTErr	HashInsert(Hash* _hash, int _data);
ADTErr	HashRemove(Hash* _hash, int _data);
int 	HashIsFound(const Hash* _hash, int _data);
size_t 	HashCapacity(const Hash* _hash);
double	HashAverageCollisions(const Hash* _hash);
size_t	HashMaxCollisions(const Hash* _hash);
void	HashPrint(Hash* _hash);

#endif /* #ifndef __HASHSET_H__ */
