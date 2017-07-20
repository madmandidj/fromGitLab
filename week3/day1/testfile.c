#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUM_OF_ASCI_CHARS 50


int main()
{
    FILE* fp;
    char fname[]="newfile";
    char cur_char;
    int char_asci_val;
    char str[1024];
    int result_table[NUM_OF_ASCI_CHARS][2];
    int num_of_elements = 0;
    int i = 0;
    int str_index = 0;
    int table_index = 0;
    for(i = 0; i < NUM_OF_ASCI_CHARS; ++i)
    {
        result_table[i][1] = 0;
        result_table[i][2] = 0;
    }
    fp = fopen("testfile", "w");
    printf("here\n");
    fprintf(fp, "test");
    printf("here\n");
    fclose(fp);

    return 0;
}