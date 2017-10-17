#include "Parser.h"
//#include "../Analyzer/Analyzer.h"
//#include "../Tokenizer/Tokenizer.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Parser::Parser()
{
	m_ifStream = new ifstream;
	
	if (0 == m_ifStream)
	{
		return;
	}
	
	m_fileNames = new vector<string>;
	
	if (0 == m_fileNames)
	{
		return;
	}
	
	m_nextLine = "";
	
	m_curLineNum = 0;
}

Parser::~Parser()
{
	if (m_ifStream->is_open())
	{
		m_ifStream->close();
	}	
	
	delete m_fileNames;
	
	delete m_ifStream;
}


//TODO:double check why did this compile when bool declared as return value, but return actually openResult;
Parser::ParserState Parser::OpenFile() 
{
	if (0 == m_fileNames->size())
	{
		return ParserEMPTY;
	}
	
	string fileName = m_fileNames->back();
	
	m_ifStream->open(fileName.c_str(), ios_base::in);
	
	ParserState state;

	return state = (true == m_ifStream->good()) ? ParserOK : (true == m_ifStream->bad() ? ParserBAD : ParserFAIL);
}


void Parser::CloseFile()
{
	if (m_ifStream->is_open())
	{
		m_ifStream->close();
	}
	
	PopBackFileName();
	
	m_curLineNum = 0;
	
	return;
}


bool Parser::ReadNextLine()
{
	std::getline(*m_ifStream, m_nextLine);	
	
	if (m_ifStream->eof())
	{
		return true;
	}
	
	++m_curLineNum;
	
	return false;
}


size_t Parser::GetCurLineNum() const
{
	return m_curLineNum;
}


void Parser::PushBackFileName(const string& _fileName)
{
	m_fileNames->push_back(_fileName.c_str());
	
	return;
}


void Parser::PopBackFileName()
{
	m_fileNames->pop_back();
	
	return;
}


size_t Parser::GetNumOfFiles() const
{
	return m_fileNames->size();
}


void Parser::PrintCurLine() const
{
	cout << "m_nextLine = " << m_nextLine << endl;
}
















