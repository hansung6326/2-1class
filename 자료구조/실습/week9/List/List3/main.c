#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

bool is_empty(ListNode* list) {
	return list == NULL;
}

bool is_full() {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	if (p == NULL)
		return true;
	free(p);
	return false;
}

ListNode* add(ListNode* list, element item) {
	if (is_full()) {
		printf("memory is full\n");
		return list;
	}

	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = item;
	p->link = NULL;

	if (is_empty(list)) {
		list = p;
		return list;
	}

	if (item < list->data) {
		p->link = list;
		list = p;
		return list;
	}
	else {
		ListNode* pre = list;
		while (pre->link != NULL && pre->link->data < item) {
			pre = pre->link;
		}
		p->link = pre->link;
		pre->link = p;
		return list;
	}

}

ListNode* delete(ListNode* list, element item) {
	ListNode* removed;
	ListNode* pre = NULL;
	ListNode* p = list;

	while (p != NULL && p->data != item) {
		pre = p;
		p = p->link;
	}
	if (p == NULL) {
		printf("%d를 찾을 수 없습니다\n", item);
		return list;
	}

	removed = p;
	if (pre == NULL)
		list = removed->link;
	else
		pre->link = removed->link;

	free(removed);
	printf("%d가 삭제되었습니다.\n", item);
	return list;

}

ListNode* clear(ListNode* list) {
	ListNode* p, * removed;
	p = list;
	while (p != NULL) {
		removed = p;
		p = p->link;
		free(removed);
	}
	printf("리스트가 CLEAR 되었습니다.\n");
	return NULL;
}

bool is_in_list(ListNode* list, element item) {
	ListNode* p = list;
	while (p != NULL) {
		if (p->data == item)
			return true;
		p = p->link;
	}
	return false;

}

int get_length(ListNode* list) {
	int count = 0;
	for (ListNode* p = list; p != NULL; p = p->link)
		count++;
	return count;
}

void display(ListNode* list) {
	for (ListNode* p = list; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL\n");
}

int main() {
	ListNode* list = NULL;
	printf("단순 연결 리스트로 SortedList 구현하기\n");
	printf("학번: 2371172 안태호\n");

	int items[] = { 40, 10, 70, 25, 55, 9, 99 };
	int n = sizeof(items) / sizeof(items[0]);
	for (int i = 0; i < n; i++) {
		printf("add(%d) -> ", items[i]);
		list = add(list, items[i]);
		display(list);
	}
	printf("\n");

	list = clear(list);
	return 0;
}