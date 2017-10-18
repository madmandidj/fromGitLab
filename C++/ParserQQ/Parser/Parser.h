#ifndef __PARSER_H__
#define __PARSER_H__

#include <fstream>
#include <string>
#include <vector>

using namespace std;
//class ifstream;
class Tokenizer;
class Analyzer;

class Parser
{
	public:
		enum ParserState
		{
			ParserOK,
			ParserFAIL,
			ParserBAD,
			ParserEMPTY
		};
		
		Parser();
		virtual ~Parser();
		void		Parse(); //TODO: implement!! Place all other funcs in protected
		ParserState OpenFile();				//opens last file in m_fileNames
		void 		CloseFile();			//closes last file, and popback
		bool		ReadNextLine();			//reads into m_nextLine. returns true for eof
		size_t		GetCurLineNum() const;
		void		PushBackFileName(const string& _fileName);
		void		PopBackFileName();
		size_t		GetNumOfFiles() const;	
		void		PrintCurLine() const;
		
		
	protected:
		void 	DoGetOpt();		//TODO:implement

		
	private:
		//TODO:Tokenizer*			m_tokenizer;
		//TODO:Analyzer*			m_analyzer;
		ifstream*			m_ifStream;
		vector<string>*		m_fileNames;
		string				m_nextLine;
		size_t				m_curLineNum;
		
		Parser(const Parser& _parser);
		Parser& operator= (const Parser& _parser);
};

#endif /* #ifndef __PARSER_H__ */





