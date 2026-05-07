#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

bool is_empty(ListNode* head) {
	return head == NULL;
}

bool is_full() {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	if (p == NULL)
		return true;
	free(p);
	return false;
}

ListNode* add(ListNode* head, element item) {
	if (is_full()) {
		printf("memory is full\n");
		return head;
	}

	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = item;
	p->link = NULL;

	if (is_empty(head)) {
		head = p;
		return head;
	}

	if (item < head->data) {
		p->link = head;
		head = p;
		return head;
	}
	else {
		ListNode* pre = head;
		while (pre->link != NULL && pre->link->data < item) {
			pre = pre->link;
		}
		p->link = pre->link;
		pre->link = p;
		return head;
	}

}

ListNode* delete(ListNode* head, element item) {
	ListNode* removed;
	ListNode* pre = NULL;
	ListNode* p = head;

	while (p != NULL && p->data != item) {
		pre = p;
		p = p->link;
	}
	if (p == NULL) {
		printf("%d를 찾을 수 없습니다\n", item);
		return head;
	}

	removed = p;
	if (pre == NULL)
		head = removed->link;
	else
		pre->link = removed->link;

	free(removed);
	printf("%d가 삭제되었습니다.\n", item);
	return head;

}

ListNode* clear(ListNode* head) {
	ListNode* p, * removed;
	p = head;
	while (p != NULL) {
		removed = p;
		p = p->link;
		free(removed);
	}
	printf("리스트가 CLEAR 되었습니다.\n");
	return NULL;
}

bool is_in_list(ListNode* head, element item) {
	ListNode* p = head;
	while (p != NULL) {
		if (p->data == item)
			return true;
		p = p->link;
	}
	return false;

}

int get_length(ListNode* head) {
	int count = 0;
	for (ListNode* p = head; p != NULL; p = p->link)
		count++;
	return count;
}

void display(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL\n");
}

int main() {
	ListNode* head = NULL;

	printf("===== SortedList 테스트 =====\n\n");

	// 요소 추가 테스트
	printf("[요소 추가]\n");
	head = add(head, 30);   display(head);
	head = add(head, 10);   display(head);
	head = add(head, 50);   display(head);
	head = add(head, 20);   display(head);
	head = add(head, 40);   display(head);
	head = add(head, 5);    display(head);
	printf("\n");

	// 현재 상태 출력
	printf("[현재 리스트 상태]\n");
	display(head);
	printf("\n");

	// 검색 테스트
	printf("[검색 테스트]\n");
	printf("20이 리스트에 있는가? %s\n", is_in_list(head, 20) ? "예" : "아니오");
	printf("99가 리스트에 있는가? %s\n", is_in_list(head, 99) ? "예" : "아니오");
	printf("\n");

	// 길이 및 상태 확인
	printf("[상태 확인]\n");
	printf("리스트 길이: %d\n", get_length(head));
	printf("리스트가 비었는가? %s\n", is_empty(head) ? "예" : "아니오");
	printf("리스트가 꽉 찼는가? %s\n", is_full(head) ? "예" : "아니오");
	printf("\n");

	// 삭제 테스트
	printf("[요소 삭제]\n");
	head = delete(head, 10);    display(head);
	head = delete(head, 50);    display(head);
	head = delete(head, 99);    // 존재하지 않는 요소
	printf("\n");

	// 리스트 초기화
	printf("[리스트 초기화]\n");
	head = clear(head);
	display(head);
	printf("리스트가 비었는가? %s\n", is_empty(head) ? "예" : "아니오");
	printf("\n");

	// 초기화 후 새 요소 추가
	printf("[초기화 후 새 요소 추가]\n");
	head = add(head, 100);
	head = add(head, 25);
	head = add(head, 75);
	display(head);

	// 메모리 해제
	head = clear(head);
	return 0;
}