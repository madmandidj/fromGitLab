#include "Parser.h"
#include "../Analyzer/Analyzer.h"
#include "../Tokenizer/Tokenizer.h"
#include "../Analyzer/Analyzer.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void Parser::CreateAnalyzer()
{
const int NUM_OF_TYPES = 6;
	const int NUM_OF_KEYWOR = 11;
	const int NUM_OF_OPER = 11;
	const int NUM_OF_PREDEF = 14;	
	string strlegalTypes[NUM_OF_TYPES] = {"char", "short", "int", "long", "float", "double"};
	string strlegalKeywords[NUM_OF_KEYWOR] = {"if", "else", "for", "while", "class", "private", "public", "protected", "main", "const", "virtual"};
	string strlegalOperators[NUM_OF_OPER] = {"++", "--", "==", "->", "=", "+", "-", "*", "&", "<<", ">>"};
	string strpredefinedTokens[NUM_OF_PREDEF] = {"(", ")", "[", "]", "{", "}", ";", "<", ">", "=", "+", "-", "*", "&"};
	set<string> legalTypes;
	set<string> legalKeywords;
	set<string> legalOperators;
	set<string> predefinedTokens;
	
	for (int index = 0; index <NUM_OF_TYPES; ++index)
	{
		legalTypes.insert(strlegalTypes[index]);
	}
	
	for (int index = 0; index <NUM_OF_KEYWOR; ++index)
	{
		legalKeywords.insert(strlegalKeywords[index]);
		legalOperators.insert(strlegalOperators[index]);
	}
	
	for (int index = 0; index <NUM_OF_PREDEF; ++index)
	{
		predefinedTokens.insert(strpredefinedTokens[index]);
	}
	
	Analyzer* analyzer;
	
	analyzer = new Analyzer(legalTypes, legalKeywords, legalOperators, predefinedTokens);
	if (0 == analyzer)
	{
		return; //Throw exception here? still not clear to me
	}
	
	SetAnalyzer(analyzer);
}


void Parser::CreateTokenizer()
{
	string _delimiters = "+-=<>*&;(){}[]  \t\r";
	
	Tokenizer* tokenizer;
	
	tokenizer = new Tokenizer(_delimiters);
	
	if (0 == tokenizer)
	{
		return; //Throw exception here? still not clear to me
	}
	
	SetTokenizer(tokenizer);
}


Parser::Parser()
{	
	CreateTokenizer();
	
	CreateAnalyzer();

	string& nextLine = GetNextLine();
	nextLine = "";

	size_t& curLineNum = GetCurLineNum();

	curLineNum = 0;
}


Parser::~Parser()
{
	ifstream& ifStream = GetIFstream();

	if (ifStream.is_open())
	{
		ifStream.close();
	}
	
	Tokenizer* tokenizer = GetTokenizer();	

	delete tokenizer;
	
	Analyzer* analyzer = GetAnalyzer();
	
	delete analyzer;
}


void Parser::GetFileNames(int _argc, char* _argv[])
{
	size_t index;
	string fileName;
	vector<string>& fileNames = GetFilesVector();
	
	for (index = 1; index < (size_t)_argc; ++index)
	{
		fileName = _argv[index];
		
		if (fileName.compare(fileName.size() - 3, 3, ".qq"))
		{
			cout << fileName << " is not a valid .qq file" << endl;
			
			continue;
		}

		fileNames.push_back(_argv[index]);
	}
	
	return;
}


void Parser::Parse(int _argc, char* _argv[])
{
	Parser::ParserState result;
	bool isEndOfLine = false;
	string token;
	Tokenizer* tokenizer = GetTokenizer();
	Analyzer* analyzer = GetAnalyzer();
	ifstream& ifStream = GetIFstream();
	vector<string>& fileNames = GetFilesVector();
	string& nextLine = GetNextLine();
	size_t& curLineNum = GetCurLineNum();
	
	GetFileNames(_argc, _argv);
	
	while (0 < GetNumOfFiles())
	{
		result = OpenFile();
		
		cout << "xxxxxxxxxxxxxxxxxxxx" << endl;
		
		if (result == ParserBAD || result == ParserFAIL)
		{
			
			PopBackFileName();
			
			continue;
		}

		cout << "Starting to parse '" << (fileNames)[GetNumOfFiles()-1] << "'" << endl;
		cout << "********************" << endl;
	
		while (1)
		{
			ReadNextLine();

			if(ifStream.eof())
			{
				break;
			}
			
			while(!isEndOfLine)
			{
				isEndOfLine = tokenizer->GetNextToken(nextLine);
				
				if ("" == tokenizer->GetCurToken())
				{
					break;
				}

				analyzer->AnalyzeToken(tokenizer->GetCurToken(), curLineNum);
			}
			
			isEndOfLine = false;
		}

		analyzer->DoEndOfFile();
		
		CloseFile();
		
		PopBackFileName();
	}
	
	return;
}


//TODO:double check why did this compile when bool declared as return value, but return is actually ParserState;
Parser::ParserState Parser::OpenFile() 
{
	vector<string>& fileNames = GetFilesVector();
	ifstream& ifStream = GetIFstream();

	if (0 == fileNames.size())
	{
		return ParserEMPTY;
	}

	string fileName = fileNames.back();

	ifStream.open(fileName.c_str(), ios_base::in);
	
	ParserState state;

	return state = (true == ifStream.good()) ? ParserOK : (true == ifStream.bad() ? ParserBAD : ParserFAIL);
}


void Parser::CloseFile()
{
	ifstream& ifStream = GetIFstream();
	
	if (ifStream.is_open())
	{
		ifStream.close();
	}

	size_t& curLineNum = GetCurLineNum();
	curLineNum = 0;
}


void Parser::ReadNextLine()
{
	string& nextLine = GetNextLine();
	ifstream& ifStream = GetIFstream();
	size_t& curLineNum = GetCurLineNum();

	std::getline(ifStream, nextLine);

	++curLineNum;
}

















