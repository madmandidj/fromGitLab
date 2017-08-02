#ifndef __FILES_H__
#define __FILES_H__

/*
typedef struct String
{
    char m_string[64];
}String;

struct StringFreqTable{
    String* m_strArr;
    int m_elements;
};
typedef struct StringFreqTable SFT;  
*/

/*
typedef struct String
{
    char m_string[64];
    unsigned int length;
}String;

typedef struct StringFreqTable
{
    String m_strArr[256];
    int m_strFreqArr[256];
}StringFreqTable;
*/

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
