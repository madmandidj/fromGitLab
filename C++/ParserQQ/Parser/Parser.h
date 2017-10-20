#ifndef __PARSER_H__
#define __PARSER_H__

#include <fstream>
#include <string>
#include <vector>

using namespace std;
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
		virtual void Parse(int _argc, char* _argv[]); 
		
	protected:
		virtual void 	GetFileNames(int _argc, char* _argv[]);
		ParserState 	OpenFile();				//opens last file in m_fileNames
		void 			CloseFile();			//closes last file, and popback
		virtual void	CreateAnalyzer();
		virtual void	CreateTokenizer();
		virtual void	ReadNextLine();			//reads into m_nextLine
		size_t			GetCurLineNum() const;
		void			PushBackFileName(const string& _fileName);
		void			PopBackFileName();
		size_t			GetNumOfFiles() const;	
		void			PrintCurLine() const;
		//TODO: Get and Set functions for all data members, so derived can access these.
		
	private:
		Tokenizer*			m_tokenizer;
		Analyzer*			m_analyzer;
		ifstream			m_ifStream;
		vector<string>		m_fileNames;
		string				m_nextLine;
		size_t				m_curLineNum;
		
		Parser(const Parser& _parser);
		Parser& operator= (const Parser& _parser);
};

#endif /* #ifndef __PARSER_H__ */





