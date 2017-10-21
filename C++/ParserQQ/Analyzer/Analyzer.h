#ifndef __ANALYZER_H__
#define __ANALYZER_H__

#include <string>
#include <set>

using namespace std;

class Analyzer
{
	
	public:
		Analyzer(set<string>& _legalTypes, 
					set<string>& _legalKeyWords, 
					set<string>& _legalOperators, 
					set<string>& _predefinedTokens);
							
		virtual ~Analyzer();
		virtual void AnalyzeToken(const string& _curToken, size_t _curLineNum);
		virtual void DoEndOfFile();
		virtual void ResetAnalyzer();
	
	protected:
		virtual bool NewFileRoutine(const string& _curToken);
		virtual bool PreDefinedTokenRoutine(const string& _curToken);
		virtual bool PreDefinedTypeRoutine(const string& _curToken);
		virtual bool DeclaredVariablesRoutine(const string& _curToken);
		virtual bool KeyWordRoutine(const string& _curToken);
		virtual bool OperatorRoutine(const string& _curToken);
		bool IsLegalCVar(const string& _curToken) const;
		void SetCurLineNum(size_t _curLineNum);
		//TODO: bool& 	GetIsNewFile() const;
		//TODO: bool& 	GetIsTypeFlag() const;
		//TODO: bool& 	GetIsKeyWord() const;
		//TODO: int& 	GetIfElseCount() const;
		//TODO: int& 	GetIfElseCount() const;
		//TODO: int& 	GetCurlyCount() const;
		//TODO: int& 	GetRoundCount() const;
		//TODO: int& 	GetSquareCount() const;
		//TODO: size_t& GetPlusCount() const;
		//TODO: size_t& GetMinusCount() const;
		//TODO: size_t& GetCurLineNum() const;
		//TODO: set<string>& GetLegalTypes() const;
		void PrintIllegalVar(const string& _curToken);

	private:
		bool			m_isNewFile;
		bool			m_isTypeFlag;
		bool			m_isKeyWord;
		int				m_ifElseCount;
		int				m_curlyCount;
		int				m_roundCount;
		int				m_squareCount;
		size_t			m_plusCount;
		size_t			m_minusCount;
		size_t			m_curLineNum;
		set<string>		m_legalTypes;
		set<string>		m_legalKeyWords;
		set<string>		m_legalOperators;
		set<string>		m_predefinedTokens;
		set<string>		m_declaredVariables;
		
		Analyzer(const Analyzer& _analyzer);
		Analyzer& operator= (const Analyzer& _analyzer);
};


inline void Analyzer::SetCurLineNum(size_t _curLineNum)
{
	m_curLineNum = _curLineNum;
}









#endif /* #ifndef __ANALYZER_H__ */




