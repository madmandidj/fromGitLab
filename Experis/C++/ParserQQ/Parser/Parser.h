#ifndef __PARSER_H__
#define __PARSER_H__

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

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
		virtual void	CreateAnalyzer();
		virtual void	CreateTokenizer();
		virtual void	ReadNextLine();			//reads into m_nextLine
		ParserState 	OpenFile();				//opens last file in m_fileNames
		void 			CloseFile();			//closes last file, and popback
		size_t			GetNumOfFiles() const;	
		void			PushBackFileName(const string& _fileName);
		void			PopBackFileName();
		Tokenizer*		GetTokenizer() const;
		void			SetTokenizer(const Tokenizer* _tokenizer);
		Analyzer*		GetAnalyzer() const;
		void			SetAnalyzer(const Analyzer* _analyzer);
		ifstream&		GetIFstream() const;
		vector<string>&	GetFilesVector() const;
		string&			GetNextLine() const;	
		size_t&			GetCurLineNum() const;
		void			PrintCurLine() const;

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


inline void Parser::PushBackFileName(const string& _fileName)
{
	vector<string>& fileNames = GetFilesVector();
	
	fileNames.push_back(_fileName.c_str());
}


inline void Parser::PopBackFileName()
{
	vector<string>& fileNames = GetFilesVector();
	
	fileNames.pop_back();
}


inline size_t Parser::GetNumOfFiles() const
{
	vector<string>& fileNames = GetFilesVector();
	
	return fileNames.size();
}


inline Tokenizer* Parser::GetTokenizer() const {return m_tokenizer;}


inline void Parser::SetTokenizer(const Tokenizer* _tokenizer)
{
	if (0 == _tokenizer)
	{
		return;
	}
	
	m_tokenizer = (Tokenizer*)_tokenizer;
}


inline Analyzer* Parser::GetAnalyzer() const {return m_analyzer;}


inline void Parser::SetAnalyzer(const Analyzer* _analyzer)
{
	if (0 == _analyzer)
	{
		return;
	}
	
	m_analyzer = (Analyzer*)_analyzer;
}


inline ifstream& Parser::GetIFstream() const {return (ifstream&)m_ifStream;}


inline vector<string>& Parser::GetFilesVector() const {return (vector<string>&)m_fileNames;}


inline string& Parser::GetNextLine() const {return (string&)m_nextLine;}


inline size_t& Parser::GetCurLineNum() const {return (size_t&)m_curLineNum;}


inline void Parser::PrintCurLine() const
{
	string& nextLine = GetNextLine();
	
	cout << "m_nextLine = " << nextLine << endl;
}


#endif /* #ifndef __PARSER_H__ */





