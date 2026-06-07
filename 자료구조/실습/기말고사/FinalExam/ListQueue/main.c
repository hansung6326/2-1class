#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct QueueNode {
	element data;
	struct QueueNode* link;
}QueueNode;

typedef struct {
	QueueNode* front, * rear;
}LinkedQueueType;

void init(LinkedQueueType* q) {
	q->front = NULL;
	q->rear = NULL;
}

int is_empty(LinkedQueueType* q) {
	return q->front == q->rear;
}

void enqueue(LinkedQueueType* q, element data) {
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = data;
	temp->link = NULL;
	if (is_empty(q)) {
		q->front = temp;
		q->rear = temp;
	}
	else {
		q->rear->link = temp;
		q->rear = temp;
	}
}

element dequeue(LinkedQueueType* q) {
	QueueNode* temp = q->front;
	element data;
	if (is_empty(q)) {
		printf("queue is empty\n");
		exit(1);
	}
	data = temp->data;
	q->front = q->front->link;
	if (q->front == NULL)
		q->rear = NULL;
	free(temp);
	return data;
}
