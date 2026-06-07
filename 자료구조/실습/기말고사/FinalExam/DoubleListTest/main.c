#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];

typedef struct DlistNode {
	element data;
	struct DlistNode* llink;
	struct DlistNode* rlink;
}DlistNode;

DlistNode* current;

void init(DlistNode* head) {
	head->llink = head;
	head->rlink = head;
}

void insert(DlistNode* before, element data) {
	DlistNode* newnode = (DlistNode*)malloc(sizeof(DlistNode));
	strcpy(newnode->data, data);
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}

void delete(DlistNode* head, DlistNode* removed) {
	if (removed == head)
		return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

void print(DlistNode* head) {
	for (DlistNode* p = head->rlink; p != head; p = p->rlink) {
		printf("<- | |%s| | ->", p->data);
	}
	printf("\n");
}

int main() {
	char ch;
	DlistNode* head = (DlistNode*)malloc(sizeof(DlistNode));
	init(head);
	
	insert(head, "Mamamia");
	insert(head, "Dancing Queen");
	insert(head, "Fernando");

	current = head->rlink;
	print(head);

	do {
		printf("current = %s\n", current->data);
		printf("\n명령어를 입력하시오(<, >, q): ");
		ch = getchar();
		if (ch == '<') {
			current = current->llink;
			if (current == head)
				current = current->llink;
		}
		else if (ch == '>') {
			current = current->rlink;
			if (current == head)
				current = current->rlink;
		}
		print(head);
		getchar();
	} while (ch != 'q');

}