#include <stdio.h>
#include <string.h>
#include "StrHomework.h"










/*
 STRLEN ITERATIVE AND RECURSIVE
*/

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
		printf("FAIL: TestStrLen");
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
		printf("FAIL: TestStrLenRec");
	}
	return;
}



























/*
 STRCOMPARE ITERATIVE AND RECURSIVE
*/

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
		printf("FAIL: TestStrCompareIdentical");
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
		printf("FAIL: TestStrCompareS1Bigger");
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
		printf("FAIL: TestStrCompareRecIdentical");
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































int main()
{
	TestStrLen();
	TestStrLenRec();
	TestStrCompareIdentical();
	TestStrCompareS1Bigger();
	TestStrCompareS1Smaller();
	TestStrCompareRecIdentical();
	TestStrCompareRecS1Bigger();
	TestStrCompareRecS1Smaller();
	TestStrCopy();
	TestStrCopyRec();
	TestStrNCopy();
	TestStrNCopyRec();
	TestStrConcat();
	return 1;
}
