
#include <stdio.h>
#include <string.h>

int main() {
	FILE* 	fp = NULL;
	char 	name[128];
	int 	age;

	fp = fopen("Yosi", "w");
	if (NULL == fp) {
		return -1;
	}
	while(1) {
		printf("Please enter name anf age of a person: ");
		scanf("%s%d", name, &age);
		if (age < 1) break;
		fprintf(fp, "%s %d\n", name, age);
	}
	fclose(fp);

	fp = fopen("Yosi", "r");
	if (NULL == fp) {
		printf("Can't open file\n");
		return -1;
	}
	while(!feof(fp)) {
		fscanf(fp, "%s%d", name, &age);

		printf(" Name = %s and age = %d\n", name, age);
	}
	fclose(fp);

	return 0;
}








