#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct StackType {
    element* data;
    int top;
    int capacity;
}StackType;

void init_stack(StackType* s) {
    s->top = -1;
    s->capacity = 1;
    s->data = (element*)malloc(sizeof(element) * s->capacity);
}
int is_empty(StackType* s) {
    return s->top == -1;
}
int is_full(StackType* s) {
    return s->top == s->capacity - 1;
}
void push(StackType* s, element item) {
    if (is_full(s)) {
        s->capacity *= 2;
        s->data = (element*)realloc(s->data, sizeof(element) * s->capacity);
        if (s->data == NULL) {
            printf("메모리 재할당 실패\n");
            exit(1);
        }
    }
    s->data[++(s->top)] = item;
}
element pop(StackType* s) {
    if (is_empty(s)) {
        printf("stack is empty\n");
        exit(1);
    }
    return s->data[s->top--];
}

int main(void) {
    StackType* s = (StackType*)malloc(sizeof(StackType));
    if (s == NULL) {
        fprintf(stderr, "스택 구조체 메모리 할당 실패\n");
        return 1;
    }

    init_stack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);

    printf("%d\n", pop(s)); // 3
    printf("%d\n", pop(s)); // 2
    printf("%d\n", pop(s)); // 1

    free(s->data); // 내부 배열 먼저 해제
    free(s);       // 구조체 해제
    return 0;
}