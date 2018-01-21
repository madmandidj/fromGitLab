#include "Parser.h"
#include <iostream>

using namespace std;

int main()
{
	bool isEof;
	
	Parser::ParserState result;
	
	Parser parser;
	
	string file1 = "TEXT_1.txt";
	
	parser.PushBackFileName(file1);
	
	result = parser.OpenFile();
	
	cout << "open result = " << result << endl;
	
	parser.PrintCurLine();
	
	parser.GetNextLine();
	
	parser.PrintCurLine();
	
	parser.GetNextLine();
	
	parser.PrintCurLine();
	
	isEof = parser.GetNextLine();
	
	parser.PrintCurLine();
	
	isEof = parser.GetNextLine();
	
	parser.PrintCurLine();
	
	cout << "eof = " << isEof << endl;
	
	if (isEof)
	{
		parser.CloseFile();
	}
	
	result = parser.OpenFile();
	
	cout << "open result = " << result << endl;
	
	return 0;	
}
