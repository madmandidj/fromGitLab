#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__
/*
Filename: 		BinaryTree.h 
Description:	Generic binary search tree API
Created: 		09/08/17
Created by:		Eyal Alon
Last modified: 	09/08/17
Modified by:	Eyal Alon
*/
#include <stdlib.h>
#include "ADTDefs.h"

typedef struct Tree Tree;

typedef enum
{
    TREE_OK,
    TREE_UNINITIALIZED,
    TREE_ALLOCATION_FAILED,
    TREE_IS_EMPTY,
    TREE_ITEM_NOT_FOUND,
    TREE_INV_ARG
} TreeError;

typedef enum
{
	PRE_ORDER,
	IN_ORDER,
	POST_ORDER
}TreeTraverse;

/* use also for predicate */
typedef int (*UserActionFunc)(void* _item, void* _context);

typedef int (*CompareFunc)(void* _item1, void* _item2);

/* add to the struct compareFunc */
Tree* 	TreeCreate(CompareFunc _compareFunc);

void	TreeDestroy			(Tree* _tree, UserActionFunc _destroyFunc, void* _context);

TreeError	TreeInsert		(Tree* _tree, void* _data);

int		TreeIsDataFound		(Tree* _tree, PredicateFunc _predicaetFunc, void* _context);

void	TreePrint			(Tree* _tree, TreeTraverse _traverseMode);


#endif /* #ifndef __BINARYTREE_H__ */
