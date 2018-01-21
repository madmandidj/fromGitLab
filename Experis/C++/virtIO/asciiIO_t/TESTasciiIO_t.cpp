
#include "asciiIO_t.h"
#include <iostream>
#include <string>

using namespace std;;

int main()
{
	string str1 = "FileTest";
	string str2 = "w";
	asciiIO_t test(str1, str2);
	
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
	
	str2 = "r";
	
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










