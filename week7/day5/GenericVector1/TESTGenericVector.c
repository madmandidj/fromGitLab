/*
Filename: 		TESTGenericVector.c 
Description:	Tests for Generic vector 
Created: 		03/08/17
Created by:		Eyal Alon
Last modified: 	03/08/17
Modified by:	Eyal Alon
*/

#include <stdio.h>
#include "GenericVector.h"


void TestGenericVector()
{
	size_t size = 10;
	size_t blockSize = 2;
	Vector* vec;
	vec = VectorCreate(size, blockSize);
	VectorDestroy(vec);
	return;
}

int main()
{
	TestGenericVector();
	return 1;
}































