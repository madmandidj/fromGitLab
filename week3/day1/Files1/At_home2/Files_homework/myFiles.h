#ifndef MYFILES_H
#define MYFILES_H

struct str_freq{
    char* str;
    int rep;
    int cap;
};
typedef struct str_freq str_freq;
int PrintRepeatedLetters(FILE* fp);
int PrintRepeatedStrings(FILE* fp);
int PrintLast(FILE* fp, int N);


#endif