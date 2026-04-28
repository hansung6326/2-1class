#include <stdio.h>
#include <string.h>
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
	return s->top == -1;
}
int is_full(StackType* s) {
	return s->top == 99;
}
void push(StackType* s, element item) {
	if (is_full(s)) {
		printf("stack is full\n");
		exit(1);
	}
	s->data[++s->top] = item;
}
element pop(StackType* s) {
	if (is_empty(s)) {
		printf("stack is empty\n");
		exit(1);
	}
	return s->data[s->top--];
}
int check_matching(const char* in) {
	StackType s;
	char ch, open_ch;

	init_stack(&s);
	for (int i = 0; i < strlen(in); i++) {
		ch = in[i];
		switch (ch) {
		case '(':
		case '{':
		case '[':
			push(&s, ch);
			break;
		case ')':
		case '}':
		case ']':
			if (is_empty(&s))
				return 0;
			else {
				open_ch = pop(&s);
				if ((open_ch == '(' && ch != ')') || (open_ch == '{' && ch != '}') ||
					(open_ch == '[' && ch != ']')) {
					return 0;
				}
				break;
			}
		}
	}
	if (!is_empty(&s))
		return 0;
	return 1;
}

int main(void) {

	char* p = "{ A[(i+1)] = 0; }";
	if (check_matching(p) == 1)
		printf("%s 괄호검사성공\n", p);
	else
		printf("%s 괄호검사실패\n", p);
	return 0;
}