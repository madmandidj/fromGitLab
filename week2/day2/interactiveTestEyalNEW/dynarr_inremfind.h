#ifndef DYNARR_H
#define DYNARR_H

typedef int* intPTR;
/*struct declaration*/
struct dynarr{
    intPTR* arr;
    int cap;
    int noe;
};

struct dynarr* 	createDA(int capacity);	
int 			insert(struct dynarr* da1, int* num);
void 			destroy(struct dynarr* da1);
int 			insert_byindex(struct dynarr* da1, int* num, int index);
int*			find(struct dynarr* da1, int numtofind);
int				remove_num(struct dynarr* da1, int numtoremove);

#endif
