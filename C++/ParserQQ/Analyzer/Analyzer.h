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
		virtual void AnalyzeToken(const string& _curToken, size_t _curLineNum, bool isLastLine);
		void SetEndOfFileFlag();
	
	protected:
			virtual bool NewFileRoutine(const string& _curToken, size_t _curLineNum);
			virtual bool PreDefinedTokenRoutine(const string& _curToken, size_t _curLineNum);
			virtual bool PreDefinedTypeRoutine(const string& _curToken, size_t _curLineNum);
			virtual bool DeclaredVariablesRoutine(const string& _curToken, size_t _curLineNum);
			virtual bool KeyWordRoutine(const string& _curToken, size_t _curLineNum);
//TODO:			virtual bool OperatorRoutine(const string& _curToken, size_t _curLineNum);
			bool IsLegalCVar(const string& _curToken) const;
	
	private:
		bool			m_isNewFile;
		bool			m_isTypeFlag;
		bool			m_isKeyWord;
		bool			m_isOperator;
		bool			m_isPreDefinedTok;
		bool			m_isDeclaredVariable;
		int				m_ifElseCount;
		int				m_curlyCount;
		int				m_roundCount;
		int				m_squareCount;
		size_t			m_plusCount;
		size_t			m_minusCount;
		size_t			m_currentLineNum;
		set<string>		m_legalTypes;
		set<string>		m_legalKeyWords;
		set<string>		m_legalOperators;
		set<string>		m_predefinedTokens;
		set<string>		m_declaredVariables;
		
		Analyzer(const Analyzer& _analyzer);
		Analyzer& operator= (const Analyzer& _analyzer);
};

#endif /* #ifndef __ANALYZER_H__ */

inline void Analyzer::SetEndOfFileFlag()
{
	m_isNewFile = true;
}



