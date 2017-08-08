
#include <stdio.h>
#include <string.h>

int main() {
	FILE* 	fp = NULL;
	char 	name[128];
	int 	age;
	int		size;
	char	nameToRead[128];
	int		ageToRead;
	int		sizeToRead;

	fp = fopen("Yosi", "w");
	if (NULL == fp) {
		return -1;
	}
	while(1) {
		printf("Please enter name anf age of a person: ");
		scanf("%s%d", name, &age);
		if (age < 1) 
		{
			break;
		}
		size = strlen(name)+1;
		fwrite(&size, sizeof(int), 1, fp);
		fwrite(name, 1, size, fp);
		fwrite(&age, sizeof(int), 1, fp);
	}
	fclose(fp);

	
	fp = fopen("Yosi", "r");
	if (NULL == fp) {
		printf("Can't open file\n");
		return -1;
	}
	while(!feof(fp)) {
		fread(&sizeToRead, 1, sizeof(int), fp);
		fread(nameToRead, sizeToRead, 1, fp);
		fread(&ageToRead, 1, sizeof(int), fp);
		printf(" Name = %s and age = %d\n", nameToRead, ageToRead);
	}
	fclose(fp);
	
	return 0;
}








