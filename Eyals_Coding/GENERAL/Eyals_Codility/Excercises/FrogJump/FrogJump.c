

// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
#include <math.h>
int solution(int X, int Y, int D) {
    // write your code in C99 (gcc 6.2.0)
    return 0 != ((Y-X) % D) ? ((Y-X) / D) + 1 : (Y-X) / D;
}


