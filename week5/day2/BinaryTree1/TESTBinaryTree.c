/*
Filename: 		TESTBinaryTree.c 
Description:	Tests for Implementation of binary tree API given by Izik.
Created: 		17/07/17
Created by:		Eyal Alon
Last modified: 	17/07/17
Modified by:	Eyal Alon
*/

#include <stdio.h>
#include "BinaryTree.h"

int main()
{
	Tree* tree;
	ADTErr result;
	int iDF;
	tree = TreeCreate();
	result = TreeInsert(tree, 10);
	result = TreeInsert(tree, 15);
	result = TreeInsert(tree, 7);
	result = TreeInsert(tree, 2);
	result = TreeInsert(tree, 5);
	result = TreeInsert(tree, 1);
	iDF = TreeIsDataFound(tree, 10);
	printf("%d\n", iDF);
	TreePrint(tree, POST_ORDER);
	TreeDestroy(tree);
	return 0;
}
