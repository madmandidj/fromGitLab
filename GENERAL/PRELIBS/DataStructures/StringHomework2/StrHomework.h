#ifndef __STRHOMEWORK_H__
#define __STRHOMEWORK_H__
/*
Filename: 		StrHomework.h 
Description:	String Functions API
Created: 		01/08/17
Created by:		Eyal Alon
Last modified: 	02/08/17
Modified by:	Eyal Alon
*/

#include <stdlib.h> /* size_t */


/*
Desc:	Calculate string length	iteritavely
In:		char*: string		
Out:	size_t: string length
Err: 	0 if input string == NULL
*/
size_t StrLen(const char* _str);
/*
Desc:	Calculate string length	recursively
In:		char*: string		
Out:	size_t: string length
Err: 	0 if input string == NULL
*/
size_t StrLenRec(const char* _str);
/*TODO: find better return for error */
/*
Desc:	Compare two strings iteratively
In:		char*: string, char*: string		
Out:	int: == 0 if equal strings, > 0 if first char in s1 is larger, < 0 if first char in s1 is smaller
Err: 	0 if input strings == NULL 
*/
int StrCompare(const char* _s1, const char* _s2);
/*
Desc:	Compare two strings recursively
In:		char*: string, char*: string		
Out:	int: == 0 if equal strings, > 0 if first char in s1 is larger, < 0 if first char in s1 is smaller
Err: 	0 if input strings == NULL
*/
int StrCompareRec(const char* _s1, const char* _s2);
/*
Desc:	Copy string iteraticely
In:		char*: string, char*: string		
Out:	char*: to copied string
Err: 	NULL if any of input strings == NULL
*/
char* StrCopy(char* _destination, const char* _source);
/*
Desc:	Copy string recursively
In:		char*: string, char*: string		
Out:	char*: to copied string
Err: 	NULL if any of input strings == NULL
*/
char* StrCopyRec(char* _destination, const char* _source);
/*
Desc:	Copy N chars from string iteratively
In:		char*: string, char*: string		
Out:	char*: to copied string
Err: 	NULL if any of input strings == NULL
*/
char* StrNCopy(char* _destination, const char* _source, size_t _num);
/*
Desc:	Copy N chars from string recursively
In:		char*: string, char*: string		
Out:	char*: to copied string
Err: 	NULL if any of input strings == NULL
*/
char* StrNCopyRec(char* _destination, const char* _source, size_t _num);
/*
Desc:	Concatenate one string to the end of another string
In:		char*: string, char*: string		
Out:	char*: to copied string
Err: 	NULL if any of input strings == NULL
*/
char* StrConcat(char* _destination, const char* _source);
char* StrSubString(const char* _str, const char* _search);

#endif /* #ifndef __STRHOMEWORK_H__ */












