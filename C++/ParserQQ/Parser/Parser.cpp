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
	
	m_analyzer = new Analyzer(legalTypes, legalKeywords, legalOperators, predefinedTokens);
	if (0 == m_analyzer)
	{
		return; //Throw exception here? still not clear to me
	}
}


void Parser::CreateTokenizer()
{
	string _delimiters = "+-=<>*&;(){}[]  \t\r";
	
	m_tokenizer = new Tokenizer(_delimiters);
	
	if (0 == m_tokenizer)
	{
		return; //Throw exception here? still not clear to me
	}
	
}


Parser::Parser()
{	
	CreateTokenizer();
	
	CreateAnalyzer();
	
	m_nextLine = "";
	
	m_curLineNum = 0;
}


Parser::~Parser()
{
	if (m_ifStream.is_open())
	{
		m_ifStream.close();
	}	

	delete m_tokenizer;
	
	delete m_analyzer;
}


void Parser::GetFileNames(int _argc, char* _argv[])
{
	size_t index;
	
	string fileName;
	
	for (index = 1; index < (size_t)_argc; ++index)
	{
		fileName = _argv[index];
		
		if (fileName.compare(fileName.size() - 3, 3, ".qq"))
		{
			cout << fileName << " is not a valid .qq file" << endl;
			
			continue;
		}
	
		m_fileNames.push_back(_argv[index]);
	}
	
	return;
}


void Parser::Parse(int _argc, char* _argv[])
{
	Parser::ParserState result;
	
	bool isEndOfLine = false;

	GetFileNames(_argc, _argv);
	
	string token;
	
	while (0 < GetNumOfFiles())
	{
		result = OpenFile();
		
		cout << "xxxxxxxxxxxxxxxxxxxx" << endl;
		
		if (result == ParserBAD || result == ParserFAIL)
		{
			
			PopBackFileName();
			
			continue;
		}
		
		
		cout << "Starting to parse '" << m_fileNames[GetNumOfFiles()-1] << "'" << endl;
		cout << "********************" << endl;
	
		while (1)
		{
			ReadNextLine();
			
			if(m_ifStream.eof())
			{
				break;
			}
			
			while(!isEndOfLine)
			{
				isEndOfLine = m_tokenizer->GetNextToken(m_nextLine);
				
				if ("" == m_tokenizer->GetCurToken())
				{
					break;
				}
								
				m_analyzer->AnalyzeToken(m_tokenizer->GetCurToken(), GetCurLineNum());
			}
			
			isEndOfLine = false;
		}
		
		m_analyzer->DoEndOfFile();
		
		CloseFile();
		
		PopBackFileName();
	}
	
	return;
}


//TODO:double check why did this compile when bool declared as return value, but return is actually ParserState;
Parser::ParserState Parser::OpenFile() 
{
	if (0 == m_fileNames.size())
	{
		return ParserEMPTY;
	}
	
	string fileName = m_fileNames.back();
	
	m_ifStream.open(fileName.c_str(), ios_base::in);
	
	ParserState state;

	return state = (true == m_ifStream.good()) ? ParserOK : (true == m_ifStream.bad() ? ParserBAD : ParserFAIL);
}


void Parser::CloseFile()
{
	if (m_ifStream.is_open())
	{
		m_ifStream.close();
	}
	
	m_curLineNum = 0;
}


void Parser::ReadNextLine()
{
	std::getline(m_ifStream, m_nextLine);	
	
	++m_curLineNum;
}


size_t Parser::GetCurLineNum() const
{
	return m_curLineNum;
}


void Parser::PushBackFileName(const string& _fileName)
{
	m_fileNames.push_back(_fileName.c_str());
}


void Parser::PopBackFileName()
{
	m_fileNames.pop_back();
}


size_t Parser::GetNumOfFiles() const
{
	return m_fileNames.size();
}


void Parser::PrintCurLine() const
{
	cout << "m_nextLine = " << m_nextLine << endl;
}
















