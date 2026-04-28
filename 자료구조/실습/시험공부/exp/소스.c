#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef char element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;
void init_stack(StackType* s) {
	s->top = -1;
}
int is_empty(StackType* s) {
	return (s->top == -1);
}
int is_full(StackType* s) {
	return (s->top == MAX_STACK_SIZE - 1);
}
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "Stack is full\n");
		return;
	}
	else {
		s->data[++(s->top)] = item;
	}
}
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else {
		return s->data[(s->top)--];
	}
}
element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	return s->data[s->top];
}
int prec(char op) {
	switch (op) {
	case '(':
	case ')':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
	case '%':
		return 2;
	default:
		return -1;
	}
}
void infix_to_postfix(char data[]) {
	char ch, top_op;
	int len = strlen(data);
	StackType s;

	init_stack(&s);
	for (int i = 0; i < len; i++) {
		ch = data[i];
		if (ch == ' ')
			continue;
		switch (ch) {
		case '(':
			push(&s, ch);
			break;
		case ')':
			top_op = pop(&s);
			while (top_op != '(') {
				printf("%c ", top_op);
				top_op = pop(&s);
			}
			break;
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
			while (!is_empty(&s) && prec(ch) <= prec(peek(&s))) {
				printf("%c ", pop(&s));
			}
			push(&s, ch);
			break;
		default:
			printf("%c", ch);
			if (i == len - 1 || data[i + 1] < '0' || data[i + 1] >'9')
				printf(" ");
			break;
		}
	}
	while (!is_empty(&s))
		printf("%c ", pop(&s));
}

int main() {
	char* s = "5 * (10 + 2) % 2";
	printf("중위표시수식 %s \n", s);
	printf("후위표시수식 ");
	infix_to_postfix(s);
	printf("\n");

	return 0;
}
