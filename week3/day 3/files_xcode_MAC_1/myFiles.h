#ifndef MYFILES_H
#define MYFILES_H

typedef char* strArr;

struct str_freq{
//    char* m_strArr;
    strArr* m_strArr;
    int* m_rep;
    int m_noe;
    int m_cap;
};
typedef struct str_freq str_freq;

int PrintRepeatedLetters(FILE* fp);
int PrintRepeatedStrings(FILE* fp);
int PrintLast(FILE* fp, int N);


#endif
