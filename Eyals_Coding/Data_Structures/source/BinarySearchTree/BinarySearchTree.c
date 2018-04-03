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
#define ITR_FATHER(I)	(((BSTnode*)I)->m_father)
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
	AreEqual		m_areEqual;
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
	if (TREE_ROOT(_tree))
	{
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
BSTree* BSTreeCreate(IsLeftBigger _isLeftBiggerFunc, AreEqual _areEqualFunc)
{
	BSTree* tree;
	
	if (!_isLeftBiggerFunc || !_areEqualFunc)
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
	tree->m_areEqual = _areEqualFunc;
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
		TraverseTree(_tree, POSTORDER, (TraverseAction)_elementDestroyFunc, NULL);
	}
	TraverseTree(_tree, POSTORDER, (TraverseAction)DestroyBSTnode, NULL); /*Cant use this because the function sends the node data to the action function, where here you actually wnat to free the node. Use iterators for next next blah blah*/
	free(_tree->m_sentinel);
	free(_tree);
}

static ADTErr DoInsert(BSTree* _tree, BSTreeItr _itr, void* _element)
{
	BSTnode* node;
	
	if (_tree->m_areEqual(ITR_DATA(_itr), _element))
	{
		return ERR_BST_ELEMENT_FOUND;
	}
	if (_tree->m_isLeftBiggerFunc(ITR_DATA(_itr), _element))
	{
		if (!ITR_LEFT(_itr))
		{
			if (!(node = CreateBSTnodeWithData(_element)))
			{
				return ERR_NOMEM;
			}
			ITR_LEFT(_itr) = node;
			NODE_FATHER(node) = (BSTnode*)_itr;
			return ERR_OK;
		}
		 return DoInsert(_tree, ITR_LEFT(_itr), _element);
	}
	else
	{
		if (!ITR_RIGHT(_itr))
		{
			if (!(node = CreateBSTnodeWithData(_element)))
			{
				return ERR_NOMEM;
			}
			ITR_RIGHT(_itr) = node;
			NODE_FATHER(node) = (BSTnode*)_itr;
			return ERR_OK;
		}
		return DoInsert(_tree, ITR_RIGHT(_itr), _element);
	}
}

ADTErr BSTreeInsert(BSTree* _tree, void* _element)
{
	BSTreeItr itr;
	BSTnode* node;
	
	if (!_tree || !_element)
	{
		return ERR_INVARG;
	}
	itr = BSTreeItrBegin(_tree);
	if (itr)
	{
		return DoInsert(_tree, itr, _element);
	}
	if (!(node = CreateBSTnodeWithData(_element)))
	{
		return ERR_NOMEM;
	}
	TREE_ROOT(_tree) = node;
	NODE_FATHER(node) = TREE_ROOT(_tree);
	return ERR_OK;
}

void BSTreePrint(BSTree* _tree, BSTTraverseMode _traverseMode, ElementFunc _printFunc)
{
	if (!_tree || !_printFunc)
	{
		return;
	}
	TraverseTree(_tree, _traverseMode, (TraverseAction)_printFunc, NULL);
}

static BSTreeItr DoIsElementFound(BSTree* _tree, BSTreeItr _itr, void* _element)
{
	BSTreeItr isLeftFoundItr = NULL;
	BSTreeItr isRightFoundItr = NULL;
	
	if (_tree->m_areEqual(ITR_DATA(_itr), _element))
	{
		return _itr;
	}
	if (ITR_RIGHT(_itr))
	{
		isRightFoundItr = DoIsElementFound(_tree, ITR_RIGHT(_itr), _element);
	}
	if (ITR_LEFT(_itr))
	{
		isLeftFoundItr = DoIsElementFound(_tree, ITR_LEFT(_itr), _element);
	}
	return isLeftFoundItr ? isLeftFoundItr : (isRightFoundItr ? isRightFoundItr : NULL);
}

BSTreeItr BSTreeIsElementFound(BSTree* _tree, void* _element)
{
	BSTreeItr itr = NULL;
	BSTreeItr itrFound = NULL;
	if (!_tree || !_element)
	{
		return NULL;
	}
	itr = TREE_ROOT(_tree);
	if (itr)
	{	
		itrFound = DoIsElementFound(_tree, itr, _element);
	}
	return itrFound;
}

BSTreeItr BSTreeItrBegin(BSTree* _tree)
{
	BSTreeItr itr = NULL;
	
	itr = TREE_ROOT(_tree);
	if (itr)
	{
		while (NULL != ITR_LEFT(itr))
		{
			itr = ITR_LEFT(itr);
		}	
	}
	return itr;
}




