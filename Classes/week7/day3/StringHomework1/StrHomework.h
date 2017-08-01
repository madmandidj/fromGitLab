#ifndef __STRHOMEWORK_H__
#define __STRHOMEWORK_H__

#include <stdlib.h> /* size_t */


size_t StrLen(const char* _str);
size_t StrLenRec(const char* _str);
int StrCompare(const char* _s1, const char* _s2);
int StrCompareRec(const char* _s1, const char* _s2);
char* StrCopy(char* _destination, const char* _source);
char* StrCopyRec(char* _destination, const char* _source);
char* StrNCopy(char* _destination, const char* _source, size_t _num);
char* StrNCopyRec(char* _destination, const char* _source, size_t _num);
char* StrConcat(char* _destination, const char* _source);
char* StrSubString(const char* _str, const char* _search);

#endif /* #ifndef __STRHOMEWORK_H__ */












