#include "../../inc/BinarySearchTree.h"
#include <stdlib.h>

/*****
TREE MACROS
*****/
#define TREE_ROOT(T) 	((T)->m_sentinel->m_left)
/*****
NODE MACROS
*****/
#define NODE_DATA(N) 	((N)->m_data)
#define NODE_FATHER(N) 	((N)->m_father)
#define NODE_LEFT(N) 	((N)->m_left)
#define NODE_RIGHT(N) 	((N)->m_right)
/*****
ITERATOR MACROS
*****/
#define ITR_DATA(I)		(((BSTnode*)I)->m_data)
#define ITR_FATER(I)	(((BSTnode*)I)->m_father)
#define ITR_LEFT(I)		(((BSTnode*)I)->m_left)
#define ITR_RIGHT(I)	(((BSTnode*)I)->m_right)


typedef struct BSTnode BSTnode;

struct BSTnode
{
	void* 		m_data;
	BSTnode* 	m_father;
	BSTnode* 	m_left;
	BSTnode* 	m_right;
};

struct BSTree
{
	BSTnode* 		m_sentinel;
	size_t			m_numOfElements;
	IsLeftBigger 	m_isLeftBiggerFunc;
};

/*STATIC FUNCTIONS*/
static void TraversePreOrder(BSTnode* _node, TraverseAction _actionFunc, void* _context)
{
	_actionFunc(NODE_DATA(_node), _context);
	if (NODE_LEFT(_node))
	{
		TraversePreOrder(NODE_LEFT(_node), _actionFunc, _context);
	}
	if (NODE_RIGHT(_node))
	{
		TraversePreOrder(NODE_LEFT(_node), _actionFunc, _context);
	}
}

static void TraverseInOrder(BSTnode* _node, TraverseAction _actionFunc, void* _context)
{
	if (NODE_LEFT(_node))
	{
		TraverseInOrder(NODE_LEFT(_node), _actionFunc, _context);
	}
	_actionFunc(NODE_DATA(_node), _context);
	if (NODE_RIGHT(_node))
	{
		TraverseInOrder(NODE_LEFT(_node), _actionFunc, _context);
	}
}

static void TraversePostOrder(BSTnode* _node, TraverseAction _actionFunc, void* _context)
{
	if (NODE_LEFT(_node))
	{
		TraversePostOrder(NODE_LEFT(_node), _actionFunc, _context);
	}
	if (NODE_RIGHT(_node))
	{
		TraversePostOrder(NODE_LEFT(_node), _actionFunc, _context);
	}
	_actionFunc(NODE_DATA(_node), _context);
}

static void TraverseTree(BSTree* _tree, BSTTraverseMode _traverseMode, TraverseAction _actionFunc, void* _context)
{
	if (!_tree || !_actionFunc)
	{
		return;
	}
	switch (_traverseMode)
	{
		case PREORDER:
			TraversePreOrder(TREE_ROOT(_tree), _actionFunc, _context);
			break;
		case INORDER:
			TraverseInOrder(TREE_ROOT(_tree), _actionFunc, _context);
			break;
		case POSTORDER:
			TraversePostOrder(TREE_ROOT(_tree), _actionFunc, _context);
			break;
		default:
			return;
	}
}

static void DestroyBSTnode(BSTnode* _node)
{
	free(_node);
}

static BSTnode* CreateBSTnodeWithData(void* _data)
{
	BSTnode* node;
	 if(!(node = malloc(sizeof(BSTnode))))
	 {
	 	return NULL;
	 }
	 NODE_DATA(node) = _data;
	 return node;
}


/*API FUNCTIONS*/
BSTree* BSTreeCreate(IsLeftBigger _isLeftBiggerFunc)
{
	BSTree* tree;
	
	if (!_isLeftBiggerFunc)
	{
		return NULL;
	}
	if (!(tree = malloc(sizeof(BSTree))))
	{
		return NULL;
	}
	if (!(tree->m_sentinel = malloc(sizeof(BSTnode))))
	{
		free(tree);
		return NULL;
	}
	tree->m_numOfElements = 0;
	tree->m_isLeftBiggerFunc = _isLeftBiggerFunc;
	tree->m_sentinel->m_father = tree->m_sentinel->m_right = NULL;
	tree->m_sentinel->m_data = NULL;
	return tree;
}

void BSTreeDestroy(BSTree* _tree, ElementFunc _elementDestroyFunc)
{
	if (!_tree)
	{
		return;
	}
	if(_elementDestroyFunc)
	{	
		TraverseTree(_tree, POSTORDER, _elementDestroyFunc, NULL);
	}
	TraverseTree(_tree, POSTORDER, DestroyBSTnode, NULL);
	free(_tree->m_sentinel);
	free(_tree);
}

ADTErr BSTreeInsert(BSTree* _tree, void* _element)
{
	int isElementFound = 0;
	
	if (!_tree || !_element)
	{
		return ERR_INVARG;
	}
	
	
	
}

void BSTreePrint(BSTree* _tree, BSTTraverseMode _traverseMode, ElementFunc _printFunc)
{
	if (!_tree || !_printFunc)
	{
		return;
	}
	TraverseTree(_tree, _traverseMode, _printFunc, NULL);
}

BSTreeItr BSTreeItrBegin(BSTree* _tree)
{
	BSTreeItr itr;
	
	itr = TREE_ROOT(_tree);
	while (NULL != ITR_LEFT(itr))
	{
		itr = ITR_LEFT(itr);
	}
	return itr;
}




