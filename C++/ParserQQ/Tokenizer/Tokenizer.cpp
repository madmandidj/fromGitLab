#include "Tokenizer.h"

const char* const Tokenizer::m_delimiters = "+-=<>*&;(){}[]  \t\r";

Tokenizer::Tokenizer()
{
	m_curPosition = 0;
	
	m_curToken = "";
}


Tokenizer::~Tokenizer(){}


bool Tokenizer::GetNextToken(const string& _line)
{	
	size_t position = m_curPosition;

	while(1)
	{
		position = _line.find_first_of(Tokenizer::m_delimiters, position);

		if (string::npos == position)
		{
			m_curToken = _line.substr(m_curPosition, _line.size() - position);
			
			m_curPosition = 0;
			
			return true;
		}
		else if (m_curPosition == position)
		{
			m_curToken = _line.substr(m_curPosition, 1);
			
			if(m_curToken == " " || m_curToken == "\t" || m_curToken == "\r" || m_curToken == "\n")
			{
				m_curToken = "";
				
				++position;

				m_curPosition = position;
				
				continue;
			}
			
			++m_curPosition;
			
			return false;
		}
		else
		{
			m_curToken = _line.substr(m_curPosition, position - m_curPosition);
			
			m_curPosition = position;

			return false;
		}
	}
}


const string& Tokenizer::GetCurToken() const
{
	return m_curToken;
}


