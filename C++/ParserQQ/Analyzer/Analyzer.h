#ifndef __ANALYZER_H__
#define __ANALYZER_H__

#include <string>
#include <vector>

using namespace std;

class Analyzer
{
	
	public:
			
		
		//TODO: error enum
		
		bool Analyze();
	
	protected:
		
	
	private:
//		Tokenizer*		m_tokenizer;
		vector<string>*	m_unresolvedTokens;
		vector<size_t>*	m_unresolvedLineNum;
		// set of defined variables (symbol table)
		size_t			m_currentLineNum;
		
		size_t			m_isNewFile;
		
		size_t			m_isTypeFlag;
		size_t			m_ifElseCount;
		size_t			m_curlyCount;
		size_t			m_roundCount;
		size_t			m_squareCount;
		size_t			m_plusCount;
		size_t			m_minusCount;
		
		set<string>*	m_legalTypes;
		set<string>*	m_legalKeyWords;
		set<string>*	m_legalOperators;
		set<string>*	m_declaredVariables;

//		static const char* const m_legalTypes[];
//		static const char* const m_legalKeyWords[]; 
//		static const char* const m_legalOperators[];
};

#endif /* #ifndef __ANALYZER_H__ */




