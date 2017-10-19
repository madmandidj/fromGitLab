#include "Parser.h"
#include "../Analyzer/Analyzer.h"
#include "../Tokenizer/Tokenizer.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Parser::Parser()
{
	m_tokenizer = new Tokenizer;
	if (0 == m_tokenizer)
	{
		return;
	}
	
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
	
	while (0 < GetNumOfFiles())
	{
		result = OpenFile();
		
		if (result == ParserBAD || result == ParserFAIL)
		{
			PopBackFileName();
			
			continue;
		}
	
		while (1)
		{
			ReadNextLine();
			
			if(m_ifStream.eof())
			{
				break;
			}
			cout << "current line num: " << GetCurLineNum() << endl;
			
			PrintCurLine();	//TODO: Remove after implementation done
			
			while(!isEndOfLine)
			{
				isEndOfLine = m_tokenizer->GetNextToken(m_nextLine);
				
				if ("" == m_tokenizer->GetCurToken())
				{
					break;
				}
				
				m_analyzer->AnalyzeToken(GetCurLineNum(), m_tokenizer->GetCurToken(), false);
				
				cout << "Token = " << m_tokenizer->GetCurToken() << endl; //TODO: Remove after implementation done
			}
			
			isEndOfLine = false;
		}
		
		m_analyzer->AnalyzeToken(GetCurLineNum(), "", true); //send lastline flag to analyzer
		
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
















