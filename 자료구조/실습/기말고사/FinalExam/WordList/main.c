#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[100];
}element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

void error(char* message) {
	printf("%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

//ListNode* insert(ListNode* head, ListNode* pre, element value) {
//	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
//	p->data = value;
//
//	p->link = pre->link;
//	pre->link = p;
//	return head;
//}

//ListNode* delete_first(ListNode* head) {
//	ListNode* removed;
//	if (head == NULL)
//		return NULL;
//	removed = head;
//	head = removed->link;
//	free(removed);
//	return head;
//}

//ListNode* delete(ListNode* head, ListNode* pre) {
//	ListNode* removed;
//	if (head == NULL)
//		return NULL;
//	removed = pre->link;
//	pre->link = removed->link;
//	free(removed);
//
//	return head;
//}

int main() {
	ListNode* head = NULL;
	element data;

	strcpy(data.name, "APPLE");
	head = insert_first(head, data);
	print_list(head);

	strcpy(data.name, "KIWI");
	head = insert_first(head, data);
	print_list(head);

	strcpy(data.name, "BANANA");
	head = insert_first(head, data);
	print_list(head);
}