#ifndef DYNARR_H
#define DYNARR_H

/*struct declaration*/
struct dynarr{
    int* arr;
    int cap;
    int noe;
};

struct dynarr* 	createDA(int capacity);	
int 			insert(struct dynarr* da1, int num);
void 			destroy(struct dynarr* da1);

#endif
