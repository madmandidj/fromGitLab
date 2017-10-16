#include "./asciiIO_t/asciiIO_t.h"
#include "./binIO_t/binIO_t.h"
#include <iostream>
#include <string>

using namespace std;;

int main()
{
	string asciiFileName = "asciiFile";
	string asciiFileMode = "rw";
	
	string binFileName = "binFile";
	string binFileMode = "w+b";
	
//	char a = 'a';
	int a = 12345;
	char b = 'b';
	char c = 'c';
		
	asciiIO_t asciiFile(asciiFileName, asciiFileMode);
	binIO_t binFile(binFileName, binFileMode);
	
	try
	{
		asciiFile << a;
	}catch(int result)
	{
		cout << "caught 1" << endl;
	}
	
	try
	{
		binFile << b << c;
	}catch(int result)
	{
		cout << "caught 2" << endl;
	}
	
	int readInt;
	
	try
	{
		asciiFile >> readInt;
	}catch(int result)
	{
		cout << "caught 3" << endl;
	}
	
	char readChar;
	
	try
	{
		binFile >> readChar;
	}catch(int result)
	{
		cout << "caught 4" << endl;
	}
	
	cout << readChar << endl;
	
//	FILE* test2;
//	
//	char c = 'c';
//	
//	test2 = fopen("binarytest2", "w+b");
//	fwrite(&c, sizeof(char), 1, test2);
//	fwrite(&c, sizeof(char), 1, test2);
//	fwrite(&c, sizeof(char), 1, test2);
//	fwrite(&c, sizeof(char), 1, test2);
//	fclose(test2);
//	
//	char yo ='X';
//	char inYo;
//	try
//	{
//		test << yo;
//	}	catch (int result)
//	{
//		cout << "caught <<" << endl;
//	}
//	
//	test.Close();
//	
//	str2 = "rb";
//	
//	test.Open(str1, str2);
//	
//	try
//	{	
//		test >> inYo;
//		test >> inYo;
//	} catch (int result)
//	{
//		cout << "caught >>" << endl;
//	}
//	
//	cout << inYo << endl;
	
	return 0;
}










