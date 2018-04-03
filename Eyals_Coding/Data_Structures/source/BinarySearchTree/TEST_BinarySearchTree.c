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

int AreIntsEqual(int* _leftInt, int* _rightInt)
{
	return *_leftInt == *_rightInt;
}

void PrintInt(int* _element)
{
	printf("%d\n", *_element);
}


UNIT(BSTreeCreate_NULL_Params)
	BSTree* tree;
	tree = BSTreeCreate(NULL, NULL);
    ASSERT_THAT(!tree);
END_UNIT

UNIT(BSTreeCreate_Valid_Params)
	BSTree* tree;
	tree = BSTreeCreate((IsLeftBigger)IsIntLeftBigger, (AreEqual)AreIntsEqual);
    ASSERT_THAT(tree);
	BSTreeDestroy(tree, NULL);
END_UNIT

UNIT(BSTreeInsert_EmptyBST)
	BSTree* tree;
	int intArr[] = {0,1,2,3,4,5,6,7,8,9};
	tree = BSTreeCreate((IsLeftBigger)IsIntLeftBigger, (AreEqual)AreIntsEqual);
	BSTreeInsert(tree, intArr+3);
    ASSERT_THAT(BSTreeIsElementFound(tree, intArr+3));
	BSTreeDestroy(tree, NULL);
END_UNIT


TEST_SUITE(BSTREE TESTS)
	
	TEST(BSTreeCreate_NULL_Params)
	TEST(BSTreeCreate_Valid_Params)
	TEST(BSTreeInsert_EmptyBST)

END_SUITE




