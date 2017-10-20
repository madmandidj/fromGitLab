#ifndef __TOKENIZER_H__
#define __TOKENIZER_H__

#include <string>

using namespace std;

class Tokenizer
{
	public:
		Tokenizer(const string _delimiters);
		virtual ~Tokenizer();
		virtual bool 	GetNextToken(const string& _line); //returns true if end of line
		const string& 	GetCurToken() const;
		//TODO: Get and Set functions for all data members, so derived can access these.
	
	private:
		string	m_delimiters;
		size_t 	m_curPosition;
		string	m_curToken;
		
		Tokenizer(const Tokenizer& _tokenizer);
		Tokenizer& operator= (const Tokenizer& _tokenizer);
};


#endif /* #ifndef __TOKENIZER_H__ */










