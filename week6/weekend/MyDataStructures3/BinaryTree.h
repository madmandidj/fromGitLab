#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__
/*
Filename: 		BinaryTree.h 
Description:	Contains binary tree API given by Izik.
Created: 		17/07/17
Created by:		Eyal Alon
Last modified: 	28/07/17
Modified by:	Eyal Alon
*/

/* TODO: move magic num to c file */
#define MAGIC_NUM 17

#include <stdlib.h>
#include "ADTDefs.h"

typedef struct Tree Tree;

typedef enum
{
	PRE_ORDER,
	IN_ORDER,
	POST_ORDER
}TreeTraverse;

/*
Desc:	Create a tree instance 	
In:		Void		
Out:	Pointer to the created Tree instance 	
Err: 	NA
*/
Tree* 	TreeCreate();
/*
Desc: 	Destroy a tree instance
In:		Pointer to Tree
Out: 	Void
Err: 	NA. Protected against double-free
*/
void	TreeDestroy		(Tree* _tree);
/*
Desc: 	Insert new node to tree
In:		Pointer to Tree, integer data to insert to node
Out: 	ADTErr to signify errors
Err: 	ERR_OK / ERR_ALLOCATION_FAILED / ERR_NOT_INITIALIZED / ERR_VALUE_EXISTS
*/
ADTErr	TreeInsert		(Tree* _tree, int _data);
/*
Desc: 	Finds if input data value already exists in tree
In:		Pointer to Tree, integer value to find
Out: 	integer (1 == TRUE, 0 == FALSE)
Err: 	NA
*/
int		TreeIsDataFound	(Tree* _tree, int _data);
/*
Desc: 	Prints all data values of tree nodes
In:		Pointer to Tree, traverseMode = PRE_ORDER / IN_ORDER / POST_ORDER
Out: 	Void
Err: 	NA
*/
void	TreePrint		(Tree* _tree, TreeTraverse _traverseMode);


#endif /* #ifndef __BINARYTREE_H__ */
