#include "./asciiIO_t/asciiIO_t.h"
#include "./binIO_t/binIO_t.h"
#include <iostream>
#include <string>

using namespace std;;

int main()
{
	string asciiFileName = "asciiFile";
	string asciiWriteMode = "w";
	string asciiReadMode = "r";
	
	string binFileName = "binFile";
	string binWriteMode = "wb";
	string binReadMode = "rb";
	
	int a = 12345;
	int x = 54321;
	char b = 'b';
	char c = 'c';
		
	asciiIO_t asciiFile(asciiFileName, asciiWriteMode);
	binIO_t binFile(binFileName, binWriteMode);
	
	try
	{
		asciiFile << a;
	}catch(int result)
	{
		cout << "caught 1" << endl;
	}
	
	try
	{
		binFile << x;
	}catch(int result)
	{
		cout << "caught 2" << endl;
	}
	
	asciiFile.Close();
	
	asciiFile.Open(asciiFileName, asciiReadMode);
	
	binFile.Close();
	
	binFile.Open(binFileName, binReadMode);
	
	int readInt;
	
	try
	{
		asciiFile >> readInt;
	}catch(int result)
	{
		cout << "caught 3" << endl;
	}
	
	cout << readInt << endl;
	
	char readChar;
	
	try
	{
		binFile >> readInt;
	}catch(int result)
	{
		cout << "caught 4" << endl;
	}
	
	cout << readInt << endl;

	return 0;
}










