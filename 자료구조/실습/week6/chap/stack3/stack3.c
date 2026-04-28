#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct {
    element* data;
    int capacity;
    int top;
} StackType;

void init_stack(StackType* s) {
    s->top = -1;
    s->capacity = 1; // 초기 용량 설정
    s->data = (element*)malloc(s->capacity * sizeof(element)); // 초기 메모리 할당
    if (s->data == NULL) {
        fprintf(stderr, "메모리 할당 실패\n");
        exit(1);
    }
}

int is_empty(StackType* s) {
    return (s->top == -1);
}

element pop(StackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

void push(StackType* s, element item) {
    if (s->top == (s->capacity - 1)) { // 스택이 가득 찼을 때
        s->capacity *= 2;
        s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
        if (s->data == NULL) {
            fprintf(stderr, "메모리 재할당 실패\n");
            exit(1);
        }
    }
    s->data[++(s->top)] = item; // 조건문 밖에서 항상 실행
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