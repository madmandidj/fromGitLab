#include <stdio.h>



int main()
{
    FILE* fp = NULL;
    char name[128];
    int age;

    fp = fopen("Yosi", "w");
    if (NULL == fp)
    {
        return -1;
    }
    while(1)
    {
        printf("Please enter name and age of a person: ");
        scanf("%s%d", name, &age);
        if (age < 1) break;
        fprintf(fp, "%s %d", name, age);
    }
    fclose(fp);

    fp = fopen("Yosi", "r");
    if (NULL == fp)
    {
         printf("cant open file");
        return -1;
    }
    while(1)
    {
        printf("Please enter name and age of a person: ");
        fscanf(fp,"%s%d", name, &age);
        if (feof(fp)) break;
        printf("Name %s %d", name, age);
    }
    fclose(fp);

}
