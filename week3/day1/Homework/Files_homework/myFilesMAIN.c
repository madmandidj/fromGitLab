#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "myFiles.h"




int main()
{
    FILE* fp;
    fp = fopen("testfile", "w+");
    fprintf(fp,"Dani studies in Medical school and Yael studies in college\nThis is a new line");
    LetterOccurence(fp);
    fclose(fp);

    // FILE* fp;
    // char fname[]="myStringFile";
    // char cur_char;
    // int char_asci_val;
    // char str[MY_STRING_SIZE];
    // int result_table[NUM_OF_ASCI_CHARS][2];
    // int num_of_elements = 0;
    // int i = 0;
    // int str_index = 0;
    // int table_index = 0;
    // int is_new_char;
    // for(i = 0; i < NUM_OF_ASCI_CHARS; ++i)
    // {
    //     result_table[i][0] = 0;
    //     result_table[i][1] = 0;
    // }
    // fp = fopen("testfile", "w+");
    // fprintf(fp,"Dani studies in Medical school and Yael studies in college\nThis is a new line");
    // fseek(fp,0,0);
    // while(1)
    // {
    //     if (feof(fp)) break;
    //     else
    //     {
    //         str_index = 0;
    //         fgets(str, MY_STRING_SIZE, fp);
    //         printf("%s",str);
    //         while(str[str_index] != '\0')
    //         {
    //             if(islower(str[str_index]) || isupper(str[str_index]))
    //             {
    //                 table_index = 0;
    //                 is_new_char = 1;
    //                 while(table_index < num_of_elements)
    //                 {
    //                     if (str[str_index] == result_table[table_index][0])
    //                     {
    //                         printf("here\n");
    //                         ++(result_table[table_index][1]);
    //                         is_new_char = 0;
    //                         break;
    //                     }
    //                     ++table_index;
    //                 }
    //                 if (is_new_char == 1)
    //                 {
    //                     result_table[num_of_elements][0] = str[str_index];
    //                     result_table[num_of_elements][1] = 1;
    //                     ++num_of_elements;
    //                 }
    //             }
    //             ++str_index;
    //         }
    //     }
    // }
    // for(i = 0; i < num_of_elements; ++i)
    // {
    //     printf("Character %c, Amount %d\n", result_table[i][0],result_table[i][1]);
    // }
    return 0;
}