
typedef int (* personProfession )(char*) ;

typedef struct{
	char* name;
	int age;
	personProfession func;
} person;



struct familyTree {
	int nMembers;
	person p[2];
	struct familyTree* next;
	/* familyProfession func; */
/* 2 only for example, has to be person* p; */
/* points to another family */
/* all members of a family have the same proffesion */
};

typedef struct familyTree FamilyTree_t;


#include <stdio.h>
#include <string.h>
int Refua(char* name) { printf("%s is a doctor\n", name); return 0; }
int Handasa(char* name) { printf("%s is an engineer\n", name); return 0; }

FamilyTree_t Halakhmi = { 2, "Ilan", 28, Handasa, "Gilad", 26, Refua, 0};
FamilyTree_t Levi     = { 2, "David", 38, Handasa, "Lea", 30, Refua, 0 };

void DoIt(FamilyTree_t* ftPtr, char* name) {
	int i;
	for (i = 0; i < ftPtr->nMembers; ++i)
	{
		if (strcmp(ftPtr->p[i].name, name) == 0)
		{
			ftPtr->p[i].func(name);
			return;
		}
	}
	printf("No family member with this name found\n");
	return;
}

int main() {
	DoIt(&Halakhmi , "Ilan");
	DoIt(&Halakhmi , "Gilad");
	DoIt(&Levi , "David");
	DoIt(&Levi , "Lea");
	DoIt(&Levi , "Erez");
	return 1;
}

