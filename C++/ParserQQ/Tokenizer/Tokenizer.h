#ifndef __TOKENIZER_H__
#define __TOKENIZER_H__

#include <string>

using namespace std;

class Tokenizer
{
	public:
		Tokenizer();
		virtual ~Tokenizer();
		bool 	GetNextToken(const string& _line); //returns true if end of line
		const string& GetCurToken() const;
		
	protected:
		
	
	private:
		static const char* const	m_delimiters;//TODO: change this to string or char*
		//TODO: add member for ignored delimiters 
		size_t 						m_curPosition;
		string						m_curToken;
		
		Tokenizer(const Tokenizer& _tokenizer);
		Tokenizer& operator= (const Tokenizer& _tokenizer);
};


#endif /* #ifndef __TOKENIZER_H__ */










