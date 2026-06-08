#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct Stack {
	element data;
	struct Stack* link;
}Stack;

typedef struct {
	Stack* top;
}LinkedStack;

void init(LinkedStack* s) {
	s->top = NULL;
}

int is_empty(LinkedStack* s) {
	return s->top == NULL;
}

void push(LinkedStack* s, element item) {
	Stack* node = (Stack*)malloc(sizeof(Stack));
	node->data = item;
	node->link = s->top;
	s->top = node;
	
}

element pop(LinkedStack* s) {
	Stack* node = s->top;
	element item = node->data;
	s->top = node->link;
	free(node);
	return item;
}

void print_stack(LinkedStack* s) {
	for (Stack* p = s->top; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("NULL \n");
}

int main() {
	LinkedStack head;
	init(&head);
	push(&head, 1); print_stack(&head);
	push(&head, 2); print_stack(&head);
	push(&head, 3); print_stack(&head);
	pop(&head); print_stack(&head);
	pop(&head); print_stack(&head);
	pop(&head); print_stack(&head);
}
