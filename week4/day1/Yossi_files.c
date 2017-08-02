
#include <stdio.h>
#include <string.h>

int main() {
	FILE* 	fp = NULL;
	char 	name[128];
	int 	age;
	int 	nLng;

	fp = fopen("Yosi", "w");
	if (NULL == fp) {
		return -1;
	}
	while(1) {
		printf("Please enter name anf age of a person: ");
		scanf("%s%d", name, &age);
		if (age < 1) break;
//		fprintf(fp, "%s %d\n", name, age);
		nLng = strlen(name)+1;
		fwrite(&nLng, sizeof(int),1 , fp);
		fwrite(name, sizeof(char),nLng , fp);
		fwrite(&age, sizeof(int),1 , fp);

	}
	fclose(fp);

	fp = fopen("Yosi", "r");
	if (NULL == fp) {
		printf("Can't open file\n");
		return -1;
	}
	while(!feof(fp)) {
//		fscanf(fp, "%s%d", name, &age);
		fread(&nLng, sizeof(int),1 , fp);
		if (feof(fp)) break;
		fread(name, sizeof(char),nLng , fp);
		if (feof(fp)) break;
		fread(&age, sizeof(int),1 , fp);
		if (feof(fp)) break;

		printf(" Name = %s and age = %d\n", name, age);
	}
	fclose(fp);

	return 0;
}








