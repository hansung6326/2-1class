#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
}DListNode;

void init(DListNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

void print_dlist(DListNode* phead) {
	DListNode* p;
	
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<-| |%d| |-> ", p->data);
	}
	printf("\n\n");
}

void dinsert(DListNode* before, element data) {
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}

void ddelete(DListNode* head, DListNode* removed) {
	if (removed == head)
		return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

DListNode* search(DListNode* head, element data) {
	DListNode* p;
	for (p = head->rlink; p != head; p = p->rlink) {
		if (p->data == data) {
			return p;
		}
	}
	return NULL;
}

int main() {
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	dinsert(head, 10); // head <-> 1
	dinsert(head, 20); // head <-> 2 <-> 1
	dinsert(head, 30);
	print_dlist(head);

	element data;
	while (1) {
		printf("탐색할 값(99999 입력 시 종료): ");
		scanf("%d", &data);

		if (data == 99999) 
			break;

		if (search(head, data) != NULL) {
			printf("%d가 리스트 안에 있습니다\n", data);
		}
		else {
			printf("%d가 리스트 안에 없습니다\n", data);
		}
		
	}
	return 0;
}
