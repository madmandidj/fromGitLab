#ifndef __FILES_H__
#define __FILES_H__

typedef struct StringFreq
{
    char m_string[64];
    int m_freq;
}StringFreq;

int PrintCharFreq(FILE* fp);
int PrintStringFreq(FILE* fp);
int PrintLastNLines(FILE* fp, int N);

#endif /* #ifndef __FILES_H__ */
