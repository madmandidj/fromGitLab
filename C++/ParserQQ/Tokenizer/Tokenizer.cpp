#include "Tokenizer.h"

const char* const m_delimitersArr[] = 
{
	"(",
	")",
	"{",
	"}"
	//TODO: add all delimiters
};

const char* const Tokenizer::m_delimiters = "(){}[]"; //TODO: add all delimiters


Tokenizer::Tokenizer()
{
	m_curPosition = 0;
}


Tokenizer::~Tokenizer(){}


char Tokenizer::GetNextToken(const string& _line)
{	
	bool isFound = false;
	
	while (isFound = false && m_curPosition != string::npos)
	{
		m_curPosition = _line.find_first_of(Tokenizer::m_delimiters, m_curPosition + 1);
	}
	
	return _line[m_curPosition];
}


void Tokenizer::ResetCurrentPosition()
{
	m_curPosition = 0;
}



