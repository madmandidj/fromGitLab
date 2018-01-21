#include "Analyzer.h"
#include <iostream>
#include <set>
//#include <array>
//using namespace std; 

int main()
{
	const int NUM_OF_TYPES = 6;
	const int NUM_OF_KEYWOR = 11;
	const int NUM_OF_OPER = 11;
	const int NUM_OF_PREDEF = 14;	
		
	
	string strlegalTypes[NUM_OF_TYPES] = {"char", "short", "int", "long", "float", "double"};
	string strlegalKeywords[NUM_OF_KEYWOR] = {"if", "else", "for", "while", "class", "private", "public", "protected", "main", "const", "virtual"};
	string strlegalOperators[NUM_OF_OPER] = {"++", "--", "==", "->", "=", "+", "-", "*", "&", "<<", ">>"};
	string strpredefinedTokens[NUM_OF_PREDEF] = {"(", ")", "[", "]", "{", "}", ";", "<", ">", "=", "+", "-", "*", "&"};

	set<string> legalTypes;
	set<string> legalKeywords;
	set<string> legalOperators;
	set<string> predefinedTokens;
	
	for (int index = 0; index <NUM_OF_TYPES; ++index)
	{
		legalTypes.insert(strlegalTypes[index]);
	}
	
	for (int index = 0; index <NUM_OF_KEYWOR; ++index)
	{
		legalKeywords.insert(strlegalKeywords[index]);
		legalOperators.insert(strlegalOperators[index]);
	}
	
	for (int index = 0; index <NUM_OF_TYPES; ++index)
	{
		predefinedTokens.insert(strpredefinedTokens[index]);
	}
	
	
//	cout << *legalTypes.find(strlegalTypes[5]) << endl;
//	
//	cout << *predefinedTokens.find(strpredefinedTokens[5]) << endl;
	
	Analyzer analyzer(legalTypes, legalKeywords, legalOperators, predefinedTokens);
	
	analyzer.AnalyzeToken(*legalKeywords.find("main"), 1);
	
	analyzer.AnalyzeToken(*predefinedTokens.find("("), 1);
	
	analyzer.AnalyzeToken(*predefinedTokens.find(")"), 1);
	
	analyzer.AnalyzeToken(*predefinedTokens.find(")"), 1);
	
	analyzer.AnalyzeToken(*predefinedTokens.find(")"), 1);
	
	analyzer.AnalyzeToken(*predefinedTokens.find("]"), 1);
	
	analyzer.AnalyzeToken(*legalTypes.find("int"), 1);
	
	analyzer.AnalyzeToken("eyal", 1);
	
	return 0;
}







