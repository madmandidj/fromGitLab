#include "Tokenizer.h"
#include <iostream>

using namespace std;

int main()
{
	Tokenizer tokenizer;
	string c_str1 = "Yo(o this [ is ] a ) te(st;;asdfgfadf. m\tm ,r .. . ..qq\r  ";
	bool isEndOfLine = false;
	string token = "";
	
	isEndOfLine = tokenizer.GetNextToken(c_str1.c_str());
	
	while (!isEndOfLine)
	{
		cout << tokenizer.GetCurToken() << endl;
		
		isEndOfLine = tokenizer.GetNextToken(c_str1.c_str());
	}
	
	if ("" != tokenizer.GetCurToken())
	cout << tokenizer.GetCurToken() << endl;
	
	return 0;
}
