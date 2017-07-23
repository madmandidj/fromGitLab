#ifndef __FILES_H__
#define __FILES_H__

typedef struct String
{
    char m_string[64];
}String;

typedef struct StringFreqTable
{
    String m_strArr[256];
    unsigned int m_freqArr[256];
}StringFreqTable;


int PrintRepeatedLetters(FILE* fp);
int PrintRepeatedStrings(FILE* fp);
int PrintLast(FILE* fp, int N);


#endif /* #ifndef __FILES_H__ */
