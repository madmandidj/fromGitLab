#include <stdio.h>
#include <string.h>
#include "strcat.h"

char *My_strcat(char *dest, const char *src)
{
    int index;
    int src_len = strlen(src) - 1;
    int dest_len = strlen(dest);
    for(index = src_len; index < src_len+dest_len; ++index)
    {
        dest[index] = src[index-src_len];
    }
    dest[index] = '\0';
    return dest;
}