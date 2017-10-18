#include "Tokenizer.h"
#include <iostream>

using namespace std;

int main()
{
	Tokenizer tokenizer;
	char* c_str1 = "Yoo this [ is ] a ) te(st";
	char token;
	
	token = tokenizer.GetNextToken(c_str1);
	
	cout << token << endl;
	return 0;
}
