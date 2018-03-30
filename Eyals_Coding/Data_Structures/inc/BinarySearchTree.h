#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__


#include "ADTErr.h"

typedef struct BSTree BSTree;
typedef void* BSTreeItr;

typedef enum
{
	PREORDER,
    INORDER,
    POSTORDER,
    DEPTH_FIRST,
    BREADTH_FIRST
}BSTTraverseMode;

typedef void(*ElementFunc)(void*);
typedef int(*IsLeftBigger)(void*, void*);
typedef int(*PredicateFunc)(void* _element, void* _context);

BSTree* BSTreeCreate(IsLeftBigger _isLeftBiggerFunc);
void BSTreeDestroy(BSTree* _tree, ElementFunc _elementDestroyFunc);
ADTErr BSTreeInsert(BSTree* _tree, void* _element);
int BSTreeIsElementFound(BSTree* _tree, void* _element);
void BSTreePrint(BSTree* _tree, BSTTraverseMode _traverseMode);

BSTreeItr BSTreeItrBegin(BSTree* _tree);
BSTreeItr BSTreeItrEnd(BSTree* _tree);
BSTreeItr BSTreeItrNext(BSTreeItr _treeItr);
BSTreeItr BSTreeItrPrev(BSTreeItr _treeItr);
BSTreeItr BSTreeFindFirst(BSTree* _tree, PredicateFunc _predFunc, void* _context);
void* BSTreeItrRemove(BSTreeItr _treeItr);
void* BSTreeItrGet(BSTreeItr _treeItr);


#endif/*#ifndef __BINARY_SEARCH_TREE_H__*/































