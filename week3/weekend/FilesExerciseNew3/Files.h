#ifndef __FILES_H__
#define __FILES_H__

typedef struct StringFreq
{
    char m_string[64];
    int m_freq;
}StringFreq;

typedef struct StringFreqArr
{
    StringFreq* m_sF;
    int cap;
}StringFreqArr;

int PrintRepeatedLetters(FILE* fp);
int PrintRepeatedStrings(FILE* fp);
int PrintLast(FILE* fp, int N);

#endif /* #ifndef __FILES_H__ */
