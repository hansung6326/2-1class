#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL\n");
}

ListNode* search_list(ListNode* head, element x) {
	ListNode* p = head;
	while (p != NULL) {
		if (p->data == x)
			return p;
		p = p->link;
	}
	return NULL;
}

ListNode* concat_list(ListNode* head1, ListNode* head2) {
	if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;
	ListNode* p;
	p = head1;
	while (p->link != NULL) {
		p = p->link;
	}
	p->link = head2;

	return head1;
}

ListNode* reverse(ListNode* head) {
	//p는 역순으로 만들 리스트, q는 현재 역순으로 만들 노드, r은 이미 역순으로 변경된 리스트
	ListNode* p, * q, * r; 
	p = head;
	q = NULL;
	r = NULL;

	while (p != NULL) {
		r = q;
		q = p;

		p = p->link;

		q->link = r;
	}
	return q;
	
}

int main() {
	ListNode* head = NULL;

	head = insert_first(head, 10);
	print_list(head);
	head = insert_first(head, 20);
	print_list(head);
	head = insert_first(head, 30);
	print_list(head);

	int num = 0;
	printf("숫자를 입력하세요: ");
	scanf("%d", &num);

	if (search_list(head, num) != NULL)
		printf("리스트에서 %d를 찾았습니다. \n", num);
	else
		printf("리스트에서 %d가 없습니다.\n", num);

	printf("\n");
	printf("리스트 두 개를 합치는 코드\n");

	ListNode* head1 = NULL;
	ListNode* head2 = NULL;

	head1 = insert_first(head1, 10);
	head1 = insert_first(head1, 20);
	head1 = insert_first(head1, 30);
	head2 = insert_first(head2, 40);
	head2 = insert_first(head2, 50);

	print_list(head1);
	print_list(head2);

	ListNode* total = concat_list(head1, head2);
	print_list(total);


	printf("\n리스트를 역순으로 만드는 코드\n");
	ListNode* head3 = NULL;
	ListNode* head4 = NULL;

	head3 = insert_first(head3, 10);
	head3 = insert_first(head3, 20);
	head3 = insert_first(head3, 30);
	print_list(head3);

	head4 = reverse(head3);
	print_list(head4);

	return 0;
}
