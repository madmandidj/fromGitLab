#ifndef __ANALYZER_H__
#define __ANALYZER_H__

#include <string>
#include <vector>

using namespace std;

class Analyzer
{
	
	public:
			
		
		//TODO: error enum
		
		bool IsTokenLegal();
	
	protected:
		
	
	private:
		Tokenizer*		m_tokenizer;
		vector<string>*	m_unresolvedTokens;
		vector<size_t>*	m_unresolvedLineNum;
		
		size_t			m_currentErrNum;
		size_t			m_currentLineNum;
		size_t			m_curlyCount;
		size_t			m_roundCount;
		size_t			m_squareCount;
		size_t			m_ifCount;
		size_t			m_elseCount;
		size_t			m_plusCount;
		size_t			m_minusCount;
		size_t			m_equalsCount;
		size_t			m_rightCount;
		size_t			m_leftCount;
		static const char* const m_legalTypes[];
		static const char* const m_legalKeyWords[]; 
		static const char* const m_legalOperators[];
};

#endif /* #ifndef __ANALYZER_H__ */




