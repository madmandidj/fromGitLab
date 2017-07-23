/*
Filename: 		BinaryTree.c 
Description:	Implementation of binary tree API given by Izik.
Created: 		17/07/17
Created by:		Eyal Alon
Last modified: 	17/07/17
Modified by:	Eyal Alon
*/

#include <stdio.h>
#include "BinaryTree.h"

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


/****** Static functions *******/


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

static Node* CreateNode(Node* _father, int _data)
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
	if (_node->m_data == _data)
	{
		return ERR_VALUE_EXISTS;
	}
	else if (_data < _node->m_data)
	{
		if (_node->m_left != NULL)
		{
			TreeInsertRec(_node->m_left, _data);
		}
		else
		{
			_node->m_left = CreateNode(_node, _data);
			if (NULL == _node->m_left)
			{
				return ERR_ALLOCATION_FAILED;
			}
			else
			{
				return ERR_OK;
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
			_node->m_right = CreateNode(_node, _data);
			if (NULL == _node->m_right)
			{
				return ERR_ALLOCATION_FAILED;
			}
			else
			{
				return ERR_OK;
			}
		}
	}
}

static int TIDFR(Node* _node, int _data)
{
	if (_node->m_data == _data)
	{
		return 1;
	}
	else if (_data < _node->m_data)
	{
		if (_node->m_left != NULL)
		{
			TIDFR(_node->m_left, _data);
		}
		else
		{
			return 0;
		}
	}
	else if (_data > _node->m_data)
	{
		if (_node->m_right != NULL)
		{
			TIDFR(_node->m_right, _data);
		}
		else
		{
			return 0;
		}
	}
}

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


/****** API functions *******/


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

void	TreeDestroy(Tree* _tree)
{
	Node* node;
	if (NULL != _tree && _tree->m_magicNum == MAGIC_NUM)
	{
		node = _tree->m_root;
		TreeDestroyRec(node);
		free(_tree);
	}
	return;
}

ADTErr	TreeInsert(Tree* _tree, int _data)
{
	ADTErr result;
	if (NULL != _tree)
	{
		if (NULL == _tree->m_root)
		{
			_tree->m_root = CreateNode(NULL, _data);
			if (NULL == _tree->m_root)
			{
				return ERR_ALLOCATION_FAILED;
			}
			else
			{
				return ERR_OK;
			}
		}
		else
		{
			result = TreeInsertRec(_tree->m_root, _data);
		}
	}
	else
	{
		return ERR_NOT_INITIALIZED;
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
			return TIDFR(_tree->m_root, _data);
		}
	}
	else
	{
		return 0;
	}
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



