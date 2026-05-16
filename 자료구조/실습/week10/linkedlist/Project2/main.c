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
// dinsert()는 데이터를 before 뒤에 삽입하기에 입력 순서의 역순으로 저장이 된다

// 입력 순서대로 데이터를 저장하기 위해 리스트 맨 뒤(before 앞)에 삽입하는 함수 추가
void dinsert_last(DListNode* before, element data) { 
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->llink = before->llink;
	newnode->rlink = before;
	before->llink->rlink = newnode;
	before->llink = newnode;
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

void reverse_print(DListNode* head) {
	DListNode* p;

	printf("데이터를 역순으로 출력: ");
	for (p = head->llink; p != head; p = p->llink) {
		printf("%d ", p->data);
	}
	printf("\n");

	printf("데이터를 입력 순서대로 출력: ");
	for (p = head->rlink; p != head; p = p->rlink) {
		printf("%d ", p->data);
	}
	printf("\n");
}

int main() {
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);

	printf("데이터의 개수를 입력하시오: ");

	int size, data;
	scanf("%d", &size);

	for (int i = 0; i < size; i++) {
		printf("노드 #%d의 데이터를 입력하시오: ", i + 1);
		scanf("%d", &data);
		dinsert_last(head, data);
	}
	reverse_print(head);

	while (head->rlink != head) {
		ddelete(head, head->rlink);
	}
	free(head);
	
	return 0;
}
