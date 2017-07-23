

typedef struct{
	char* name;
	int age;
} person;

typedef int (* familyProfession )(char*) ;

struct familyTree {
	int nMembers;
	person p[2];
	struct familyTree* next;
	familyProfession func;
/* 2 only for example, has to be person* p; */
/* points to another family */
/* all members of a family have the same proffesion */
};

typedef struct familyTree FamilyTree_t;


#include <stdio.h>
int Refua(char* name) { printf("I'm a doctor\n"); return 0; }
int Handasa(char* name) { printf("I'm an engineer\n"); return 0; }

FamilyTree_t Halakhmi = { 2, "Ilan", 28, "Gilad", 26, 0, Handasa};
FamilyTree_t Levi     = { 2, "David", 38, "Lea", 30, 0, Refua };

void DoIt(FamilyTree_t* ftPtr, char* name) {
	ftPtr->func(name);
}
int main() {
	DoIt(&Halakhmi , "Ilan");
	DoIt(&Levi , "David");
	return 1;
}

