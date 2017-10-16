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
		asciiFile << b;
	}catch(int result)
	{
		cout << "caught 1" << endl;
	}
	
	try
	{
		binFile << x;
		asciiFile << b;
	}catch(int result)
	{
		cout << "caught 2" << endl;
	}
	
	asciiFile.Close();
	
	asciiFile.Open(asciiFileName, asciiReadMode);
	
	binFile.Close();
	
	binFile.Open(binFileName, binReadMode);
	
	char readChar;
	int readInt;
	
	try
	{
		asciiFile >> readChar;
	}catch(int result)
	{
		cout << "caught 3" << endl;
	}
	
	cout << readChar << endl;
	
	try
	{
		binFile >> readInt;
	}catch(int result)
	{
		cout << "caught 4" << endl;
	}
	
	cout << readInt << endl;
	
	
	int n = 171;
	
	int m;
	
	binFile.Close();
	
	binFile.Open(binFileName, binWriteMode);
	
	try
	{
		binFile << &n, sizeof(int);
	}catch(int result)
	{
		cout << "caught 5" << endl;
	}
	
	binFile.Close();
	
	binFile.Open(binFileName, binReadMode);
	
	try
	{
		binFile >> &m, sizeof(int);
	}catch(int result)
	{
		cout << "caught 6" << endl;
	}
	
	cout << m << endl;
	
	
	float pI = 3.14;
	
	float mpI;
	
	binFile.Close();
	
	binFile.Open(binFileName, binWriteMode);
	
	try
	{
		binFile << &pI, sizeof(float);
	}catch(int result)
	{
		cout << "caught 7" << endl;
	}
	
	binFile.Close();
	
	binFile.Open(binFileName, binReadMode);
	
	try
	{
		binFile >> &mpI, sizeof(float);
	}catch(int result)
	{
		cout << "caught 8" << endl;
	}
	
	cout << mpI << endl;

	return 0;
}






