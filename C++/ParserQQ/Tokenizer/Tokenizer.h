#ifndef __TOKENIZER_H__
#define __TOKENIZER_H__

#include <string>

using namespace std;

class Tokenizer
{
	public:
		Tokenizer();
		~Tokenizer();
		char 	GetNextToken(const string& _line);
		void	ResetCurrentPosition();
	protected:
		
	
	private:
		static const char* const 	m_delimitersArr[];
		static const char* const	m_delimiters;
		size_t 						m_curPosition;
		Tokenizer(const Tokenizer& _tokenizer);
		Tokenizer& operator= (const Tokenizer& _tokenizer);
};


#endif /* #ifndef __TOKENIZER_H__ */










