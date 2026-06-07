#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct DlistNode {
	element data;
	struct DlistNode* llink;
	struct DlistNode* rlink;
}DlistNode;

void init(DlistNode* head) {
	head->llink = head;
	head->rlink = head;
}

void insert(DlistNode* before, element data) {
	DlistNode* newnode = (DlistNode*)malloc(sizeof(DlistNode));
	newnode->data = data;
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
		printf("<- | |%d| | ->", p->data);
	}
	printf("\n");
}

int main() {
	DlistNode* head = (DlistNode*)malloc(sizeof(DlistNode));
	init(head);
	for (int i = 0; i < 5; i++) {
		insert(head, i);
		print(head);
	}
	printf("삭제\n");
	for (int i = 0; i < 5; i++) {
		print(head);
		delete(head, head->rlink);
	}
	free(head);
}