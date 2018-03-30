#include "../../inc/BinarySearchTree.h"
#include <stdlib.h>

typedef struct BSTnode BSTnode;

struct BSTnode
{
	void* 		m_data;
	BSTnode* 	m_father;
	BSTnode* 	m_leftNode;
	BSTnode* 	m_rightNode;
};

struct BSTree
{
	BSTnode* 		m_sentinel;
	size_t			m_numOfElements;
	IsLeftBigger 	m_isLeftBiggerFunc;
};

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
	tree->m_sentinel->m_father = tree->m_sentinel->m_rightNode = NULL;
	tree->m_sentinel->m_data = NULL;
	return tree;
}










