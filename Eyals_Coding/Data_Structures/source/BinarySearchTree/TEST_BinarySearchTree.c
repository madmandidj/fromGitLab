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

UNIT(BSTreeInsert_2Elements)
	BSTree* tree;
	int intArr[] = {0,1,2,3,4,5,6,7,8,9};
	tree = BSTreeCreate((IsLeftBigger)IsIntLeftBigger, (AreEqual)AreIntsEqual);
	BSTreeInsert(tree, intArr+3);
	BSTreeInsert(tree, intArr+7);
    ASSERT_THAT(BSTreeIsElementFound(tree, intArr+7));
/*    BSTreePrint(tree, INORDER, (ElementFunc)PrintInt);*/
	BSTreeDestroy(tree, NULL);
END_UNIT

UNIT(BSTreeInsert_10Elements)
	BSTree* tree;
	int intArr[] = {0,1,2,3,4,5,6,7,8,9};
	tree = BSTreeCreate((IsLeftBigger)IsIntLeftBigger, (AreEqual)AreIntsEqual);
	BSTreeInsert(tree, intArr+3);
	BSTreeInsert(tree, intArr+8);
	BSTreeInsert(tree, intArr+2);
	BSTreeInsert(tree, intArr+4);
	BSTreeInsert(tree, intArr+9);
	BSTreeInsert(tree, intArr+7);
	BSTreeInsert(tree, intArr+1);
	BSTreeInsert(tree, intArr+5);
	BSTreeInsert(tree, intArr+0);
	BSTreeInsert(tree, intArr+6);
    ASSERT_THAT(BSTreeIsElementFound(tree, intArr+7));
/*    BSTreePrint(tree, INORDER, (ElementFunc)PrintInt);*/
	BSTreeDestroy(tree, NULL);
END_UNIT

UNIT(BSTreeItrNext_10Elements)
	BSTree* tree;
	BSTreeItr itr;
	int intArr[] = {0,1,2,3,4,5,6,7,8,9};
	tree = BSTreeCreate((IsLeftBigger)IsIntLeftBigger, (AreEqual)AreIntsEqual);
	BSTreeInsert(tree, intArr+3);
	BSTreeInsert(tree, intArr+8);
	BSTreeInsert(tree, intArr+2);
	BSTreeInsert(tree, intArr+4);
	BSTreeInsert(tree, intArr+9);
	BSTreeInsert(tree, intArr+7);
	BSTreeInsert(tree, intArr+1);
	BSTreeInsert(tree, intArr+5);
	BSTreeInsert(tree, intArr+0);
	BSTreeInsert(tree, intArr+6);
	itr = BSTreeItrBegin(tree);
    ASSERT_THAT(*(int*)BSTreeItrGet(itr) == 0);
    itr = BSTreeItrNext(itr);
    ASSERT_THAT(*(int*)BSTreeItrGet(itr) == 1);
    itr = BSTreeItrNext(itr);
    ASSERT_THAT(*(int*)BSTreeItrGet(itr) == 2);
    itr = BSTreeItrNext(itr);
    ASSERT_THAT(*(int*)BSTreeItrGet(itr) == 3);
    itr = BSTreeItrNext(itr);
    ASSERT_THAT(*(int*)BSTreeItrGet(itr) == 4);
    itr = BSTreeItrNext(itr);
    ASSERT_THAT(*(int*)BSTreeItrGet(itr) == 5);
    itr = BSTreeItrNext(itr);
    ASSERT_THAT(*(int*)BSTreeItrGet(itr) == 6);
    itr = BSTreeItrNext(itr);
    ASSERT_THAT(*(int*)BSTreeItrGet(itr) == 7);
    itr = BSTreeItrNext(itr);
    ASSERT_THAT(*(int*)BSTreeItrGet(itr) == 8);
    itr = BSTreeItrNext(itr);
    ASSERT_THAT(*(int*)BSTreeItrGet(itr) == 9);
   	itr = BSTreeItrNext(itr);
    ASSERT_THAT((int*)BSTreeItrGet(itr) == NULL);
	BSTreeDestroy(tree, NULL);
END_UNIT

UNIT(BSTreeItrPrev_10Elements)
	BSTree* tree;
	BSTreeItr itr;
	int intArr[] = {0,1,2,3,4,5,6,7,8,9};
	tree = BSTreeCreate((IsLeftBigger)IsIntLeftBigger, (AreEqual)AreIntsEqual);
	BSTreeInsert(tree, intArr+3);
	BSTreeInsert(tree, intArr+8);
	BSTreeInsert(tree, intArr+2);
	BSTreeInsert(tree, intArr+4);
	BSTreeInsert(tree, intArr+9);
	BSTreeInsert(tree, intArr+7);
	BSTreeInsert(tree, intArr+1);
	BSTreeInsert(tree, intArr+5);
	BSTreeInsert(tree, intArr+0);
	BSTreeInsert(tree, intArr+6);
	itr = BSTreeItrEnd(tree);
    ASSERT_THAT(*(int*)BSTreeItrGet(itr) == 9);
    itr = BSTreeItrPrev(itr);
    ASSERT_THAT(*(int*)BSTreeItrGet(itr) == 8);
    itr = BSTreeItrPrev(itr);
    ASSERT_THAT(*(int*)BSTreeItrGet(itr) == 7);
    itr = BSTreeItrPrev(itr);
    ASSERT_THAT(*(int*)BSTreeItrGet(itr) == 6);
    itr = BSTreeItrPrev(itr);
    ASSERT_THAT(*(int*)BSTreeItrGet(itr) == 5);
    itr = BSTreeItrPrev(itr);
    ASSERT_THAT(*(int*)BSTreeItrGet(itr) == 4);
    itr = BSTreeItrPrev(itr);
    ASSERT_THAT(*(int*)BSTreeItrGet(itr) == 3);
    itr = BSTreeItrPrev(itr);
    ASSERT_THAT(*(int*)BSTreeItrGet(itr) == 2);
    itr = BSTreeItrPrev(itr);
    ASSERT_THAT(*(int*)BSTreeItrGet(itr) == 1);
    itr = BSTreeItrPrev(itr);
    ASSERT_THAT(*(int*)BSTreeItrGet(itr) == 0);
   	itr = BSTreeItrPrev(itr);
    ASSERT_THAT((int*)BSTreeItrGet(itr) == NULL);
	BSTreeDestroy(tree, NULL);
END_UNIT


TEST_SUITE(BSTREE TESTS)
	
	TEST(BSTreeCreate_NULL_Params)
	TEST(BSTreeCreate_Valid_Params)
	TEST(BSTreeInsert_EmptyBST)
	TEST(BSTreeInsert_2Elements)
	TEST(BSTreeInsert_10Elements)
	TEST(BSTreeItrNext_10Elements)
	TEST(BSTreeItrPrev_10Elements)
END_SUITE




