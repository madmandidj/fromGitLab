#ifndef __PARSER_H__
#define __PARSER_H__

#include <string>
#include <vector>

using namespace std;

class Parser
{
	public:
		Parser();
		~Parser();
		bool 	OpenFile();
		bool 	CloseFile();
		string	GetNextLine(); //throw exception for eof
		
	protected:
		void DoGetOpt();
		
	private:
		Tokenizer*		m_tokenizer;
		Analyzer*		m_analyzer;
		FILE*			m_fp;
		vector<string>*	m_fileNames;
		Parser(const Parser& _parser);
		Parser& operator= (const Parser& _parser);
};

#endif /* #ifndef __PARSER_H__ */





