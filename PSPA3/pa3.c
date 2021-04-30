#include <stdio.h>
#include <stdlib.h>
typedef struct _scholar {
	int department;
	int semester;
	int credits;
	int grad_requirements;
	int TSA; // total_scholarship_amount;
}ScholarList;

void PrintListState(ScholarList* list, int size);
int cmp(const void* a, const void* b)
{
	ScholarList* pa = (ScholarList*)a;
	ScholarList* pb = (ScholarList*)b;
	if (pa->TSA > pb->TSA)
		return 1;
	else if (pa->TSA < pb->TSA)
		return -1;
	else
		return 0;
}



int main()
{
	int num_of_students;
	int num_of_queries;
	int option;
	int department;
	int semester;
	int credits;
	int grad_requirements;
	int TSA;
	scanf("%d", &num_of_students);
	//printf("%d\n", num_of_students);
	ScholarList* list = (ScholarList*)malloc(sizeof(ScholarList) * num_of_students);
	for (int i = 0; i < num_of_students; i++) {
		scanf("%d %d %d %d %d", &list[i].department, &list[i].semester, &list[i].credits, &list[i].grad_requirements, &list[i].TSA);
	}
	PrintListState(list, num_of_students);
	scanf("%d", &num_of_queries);
	for (int i = 0; i < num_of_queries; i++) {
		scanf("%d %d %d %d %d %d", &option, &department, &semester, &credits,&grad_requirements, &TSA);
		int* item = (int*)bsearch(TSA, list, num_of_students, sizeof(ScholarList), cmp);
		//int index = list - item;
		printf("%d\n", *item);
		//printf("find: value: %d, index: %d\n", list[index].TSA, index);
		if (option == 1) { // exact
			
		}
		else if (option == 2) { //higher

		}
		else { // lower

		}
	}

	return 0;
}

void PrintListState(ScholarList* list, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d %d %d %d %d\n", list[i].department, list[i].semester, list[i].credits, list[i].grad_requirements, list[i].TSA);
	}
}