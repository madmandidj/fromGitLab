#include "Parser.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	Parser parser;
//	Parser::ParserState result;
//	string file1 = "TEXT_1.txt";
//	string file2 = "TEXT_2.txt";
//	string file3 = "../Parser.qq";
//	bool isEof = false;
//	
//	//TODO: parser.DoGetOpt();
//	parser.PushBackFileName(file1);
//	parser.PushBackFileName(file2);
//	parser.PushBackFileName(file3);
//	
//	while (0 < parser.GetNumOfFiles())
//	{
//		result = parser.OpenFile();
//		cout << "open result = " << result << endl;
//	
//		while (!isEof)
//		{
//			isEof = parser.ReadNextLine();
//			cout << "current line num: " << parser.GetCurLineNum() << endl;
//			parser.PrintCurLine();	
//			
//			// TODO: m_tokenizer->tokenize(m_nextLine&, m_curLineNum)
//			//...
//			//...
//			
//		}
//		
//		isEof = false;
//		parser.CloseFile();
//	}

	parser.Parse();

	return 0;	
}
