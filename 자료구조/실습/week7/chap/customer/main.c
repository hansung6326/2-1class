#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_QUEUE_SIZE 5

typedef struct {
	int id;
	int arrival_time;
	int service_time;
}Customer;

typedef Customer element;

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
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}
void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		error("큐가 포화상태입니다.");
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
element dequeue(QueueType* q) {
	if (is_empty(q)) {
		error("큐가 공백상태입니다.");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}


int main(void) {
	int minutes = 60;
	int total_wait = 0;
	int total_customers = 0;
	int service_time = 0;
	int service_customer;
	QueueType queue;
	init_queue(&queue);

	srand(time(NULL));
	for (int clock = 0; clock < minutes; clock++) {
		printf("현재 시각: %d\n", clock);
		if ((rand() % 10) < 3) {
			Customer customer;
			customer.id = total_customers++;
			customer.arrival_time = clock;
			customer.service_time = rand() % 3 + 1;
			enqueue(&queue, customer);
			printf("고객 %d이 %d분에 들어옵니다. 업무처리시간: %d분\n",
				customer.id, customer.arrival_time, customer.service_time);
		}
		if (service_time > 0) {
			printf("고객 %d이 업무처리중입니다.\n", service_customer);
			service_time--;
		}
		else {
			if (!is_empty(&queue)) {
				element customer = dequeue(&queue);
				service_customer = customer.id;
				service_time = customer.service_time;
				printf("고객 %d이 %d분에 업무를 시작합니다. 대기시간은 %d분이었습니다.\n",
					customer.id, clock, clock - customer.arrival_time);
				total_wait += clock - customer.arrival_time;
			}
		}
	}
	printf("\n============================\n");
	printf("총 서비스 고객 수: %d명\n", total_customers);
	printf("전체 대기 시간: %d분\n", total_wait);
	printf("평균 대기 시간: %.2f분\n", (float)total_wait / total_customers);
	printf("============================\n");

	return 0;
}