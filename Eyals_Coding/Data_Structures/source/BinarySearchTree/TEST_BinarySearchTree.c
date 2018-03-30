#include "../../inc/BinarySearchTree.h"
#include "../../inc/mu_test.h"
#include "../../inc/ADTErr.h"
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


int IsIntLeftBigger(int* _leftInt, int* _rightInt)
{
	return *_leftInt > *_rightInt;
}

void PrintInt(int* _element)
{
	printf("%d\n", *_element);
}


UNIT(BSTreeCreate_NULL_IsLeftBiggerFunc)
	BSTree* tree;
	tree = BSTreeCreate(NULL);
    ASSERT_THAT(!tree);
END_UNIT


TEST_SUITE(BSTREE TESTS)
	
	TEST(BSTreeCreate_NULL_IsLeftBiggerFunc)



END_SUITE




