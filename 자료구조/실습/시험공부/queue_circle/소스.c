#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	int front, rear;
	element data[MAX_QUEUE_SIZE];
}QueueType;

void init_queue(QueueType* q) {
	q->front = 0;
	q->rear = 0;
}
int is_empty(QueueType* q) {
	return q->front == q->rear;
}
int is_full(QueueType* q) {
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}
void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		printf("queue is full\n");
		exit(1);
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
element dequeue(QueueType* q) {
	if (is_empty(q)) {
		printf("queue is empty\n");
		exit(1);
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
void queue_printf(QueueType* q) {
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

int main(void) {
	int element;
	QueueType q;

	init_queue(&q);
	printf("데이터 추가 단계 \n");
	while (!is_full(&q)) {
		printf("정수를 입력하시오: ");
		scanf("%d", &element);
		enqueue(&q, element);
		queue_printf(&q);
	}
	printf("큐는 포화상태입니다.\n\n");

	printf("데이터 삭제 단계\n");
	while (!is_empty(&q)) {
		element = dequeue(&q);
		printf("꺼내진 정수: %d\n", element);
		queue_printf(&q);
	}
	printf("큐는 공백상태입니다\n");

	return 0;
}