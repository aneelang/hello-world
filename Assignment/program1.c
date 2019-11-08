#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct list {
	char* str;
	struct list* next;
}LIST;

int main(void){
	FILE* fp;
	char line[128];
	LIST* curr, *head;

	head = curr = NULL;
	fp = fopen("prg1_test.txt", "r");

	while(fgets(line, sizeof(line), fp)) {
		LIST* node = malloc(sizeof(LIST));
		node->str = strdup(line);
		node->next = NULL;

		if(head == NULL){
			curr = head = node;
		}
		else {
			curr = curr->next = node;
		}
	}
	fclose(fp);

	for(curr = head; curr; curr = curr->next) {
		printf("%s", curr->str);
	}
	return 0;
}

