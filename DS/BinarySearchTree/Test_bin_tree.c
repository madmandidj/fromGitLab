#include <stdio.h>
#include <stdlib.h> /* malloc, free */
#include <string.h> /* strcpy */
#include <assert.h> /* assert */
#include "bin_tree.h"

/*****
GENERAL MACROS
*****/
#define TRUE 			1
#define FALSE 			0
#define INVALID 		-1
#define IS_NULL(A) 		(NULL == (A))
#define IS_FALSE(I)		(NULL == (I))

typedef struct Person Person;
struct Person
{
	size_t 		m_age;
	char 		m_name[64];
	size_t 		m_famSize;
	Person**	m_family;
};

/*****
INIT FUNCTIONS
*****/
static int* InitIntArr(size_t _numOfInts)
{
    int* arr;
    size_t index;
    assert(0 != _numOfInts);

    arr = malloc(_numOfInts * sizeof(int));
    if (NULL == arr)
    {
        return NULL;
    }
    for (index = 0; index < _numOfInts; ++index)
    {
        arr[index] = (int)index;
    }
    return arr;
}

static Person* InitPersArr(size_t _numOfPersons)
{
    Person* arr;
	size_t numOfFamily = 2;
	size_t index;
	size_t indexDealloc;
	size_t indexFam;
	char* names[] = {"Eyal\0", "Yodo\0", "Erez\0", "Eli\0", "Hana\0"};
	size_t ages[] = {101, 999, 23, 21, 17};

    assert(0 != _numOfPersons);
    arr = malloc(_numOfPersons * sizeof(Person));
	if (NULL == arr)
	{
		return NULL;
	}
	for (index = 0; index < _numOfPersons; ++index)
	{
		arr[index].m_famSize = numOfFamily;
		arr[index].m_age = ages[index];
		strcpy(arr[index].m_name, names[index]);
		arr[index].m_family = malloc(numOfFamily * sizeof(Person));
		if (NULL == arr[index].m_family)
		{
			for (indexDealloc = index-1; indexDealloc > 0; --indexDealloc)
			{
				free(arr[index].m_family);
			}
			free(arr);
			return NULL;
		}
		for (indexFam = 0; indexFam < numOfFamily; ++indexFam)
		{
			arr[index].m_family[indexFam] = &arr[indexFam];
		}
	}
	arr[0].m_family[0] = &arr[1];
	arr[0].m_family[1] = &arr[2];
	arr[1].m_family[0] = &arr[3];
	arr[1].m_family[1] = &arr[4];
	return arr;
}







/*****
LESS COMPARATOR FUNCTIONS
*****/
int IntLessComparator(int* _left, int* _right)
{
    assert(!IS_NULL(_left) && !IS_NULL(_right));
    if (*_left < *_right)
    {
        return TRUE;
    }
    return FALSE;
}









/*****
ACTION FUNCTIONS
*****/
int PrintItrInt(int* _element, void* _context)
{
	printf("%d\n", *_element);
	return;
}






/*****
BSTREE CREATE TESTS
*****/
void TestBSTreeCreateNULLLess()
{
    BSTree* tree;

    tree = BSTreeCreate(NULL);
    if (IS_NULL(tree))
    {
        printf("PASS: TestBSTreeCreateNULLLess\n");
    }
    else
    {
        printf("FALSE: TestBSTreeCreateNULLLess\n");
    }
    return;
}

void TestBSTreeCreate()
{
    BSTree* tree;

    tree = BSTreeCreate((LessComparator) IntLessComparator);
    if (!IS_NULL(tree))
    {
        printf("PASS: TestBSTreeCreate\n");
    }
    else
    {
        printf("FALSE: TestBSTreeCreate\n");
    }
    BSTreeDestroy(tree, NULL);
    return;
}







/*****
BSTREE DESTROY TESTS
*****/
/*
TODO: destroy 10 items without destroyfunc
TODO: destroy 10 person items using destroyfunc
*/

void TestBSTreeDestroyDoubleDestroy()
{
    BSTree* tree;

    tree = BSTreeCreate((LessComparator) IntLessComparator);
    BSTreeDestroy(tree, NULL);
    BSTreeDestroy(tree, NULL);
    printf("PASS: TestBSTreeDestroyDoubleDestroy\n");
    return;
}







/*****
BSTREE INSERT TESTS
*****/
void TestBSTreeInsertEmptyBST()
{
    BSTree* tree;
    int* arr;
    BSTreeItr itr;
    const size_t numOfInts = 10;
    int* data;

    arr = InitIntArr(numOfInts);
    tree = BSTreeCreate((LessComparator) IntLessComparator);
    BSTreeInsert(tree, arr + 1);

    itr = BSTreeItrBegin(tree);
    data = BSTreeItrGet(itr);
    printf("%d\n", *data);
    BSTreeDestroy(tree, NULL);
    free(arr);
    return;
}


void TestBSTreeInsertSmallerItem()
{
    BSTree* tree;
    int* arr;
    BSTreeItr itr;
    const size_t numOfInts = 10;
    int* data;

    arr = InitIntArr(numOfInts);
    tree = BSTreeCreate((LessComparator) IntLessComparator);
    BSTreeInsert(tree, arr + 4);
    BSTreeInsert(tree, arr + 3);
    itr = BSTreeItrBegin(tree);
    data = BSTreeItrGet(itr);
    printf("%d\n", *data);
    BSTreeDestroy(tree, NULL);
    free(arr);
    return;
}

void TestBSTreeInsertLargerItem()
{
    BSTree* tree;
    int* arr;
    BSTreeItr itr;
    const size_t numOfInts = 10;
    int* data;

    arr = InitIntArr(numOfInts);
    tree = BSTreeCreate((LessComparator) IntLessComparator);
    BSTreeInsert(tree, arr + 2);
    BSTreeInsert(tree, arr + 7);
    itr = BSTreeItrBegin(tree);
    itr = BSTreeItrNext(itr);
    data = BSTreeItrGet(itr);
    printf("%d\n", *data);
    BSTreeDestroy(tree, NULL);
    free(arr);
    return;
}






void TestBSTreeItrNextToEnd()
{
    BSTree* tree;
    int* arr;
    BSTreeItr itr;
    const size_t numOfInts = 10;
    int* data;

    arr = InitIntArr(numOfInts);
    tree = BSTreeCreate((LessComparator) IntLessComparator);
    BSTreeInsert(tree, arr + 2);
    BSTreeInsert(tree, arr + 7);
    itr = BSTreeItrBegin(tree);
    itr = BSTreeItrNext(itr);
    itr = BSTreeItrNext(itr);
    if (BSTreeItrEnd(tree) == itr)
    {
        printf("at end\n");
    }
    else
    {
        printf("NOT at end\n");
    }
    BSTreeForEach(BSTreeItrBegin(tree), PrintItrInt, NULL);
    // data = BSTreeItrGet(itr);
    
    BSTreeDestroy(tree, NULL);
    free(arr);
    return;
}









































int main()
{
    TestBSTreeCreateNULLLess();
    TestBSTreeCreate();
    TestBSTreeDestroyDoubleDestroy();
    TestBSTreeInsertEmptyBST();
    TestBSTreeInsertSmallerItem();
    TestBSTreeInsertLargerItem();
    TestBSTreeItrNextToEnd();
    return 0;
}

































