/*
Filename: 		BinaryTree.h 
Description:	Contains binary tree API given by Izik.
Created: 		17/07/17
Created by:		Eyal Alon
Last modified: 	17/07/17
Modified by:	Eyal Alon
*/

#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__
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
Desc: 	
In:		
Out: 	
Err: 	
*/
Tree* 	TreeCreate();
/*
Desc: 	
In:		
Out: 	
Err: 	
*/
void	TreeDestroy(Tree* _tree);
/*
Desc: 	
In:		
Out: 	
Err: 	
*/
ADTErr	TreeInsert(Tree* _tree, int _data);
/*
Desc: 	
In:		
Out: 	
Err: 	
*/
int		TreeIsDataFound(Tree* _tree, int _data);
/*
Desc: 	
In:		
Out: 	
Err: 	
*/
void	TreePrint(Tree* _tree, TreeTraverse _traverseMode);


#endif /* #ifndef __BINARYTREE_H__ */
