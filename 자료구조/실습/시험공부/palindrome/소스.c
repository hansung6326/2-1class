#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_QUEUE_SIZE 100

typedef char element;
typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
}QueueType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
void init_queue(QueueType* q) {
	q->rear = 0;
	q->front = 0;
}

int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}
void add_rear(QueueType* q, element item) {
	if (is_full(q)) {
		error("큐가 포화상태입니다.");
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
void add_front(QueueType* q, element item) {
	if (is_full(q)) {
		error("큐가 포화상태입니다.");
		return;
	}
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	q->data[q->front] = item;
}
element delete_front(QueueType* q) {
	if (is_empty(q)) {
		error("큐가 공백상태입니다.");
		return -1;
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
element delete_rear(QueueType* q) {
	if (is_empty(q)) {
		error("큐가 공백입니다.");
		return -1;
	}
	element item = q->data[q->rear];
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return item;
}
element get_front(QueueType* q) {
	if (is_empty(q)) {
		error("큐가 공백상태입니다.");
		return -1;
	}
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}
element get_rear(QueueType* q) {
	if (is_empty(q)) {
		error("큐가 공백상태입니다.");
		return -1;
	}
	return q->data[q->rear];
}

int main(void) {
	QueueType q;
	int i = 0, j = 0;
	char str[100];
	char word[100] = { 0 };
	int is_palindrome = 1;

	init_queue(&q);
	printf("문자를 입력하세요 : ");
	fgets(str, sizeof(str), stdin);

	while (str[i] != '\0') {
		if (isalpha(str[i])) {
			add_rear(&q, tolower(str[i]));
			word[j++] = tolower(str[i]);
		}
		i++;
	}

	while (!is_empty(&q)) {
		element first = delete_front(&q);
		if (is_empty(&q))
			break;
		element last = delete_rear(&q);
		printf("front 비교: %c, rear 비교: %c\n", first, last);
		if (first != last) {
			is_palindrome = 0;
			break;
		}
	}

	if (is_palindrome) {
		printf("%s은(는) 회문입니다.\n", word);
	}
	else {
		printf("%s은(는) 회문이 아닙니다.\n", word);
	}

	return 0;
}