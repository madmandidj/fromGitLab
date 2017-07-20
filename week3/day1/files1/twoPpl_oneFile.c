#include <stdio.h>
#include <string.h>

int main()
{
    char name1[64];
    char name2[64];
    char str_read[1024];
    char fname[]="myFirstFile";
    int age1;
    int age2;
    int isEnd;
    FILE* fp;
    printf("Enter name of person 1\n");
    scanf("%s",name1);
    printf("Enter age of person 1\n");
    scanf("%d", &age1);
    printf("Enter name of person 2\n");
    scanf("%s",name2);
    printf("Enter age of person 2\n");
    scanf("%d", &age2);
    fp = fopen(fname, "w+");
    fprintf(fp, "Name 1: %s, Age 2: %d,\nName 2: %s,  Age 2: %d", name1,age1,name2,age2);
    fclose(fp);
    fp = fopen(fname, "r");
    isEnd = feof(fp);
    while (isEnd != 1)
    {
        fscanf(fp,"%s", str_read);
        printf("%s", str_read);
        isEnd = feof(fp);
    }
    fclose(fp);
    

    return 0;
}