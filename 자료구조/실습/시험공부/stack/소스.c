#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct StackType {
	element data[100];
	int top;
}StackType;

void init_stack(StackType* s) {
	s->top = -1;
}
int is_empty(StackType* s) {
	return (s->top == -1);
}
int is_full(StackType* s) {
	return (s->top == 99);
}
void push(StackType* s, element e) {
	if (is_full(s)) {
		printf("stack is full\n");
		return;
	}
	s->data[++s->top] = e;
}
element pop(StackType* s) {
	if (is_empty(s)) {
		printf("stack is empty\n");
		exit(1);
	}
	return s->data[s->top--];
}

int main(void) {

	StackType s;
	init_stack(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
}