/*
Filename: 		TESTStrHomework.c 
Description:	Tests for Implementation of String Functions
Created: 		01/08/17
Created by:		Eyal Alon
Last modified: 	02/08/17
Modified by:	Eyal Alon
*/

#include <stdio.h>
#include <string.h>
#include "StrHomework.h"










/*
 STRLEN ITERATIVE AND RECURSIVE
*/

void TestStrLenNULLstr()
{
	size_t strlength;
	strlength = StrLen(NULL);
	if (strlength == 0)
	{
		printf("PASS: TestStrLenNULLstr\n");
	}
	else
	{
		printf("FAIL: TestStrLenNULLstr");
	}
	return;
}

void TestStrLen()
{
	char str[] = "This string";
	size_t strlength = 0;
	strlength = StrLen(str);
	if (strlength == 11)
	{
		printf("PASS: TestStrLen\n");
	}
	else
	{
		printf("FAIL: TestStrLen\n");
	}
	return;
}

void TestStrLenRecNULLstr()
{
	size_t strlength = 0;
	strlength = StrLenRec(NULL);
	if (strlength == 0)
	{
		printf("PASS: TestStrLenRecNULLstr\n");
	}
	else
	{
		printf("FAIL: TestStrLenRecNULLstr\n");
	}
	return;
}

void TestStrLenRec()
{
	char str[] = "This string";
	size_t strlength = 0;
	strlength = StrLenRec(str);
	if (strlength == 11)
	{
		printf("PASS: TestStrLenRec\n");
	}
	else
	{
		printf("FAIL: TestStrLenRec\n");
	}
	return;
}



























/*
 STRCOMPARE ITERATIVE AND RECURSIVE
*/

void TestStrCompareNULLstr1()
{
	int strCmp;
	char str2[] = "This string";
	strCmp = StrCompare(NULL, str2);
	if (strCmp == 0)
	{
		printf("PASS: TestStrCompareNULLstr1\n");
	}
	else
	{
		printf("FAIL: TestStrCompareNULLstr1\n");
	}
	return;
}

void TestStrCompareNULLstr2()
{
	int strCmp;
	char str1[] = "This string";
	strCmp = StrCompare(str1, NULL);
	if (strCmp == 0)
	{
		printf("PASS: TestStrCompareNULLstr2\n");
	}
	else
	{
		printf("FAIL: TestStrCompareNULLstr2\n");
	}
	return;
}

void TestStrCompareIdentical()
{
	int strCmp;
	char str1[] = "This string";
	char str2[] = "This string";
	strCmp = StrCompare(str1, str2);
	if (strCmp == 0)
	{
		printf("PASS: TestStrCompareIdentical\n");
	}
	else
	{
		printf("FAIL: TestStrCompareIdentical\n");
	}
	return;
}

void TestStrCompareS1Bigger()
{
	int strCmp;
	char str1[] = "This strzng";
	char str2[] = "This string";
	strCmp = StrCompare(str1, str2);
	if (strCmp > 0)
	{
		printf("PASS: TestStrCompareS1Bigger\n");
	}
	else
	{
		printf("FAIL: TestStrCompareS1Bigger\n");
	}
	return;
}

void TestStrCompareS1Smaller()
{
	int strCmp;
	char str1[] = "This string";
	char str2[] = "This strzng";
	strCmp = StrCompare(str1, str2);
	if (strCmp < 0)
	{
		printf("PASS: TestStrCompareS1Smaller\n");
	}
	else
	{
		printf("FAIL: TestStrCompareS1Smaller\n");
	}
	return;
}

void TestStrCompareRecIdenticalNULLstr1()
{
	int strCmp;
	char str2[] = "This string";
	strCmp = StrCompareRec(NULL, str2);
	if (strCmp == 0)
	{
		printf("PASS: TestStrCompareRecIdenticalNULLstr1\n");
	}
	else
	{
		printf("FAIL: TestStrCompareRecIdenticalNULLstr1\n");
	}
	return;
}

void TestStrCompareRecIdenticalNULLstr2()
{
	int strCmp;
	char str1[] = "This string";
	strCmp = StrCompareRec(str1, NULL);
	if (strCmp == 0)
	{
		printf("PASS: TestStrCompareRecIdenticalNULLstr2\n");
	}
	else
	{
		printf("FAIL: TestStrCompareRecIdenticalNULLstr2\n");
	}
	return;
}

void TestStrCompareRecIdentical()
{
	int strCmp;
	char str1[] = "This string";
	char str2[] = "This string";
	strCmp = StrCompareRec(str1, str2);
	if (strCmp == 0)
	{
		printf("PASS: TestStrCompareRecIdentical\n");
	}
	else
	{
		printf("FAIL: TestStrCompareRecIdentical\n");
	}
	return;
}

void TestStrCompareRecS1Bigger()
{
	int strCmp;
	char str1[] = "This strzng";
	char str2[] = "This string";
	strCmp = StrCompareRec(str1, str2);
	if (strCmp > 0)
	{
		printf("PASS: TestStrCompareRecS1Bigger\n");
	}
	else
	{
		printf("FAIL: TestStrCompareRecS1Bigger\n");
	}
	return;
}

void TestStrCompareRecS1Smaller()
{
	int strCmp;
	char str1[] = "This string";
	char str2[] = "This strzng";
	strCmp = StrCompareRec(str1, str2);
	if (strCmp < 0)
	{
		printf("PASS: TestStrCompareRecS1Smaller\n");
	}
	else
	{
		printf("FAIL: TestStrCompareRecS1Smaller\n");
	}
	return;
}



























/*
 STRCOPY ITERATIVE AND RECURSIVE
*/

void TestStrCopyNULLstr1()
{
	char str2[32];
	char* str3;
	str3 = StrCopy(str2, NULL);
	if (str3 == NULL)
	{
		printf("PASS: TestStrCopyNULLstr1\n");
	}
	else
	{
		printf("FAIL: TestStrCopyNULLstr1\n");
	}
	return;
}

void TestStrCopyNULLstr2()
{
	char str1[32];
	char* str3;
	str3 = StrCopy(NULL, str1);
	if (str3 == NULL)
	{
		printf("PASS: TestStrCopyNULLstr2\n");
	}
	else
	{
		printf("FAIL: TestStrCopyNULLstr2\n");
	}
	return;
}

void TestStrCopy()
{
	int strCmp;
	char str1[] = "This string";
	char str2[32];
	char* str3;
	str3 = StrCopy(str2, str1);
	strCmp = strcmp(str1, str3);
	if (strCmp == 0)
	{
		printf("PASS: TestStrCopy\n");
	}
	else
	{
		printf("FAIL: TestStrCopy\n");
	}
	return;
}

void TestStrCopyRec()
{
	int strCmp;
	char str1[] = "This string";
	char str2[32];
	char* str3;
	str3 = StrCopyRec(str2, str1);
	strCmp = strcmp(str1, str3);
	if (strCmp == 0)
	{
		printf("PASS: TestStrCopyRec\n");
	}
	else
	{
		printf("FAIL: TestStrCopyRec\n");
	}
	return;
}























/*
 STRNCOPY ITERATIVE AND RECURSIVE
*/

void TestStrNCopyNULLstr1()
{
	size_t num = 7;
	char str2[32];
	char* str3;
	str3 = StrNCopy(str2, NULL, num);
	if (str3 == NULL)
	{
		printf("PASS: TestStrNCopyNULLstr1\n");
	}
	else
	{
		printf("FAIL: TestStrNCopyNULLstr1\n");
	}
	return;
}

void TestStrNCopyNULLstr2()
{
	size_t num = 7;
	char str1[] = "This string";
	char* str3;
	str3 = StrNCopy(NULL, str1, num);
	if (str3 == NULL)
	{
		printf("PASS: TestStrNCopyNULLstr2\n");
	}
	else
	{
		printf("FAIL: TestStrNCopyNULLstr2\n");
	}
	return;
}

void TestStrNCopy0N()
{
	size_t num = 0;
	char str1[] = "This string";
	char str2[32];
	char* str3;
	str3 = StrNCopy(str2, str1, num);
	if (str3 == NULL)
	{
		printf("PASS: TestStrNCopy0N\n");
	}
	else
	{
		printf("FAIL: TestStrNCopy0N\n");
	}
	return;
}

void TestStrNCopy()
{
	int strCmp;
	size_t num = 7;
	char str1[] = "This string";
	char str2[32];
	char* str3;
	char* str4;
	str3 = StrNCopy(str2, str1, num);
	str4 = strncpy(str2, str1, num);
	strCmp = strcmp(str4, str3);
	if (strCmp == 0)
	{
		printf("PASS: TestStrNCopy\n");
	}
	else
	{
		printf("FAIL: TestStrNCopy\n");
	}
	return;
}


void TestStrNCopyRec()
{
	int strCmp;
	size_t num = 7;
	char str1[] = "This string";
	char str2[32];
	char* str3;
	char* str4;
	str3 = StrNCopyRec(str2, str1, num);
	str4 = strncpy(str2, str1, num);
	strCmp = strcmp(str4, str3);
	if (strCmp == 0)
	{
		printf("PASS: TestStrNCopyRec\n");
	}
	else
	{
		printf("FAIL: TestStrNCopyRec\n");
	}
	return;
}
























/*
 STRCONCAT ITERATIVE AND RECURSIVE
*/

void TestStrConcat()
{
	int strCmp;
	char str1[64] = "This string ";
	char str2[64] = "is a string";
	char* str3;
	str3 = StrConcat(str1, str2);
	strCmp = strcmp(str1, str3);
	if (strCmp == 0)
	{
		printf("PASS: TestStrConcat\n");
	}
	else
	{
		printf("FAIL: TestStrConcat\n");
	}
	return;
}

















/*
 STRSUBSTRING
*/

void TestStrSubStringExists()
{
	char str1[64] = "This string ";
	char str2[64] = "ri";
	char* str3;
	str3 = StrSubString(str1, str2);
	if (strcmp("ring ", str3) == 0)
	{
		printf("PASS: TestStrSubStringExists\n");
	}
	else
	{
		printf("FAIL: TestStrSubStringExists\n");
	}
	return;
}


void TestStrSubStringNotExists()
{
	char str1[64] = "This string ";
	char str2[64] = "abc";
	char* str3;
	str3 = StrSubString(str1, str2);
	if (str3 == NULL)
	{
		printf("PASS: TestStrSubStringNotExists\n");
	}
	else
	{
		printf("FAIL: TestStrSubStringNotExists\n");
	}
	return;
}










int main()
{
	TestStrLenNULLstr();
	TestStrLen();
	TestStrLenRecNULLstr();
	TestStrLenRec();
	TestStrCompareNULLstr1();
	TestStrCompareNULLstr2();
	TestStrCompareIdentical();
	TestStrCompareS1Bigger();
	TestStrCompareS1Smaller();
	TestStrCompareRecIdenticalNULLstr1();
	TestStrCompareRecIdenticalNULLstr2();
	TestStrCompareRecIdentical();
	TestStrCompareRecS1Bigger();
	TestStrCompareRecS1Smaller();
	TestStrCopyNULLstr1();
	TestStrCopyNULLstr2();
	TestStrCopy();
	TestStrCopyRec();
	TestStrNCopyNULLstr1();
	TestStrNCopyNULLstr2();
	TestStrNCopy0N();
	TestStrNCopy();
	TestStrNCopyRec();
	TestStrConcat();
	TestStrSubStringExists();
	TestStrSubStringNotExists();
	return 1;
}
