#include "Analyzer.h"
#include <iostream>
#include <string>
#include <set>
#include <ctype.h>

using namespace std;


Analyzer::Analyzer(set<string>& _legalTypes, 
					set<string>& _legalKeyWords, 
					set<string>& _legalOperators, 
					set<string>& _predefinedTokens)
{
	m_legalTypes = _legalTypes;
	
	m_legalKeyWords = _legalKeyWords;
	
	m_legalOperators = _legalOperators;
	
	m_predefinedTokens = _predefinedTokens;
	
	ResetAnalyzer();
}


Analyzer::~Analyzer(){}


void Analyzer::AnalyzeToken(const string& _curToken, size_t _curLineNum, bool isLastLine)
{	
	if (true == NewFileRoutine(_curToken, _curLineNum))
	{
		return;
	}

	if (true == PreDefinedTokenRoutine(_curToken, _curLineNum))
	{
		return;
	}
	
	if (true == PreDefinedTypeRoutine(_curToken, _curLineNum))
	{
		return;
	}
	
	if (true == KeyWordRoutine(_curToken, _curLineNum))
	{
		return;
	}
	
	if (true == OperatorRoutine(_curToken, _curLineNum))
	{
		return;
	}
	
	if (true == DeclaredVariablesRoutine(_curToken, _curLineNum))
	{
		return;
	}
	
	
	
	/*
	PSUEDO:
		check if newfile
		check if predefined token
		check if predefined type
		check if declared variable
		check if keyword
		check if operator
	*/
	
}




void Analyzer::DoEndOfFile()
{
	/*
	if (num of round dont match)
	{
		print error;
	}
	
	if (num of curly dont match)
	{
		print error;
	}
	
	if (num of square dont match)
	{
		print error;
	}
	*/
	
	if (m_curlyCount > 0)
	{
		cout << "You left " << m_curlyCount << " '{' unclosed" << endl;
	}
	
	if (m_roundCount > 0)
	{
		cout << "You left " << m_roundCount << " '(' unclosed" << endl;
	}
	
	if (m_squareCount > 0)
	{
		cout << "You left " << m_squareCount << " '[' unclosed" << endl;
	}
	
	m_isNewFile = true;
}









void Analyzer::ResetAnalyzer()
{
	m_isNewFile = true;
	
	m_isTypeFlag = false;
	
	m_ifElseCount = 0;
	
	m_curlyCount = 0;
	
	m_roundCount = 0;
	
	m_squareCount = 0;
	
	m_plusCount = 0;
	
	m_minusCount = 0;
	
	m_currentLineNum = 0;
}






bool Analyzer::NewFileRoutine(const string& _curToken, size_t _curLineNum)
{
		if (true == m_isNewFile)
		{
			if (*m_legalKeyWords.find(_curToken) == *m_legalKeyWords.find("main"))
			{			
				m_isNewFile = false;
			
				return true;
			}
			else
			{
				cout << "line " << _curLineNum << ": error, illegal declaration before 'main'" << endl; 
			}
		
			m_isNewFile = false;
		}
	
	return false;
}






bool Analyzer::PreDefinedTokenRoutine(const string& _curToken, size_t _curLineNum)
{
	if (m_predefinedTokens.end() != m_predefinedTokens.find(_curToken))
	{
		m_isPreDefinedTok = true;
		
		string tokenString = *m_predefinedTokens.find(_curToken);
		
		string keyString;
		
		keyString = "(";
		if (tokenString == keyString)
		{
			++m_roundCount;
			return true;
		}
		
		keyString = ")";
		if (tokenString == keyString)
		{
			--m_roundCount;
			
			if (-1 == m_roundCount)
			{
				m_roundCount = 0;
				cout << "line " << _curLineNum << ": error, is illegal '(' has to be before ')'" << endl;	
			}
			
			return true;
		}
		
		keyString = "[";
		if (tokenString == keyString)
		{
			++m_squareCount;
			
			return true;
		}
		
		keyString = "]";
		if (tokenString == keyString)
		{
			--m_squareCount;
			
			if (-1 == m_squareCount)
			{
				m_squareCount = 0;
				cout << "line " << _curLineNum << ": error, is illegal '[' has to be before ']'" << endl;	
			}
			return true;
		}
		
		keyString = "{";
		if (tokenString == keyString)
		{
			++m_curlyCount;
			
			return true;
		}
		
		keyString = "}";
		if (tokenString == keyString)
		{
			--m_curlyCount;
			
			if (-1 == m_curlyCount)
			{
				m_curlyCount = 0;
				cout << "line " << _curLineNum << ": error, is illegal '{' has to be before '}'" << endl;	
			}
			return true;
		}
		
		keyString = ";";
		if (tokenString == keyString)
		{
			return true;
		}
		
		keyString = "<";
		if (tokenString == keyString)
		{
			return true;
		}
		
		keyString = ">";
		if (tokenString == keyString)
		{
			return true;
		}
		
		keyString = "=";
		if (tokenString == keyString)
		{
			return true;
		}
		
		keyString = "+";
		if (tokenString == keyString)
		{
			++m_plusCount;
			
			if(3 == m_plusCount)
			{
				m_plusCount = 0;
				cout << "line " << _curLineNum << ": error, no operator +++" << endl;
			}
			return true;
		}
		
		keyString = "-";
		if (tokenString == keyString)
		{
			++m_minusCount;
			
			if(3 == m_minusCount)
			{
				m_minusCount = 0;
				cout << "line " << _curLineNum << ": error, no operator ---"<< endl;
			}
			
			return true;
		}
		
		keyString = "*";
		if (tokenString == keyString)
		{
			return true;
		}
		
		keyString = "&";
		if (tokenString == keyString)
		{
			return true;
		}
	}
	
	m_isPreDefinedTok = false;
		
	return false;
}









bool Analyzer::IsLegalCVar(const string& _curToken) const
{
	if (isdigit(_curToken.c_str()[0]) || 
			(!isalpha(_curToken.c_str()[0]) && ('_' != _curToken.c_str()[0])))
	{
		return false;
	}
	
	for (size_t index = 1; index < _curToken.size(); ++index)
	{
		if (!isalpha(_curToken.c_str()[index]) || 
			(!isdigit(_curToken.c_str()[index]) && !('_' != _curToken.c_str()[index])))
			{
				return false;
			}
	}
	
//	if (m_legalKeyWords.end() != m_legalKeyWords.find(_curToken))
//	{
//		
//		return false;
//	}
//	
//	if (m_legalOperators.end() != m_legalOperators.find(_curToken))
//	{
//		return false;
//	}
//	
//	if (m_legalTypes.end() != m_legalTypes.find(_curToken))
//	{
//		return false;
//	}
	
	return true;
}








bool Analyzer::PreDefinedTypeRoutine(const string& _curToken, size_t _curLineNum)
{
	if (m_legalTypes.end() != m_legalTypes.find(_curToken))
	{	
		if (true == m_isTypeFlag)
		{
			m_isTypeFlag = false;
			
			cout << "line " << _curLineNum << ": error, multiple type declaration"<< endl;
			
			return true;
		}
		
		m_isTypeFlag = true;
		
		return true;
	}
	
//	m_isTypeFlag = false;
	
	return false;
}









bool Analyzer::KeyWordRoutine(const string& _curToken, size_t _curLineNum)
{
	if (m_legalKeyWords.end() == m_legalKeyWords.find(_curToken))
	{
		m_isKeyWord = true;
		
		string tokenString = *m_legalKeyWords.find(_curToken);
		
		string keyString;
		
		keyString = "if";
		if (tokenString == keyString)
		{
			++m_ifElseCount;
			
			return false;
		}
		
		keyString = "else";
		if (tokenString == keyString)
		{
			--m_ifElseCount;
			
			if (0 > m_ifElseCount)
			{
				cout << "line " << _curLineNum << ": error, is illegal 'if' has to be before 'else'" << endl;
				
				m_ifElseCount = 0;	
			} 
			
			return false;
		}
		
		return false;
	}
	
	return false;
}








bool Analyzer::OperatorRoutine(const string& _curToken, size_t _curLineNum)
{
	if (m_legalOperators.end() == m_legalOperators.find(_curToken))
	{	
		
		return true;
	}
	
	return false;
}









bool Analyzer::DeclaredVariablesRoutine(const string& _curToken, size_t _curLineNum)
{	

	/*
	Psuedo
	
	
	
	*/



	if (true == IsLegalCVar(_curToken))
	{
//		if (m_legalKeyWords.end() != m_legalKeyWords.find(_curToken))
//		{
//			return false;
//		}
//	
//		if (m_legalOperators.end() != m_legalOperators.find(_curToken))
//		{
//			return false;
//		}
//	
//		if (m_legalTypes.end() != m_legalTypes.find(_curToken))
//		{
//			return false;
//		}	
		
	
		if (true == m_isTypeFlag)
		{
			if (m_declaredVariables.end() == m_declaredVariables.find(_curToken))
			{
				m_declaredVariables.insert(_curToken);
			}
			else
			{
				cout << "line " << _curLineNum << ": error, variable '"
					<< _curToken <<"' already declared" << endl;
			}
			
			return true;
		}
		
		if(true == m_isKeyWord)
		{
			cout << "variable keyword here1" << endl;
			
			return true;
		}
		
		if (m_declaredVariables.end() == m_declaredVariables.find(_curToken))
		{
			cout << "line " << _curLineNum << ": error, '"
				<< _curToken <<"' is not declared" << endl;
		}
	}
	
	if (true == m_isTypeFlag)
	{
		cout << "line " << _curLineNum << ": error, '" << _curToken << "' illegal variable name"<< endl;
		
		return true;
	}
	
	if(true == m_isKeyWord)
	{
		cout << "variable keyword here2" << endl;
		
		return true;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
//	if (true == m_isTypeFlag)
//	{
//		if (false == isLegalCVar)
//		{
//			cout << "line " << _curLineNum << ": error, '" << _curToken << "' illegal variable name"<< endl;
//		}
//		else
//		{
//			
//		}
//		
//		m_isTypeFlag = false;
//			
//		return true;
//	}
//	
//	if (true == m_isKeyWord)
//	{
//		m_isKeyWord = false;
//		
//		return true;
//	} 
	
	return false;
}

































