/*
Filename: 		BinaryTree.c 
Description:	Implementation of binary tree API given by Izik.
Created: 		17/07/17
Created by:		Eyal Alon
Last modified: 	29/07/17
Modified by:	Eyal Alon
*/
#include <stdio.h>
#include "BinaryTree.h"
#define MAGIC_NUM 17
/* 
TODO:
* add descriptions about structs
*
*
*/

typedef struct Node Node;
struct Node
{
	int m_data;
	Node* m_left;
	Node* m_right;
	Node* m_father;
};

struct Tree
{
	Node* m_root;
	int m_magicNum;
};









/*************
AUX STATIC FUNCTIONS
**************/


static ADTErr CheckPtrNotNULL(void* _ptr)
{
	ADTErr result;
	if (NULL == _ptr)
	{
		result = ERR_NOT_INITIALIZED;
	}
	else
	{
		result = ERR_OK;
	}
	return result;
}











/*************
TREE CREATE
**************/


Tree* 	TreeCreate()
{
	Tree* tree;
	tree = malloc(sizeof(Tree));
	if (NULL == tree)
	{
		return NULL;
	}
	tree->m_root = NULL;
	tree->m_magicNum = MAGIC_NUM;
	return tree;
}















/*************
TREE DESTROY
**************/


static void TreeDestroyRec(Node* _node)
{
	if (NULL == _node)
	{
		return;
	}
	TreeDestroyRec(_node->m_left);
	TreeDestroyRec(_node->m_right);
	free(_node);
}

void	TreeDestroy(Tree* _tree)
{
	Node* node;
	if (NULL != _tree && _tree->m_magicNum == MAGIC_NUM)
	{
		node = _tree->m_root;
		TreeDestroyRec(node);
		_tree->m_magicNum = 1001;
		free(_tree);
	}
	return;
}
















/*************
TREE INSERT
**************/


static int IsTreeEmpty(Tree* _tree)
{
	int result = 0;
	if (NULL == _tree->m_root)
	{
		result = 1;
	}
	return result;
}

/*
static Node* CreateAndInsertNode(Node* _father, int _data)
{
	Node* node;
	node = malloc(sizeof(Node));
	if (NULL == node)
	{
		return NULL;
	}
	node->m_data = _data;
	node->m_left = NULL;
	node->m_right = NULL;
	node->m_father = _father;
	return node;
}

static ADTErr TreeInsertRec(Node* _node, int _data)
{
	ADTErr result = ERR_GENERAL;
	if (_node->m_data == _data)
	{
		result = ERR_VALUE_EXISTS;
	}
	else if (_data < _node->m_data)
	{
		if (_node->m_left != NULL)
		{
			TreeInsertRec(_node->m_left, _data);
		}
		else
		{
			_node->m_left = CreateAndInsertNode(_node, _data);
			if (NULL == _node->m_left)
			{
				result = ERR_ALLOCATION_FAILED;
			}
			else
			{
				result = ERR_OK;
			}
		}
	}
	else if (_data > _node->m_data)
	{
		if (_node->m_right != NULL)
		{
			TreeInsertRec(_node->m_right, _data);
		}
		else
		{
			_node->m_right = CreateAndInsertNode(_node, _data);
			if (NULL == _node->m_right)
			{
				result = ERR_ALLOCATION_FAILED;
			}
			else
			{
				result = ERR_OK;
			}
		}
	}
	return result;
}
*/

static ADTErr InsertNode(Node* _node, int _data)
{
	ADTErr result = ERR_OK;
	if (_data > _node->m_data)
	{
		/*TODO: Can use calloc here instead of malloc */
		_node->m_right = malloc(sizeof(Node)); 
		if (NULL == _node->m_right)
		{
			result = ERR_ALLOCATION_FAILED;
		}
		else
		{
			/*TODO: Can move this to createnode function */
			_node->m_right->m_data = _data;  
			_node->m_right->m_left = NULL;
			_node->m_right->m_right = NULL;
			_node->m_right->m_father = _node;
			result = ERR_OK;
		}
	}
	else if (_data < _node->m_data)
	{
		_node->m_left = malloc(sizeof(Node));
		if (NULL == _node->m_left)
		{
			return ERR_ALLOCATION_FAILED;
		}
		else
		{
			_node->m_left->m_data = _data;
			_node->m_left->m_left = NULL;
			_node->m_left->m_right = NULL;
			_node->m_left->m_father = _node;
			result = ERR_OK;
		}
	}
	return result;
}

static Node* BubbleDownRec(Node* _node, int _data)
{
	Node* foundNode = NULL;
	if (_node->m_data == _data)
	{
		foundNode = NULL;
	}
	else if (_data < _node->m_data)
	{
		if (_node->m_left == NULL)
		{
			foundNode = _node;
		}
		else
		{
			foundNode = BubbleDownRec(_node->m_left, _data);
		}
	}
	else if (_data > _node->m_data)
	{
		if (_node->m_right == NULL)
		{
			foundNode = _node;
		}
		else
		{
			foundNode = BubbleDownRec(_node->m_right, _data);
		}
	}
	return foundNode;
}

ADTErr	TreeInsert(Tree* _tree, int _data)
{
	ADTErr resultErr;
	Node* node;
	resultErr = CheckPtrNotNULL((void*) _tree);
	if (resultErr != ERR_OK)
	{
		return resultErr;
	}
	else if(IsTreeEmpty(_tree))
	{
		_tree->m_root = malloc(sizeof(Node));
		if (NULL == _tree->m_root)
		{
			return ERR_ALLOCATION_FAILED;
		}
		else
		{
			_tree->m_root->m_data = _data;
			_tree->m_root->m_left = NULL;
			_tree->m_root->m_right = NULL;
			_tree->m_root->m_father = NULL;	
			resultErr = ERR_OK;	
		}
	}
	else
	{
		node = BubbleDownRec(_tree->m_root, _data);
		if (node == NULL)
		{
			resultErr = ERR_VALUE_EXISTS;
		}
		else
		{
			resultErr = InsertNode(node, _data);
		}
	}
	return resultErr;
}





















/*************
TREE ISDATAFOUND
**************/


static int TreeIsDataFoundRec(Node* _node, int _data)
{
	int result = 0;
	if (_node->m_data == _data)
	{
		result = 1;
	}
	else if (_data < _node->m_data)
	{
		if (_node->m_left != NULL)
		{
			TreeIsDataFoundRec(_node->m_left, _data);
		}
		else
		{
			result = 0;
		}
	}
	else if (_data > _node->m_data)
	{
		if (_node->m_right != NULL)
		{
			TreeIsDataFoundRec(_node->m_right, _data);
		}
		else
		{
			result = 0;
		}
	}
	return result;
}

int		TreeIsDataFound(Tree* _tree, int _data)
{
	if (NULL != _tree)
	{
		if (NULL == _tree->m_root)
		{
			return 0;
		}
		else
		{
			return TreeIsDataFoundRec(_tree->m_root, _data);
		}
	}
	else
	{
		return 0;
	}
}



















/*************
TREE PRINT
**************/



static void TreePrintRecPre(Node* _node)
{
	if (NULL == _node)
	{
		return;
	}
	printf("%d\n", _node->m_data);
	TreePrintRecPre(_node->m_left);
	TreePrintRecPre(_node->m_right);
}

static void TreePrintRecIn(Node* _node)
{
	if (NULL == _node)
	{
		return;
	}
	TreePrintRecIn(_node->m_left);
	printf("%d\n", _node->m_data);
	TreePrintRecIn(_node->m_right);
}

static void TreePrintRecPost(Node* _node)
{
	if (NULL == _node)
	{
		return;
	}
	TreePrintRecPost(_node->m_left);
	TreePrintRecPost(_node->m_right);
	printf("%d\n", _node->m_data);
}


void	TreePrint(Tree* _tree, TreeTraverse _traverseMode)
{
	if (NULL != _tree)
	{
		if (NULL != _tree->m_root)
		{
			switch (_traverseMode)
			{
			case PRE_ORDER:
				TreePrintRecPre(_tree->m_root);
				break;
			case IN_ORDER:
				TreePrintRecIn(_tree->m_root);
				break;
			case POST_ORDER:
				TreePrintRecPost(_tree->m_root);
				break;
			}
		}
	}
	return;
}



