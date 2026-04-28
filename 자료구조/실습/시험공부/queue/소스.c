#include <stdio.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	int front, rear;
	element data[MAX_QUEUE_SIZE];
}QueueType;
void init_queue(QueueType* q) {
	q->front = -1;
	q->rear = -1;
}
int is_empty(QueueType* q) {
	return q->front == q->rear;
}
int is_full(QueueType* q) {
	return q->rear == MAX_QUEUE_SIZE - 1;
}
void enqueue(QueueType* q, element item) {
	if (is_full(q))
		return;
	q->data[++q->rear] = item;
}
element dequeue(QueueType* q) {
	if (is_empty(q))
		exit(1);
	return q->data[++q->front];
}


void queue_printf(QueueType* q) {
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (i <= q->front || i > q->rear)
			printf("   | ");
		else
			printf("%d | ", q->data[i]);
	}
	printf("\n");
}

int main(void) {
	QueueType q;

	init_queue(&q);

	enqueue(&q, 10);
	queue_printf(&q);
	enqueue(&q, 20);
	queue_printf(&q);
	enqueue(&q, 30);
	queue_printf(&q);

	dequeue(&q);
	queue_printf(&q);
	dequeue(&q);
	queue_printf(&q);
	dequeue(&q);
	queue_printf(&q);
	return 0;
}