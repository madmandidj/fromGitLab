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
		void Parse(int _argc, char* _argv[]); 
		
	protected:
		void 		GetFileNames(int _argc, char* _argv[]); //TODO:implement
		ParserState OpenFile();				//opens last file in m_fileNames
		void 		CloseFile();			//closes last file, and popback
		void		ReadNextLine();			//reads into m_nextLine
		size_t		GetCurLineNum() const;
		void		PushBackFileName(const string& _fileName);
		void		PopBackFileName();
		size_t		GetNumOfFiles() const;	
		void		PrintCurLine() const;
		
	private:
		Tokenizer*			m_tokenizer;
		//TODO:Analyzer*			m_analyzer;
		ifstream*			m_ifStream;
		vector<string>*		m_fileNames;
		string				m_nextLine;
		size_t				m_curLineNum;
		
		Parser(const Parser& _parser);
		Parser& operator= (const Parser& _parser);
};

#endif /* #ifndef __PARSER_H__ */





