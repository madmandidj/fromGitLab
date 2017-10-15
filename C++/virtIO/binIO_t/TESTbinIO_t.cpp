
#include "binIO_t.h"
#include <iostream>
#include <string>

using namespace std;;

int main()
{
	string str1 = "FileTest2";
	string str2 = "wb";
	binIO_t test(str1, str2);
	
	FILE* test2;
	
	char c = 'c';
	
	test2 = fopen("binarytest2", "w+b");
	fwrite(&c, sizeof(char), 1, test2);
	fwrite(&c, sizeof(char), 1, test2);
	fwrite(&c, sizeof(char), 1, test2);
	fwrite(&c, sizeof(char), 1, test2);
	fclose(test2);
	
	char yo ='X';
	char inYo;
	try
	{
		test << yo;
	}	catch (int result)
	{
		cout << "caught <<" << endl;
	}
	
	test.Close();
	
	str2 = "rb";
	
	test.Open(str1, str2);
	
	try
	{	
		test >> inYo;
		test >> inYo;
	} catch (int result)
	{
		cout << "caught >>" << endl;
	}
	
	cout << inYo << endl;
	
	return 0;
}










