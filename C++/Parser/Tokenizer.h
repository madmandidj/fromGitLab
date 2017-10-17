#ifndef __TOKENIZER_H__
#define __TOKENIZER_H__

#include <string>

using namespace std;

class Tokenizer
{
	public:
		Tokenizer();
		~Tokenizer();
		string GetNextToken(string& _line);
	protected:
	
	
	private:
		size_t m_curLinePosition; //Maybe not needed
		static const char* const m_delimiters[];
		Tokenizer(const Tokenizer& _tokenizer);
		Tokenizer& operator= (const Tokenizer& _tokenizer);
};


#endif /* #ifndef __TOKENIZER_H__ */


