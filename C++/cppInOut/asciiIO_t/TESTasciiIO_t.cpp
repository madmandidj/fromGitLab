
#include "asciiIO_t.h"
#include <iostream>
#include <string>

int main()
{
	string str1 = "FileTest";
	string str2 = "w";
	asciiIO_t test(str1, str2);
	
	char yo ='X';
	
	test << yo;
	
	return 0;
}










