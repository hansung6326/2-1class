#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 100
#define MAZE_SIZE 6

typedef struct {
	short r;
	short c;
} StackObject;

StackObject stack[MAX_STACK_SIZE];
int top = -1;
//here: 현재 위치, entry: 시작 위치
StackObject here = { 1, 0 }, entry = { 1, 0 };

char maze[MAZE_SIZE][MAZE_SIZE] = {
{ '1', '1', '1', '1', '1', '1' },
{'e', '0', '1', '0', '0', '1' },
{'1', '0', '0', '0', '1', '1' },
{'1', '0', '1', '0', '1', '1' },
{'1', '0', '1', '0', '0', 'x' },
{'1', '1', '1', '1', '1', '1' },
};

void initialize() {
	top = -1;
}
int isEmpty() {
	return (top == -1);
}
int isFull() {
	return (top == (MAX_STACK_SIZE - 1));
}
void push(StackObject item) {
	if (isFull()) {
		printf("Stack is full\n");
	}
	else {
		stack[++top] = item;
	}
}
StackObject pop() {
	if (isEmpty()) {
		printf("Stack is empty\n");
	}
	else {
		return stack[top--];
	}
}
void PushLoc(int r, int c) {
	if (r < 0 || c < 0)
		return;
	if (maze[r][c] != '1' && maze[r][c] != '.') {
		StackObject tmp;
		tmp.r = r;
		tmp.c = c;
		push(tmp);
	}
}

void printMaze(char m[MAZE_SIZE][MAZE_SIZE]) {
	int r, c;
	for (r = 0; r < MAZE_SIZE; r++) {
		for (c = 0; c < MAZE_SIZE; c++) {
			if (r == here.r && c == here.c)
				printf("e ");
			else {
				if (m[r][c] == 0)
					printf("0 ");
				else
					printf("%c ", m[r][c]);
			}
		}
		printf("\n");
	}
	printf("\n\n");
}
void printStack() {
	for (int i = 0; i < 5; i++) {
		printf("|      |\n");
	}
	for (int i = top; i >= 0; i--) {
		printf("|(%01d, %01d)|\n", stack[i].r, stack[i].c);
	}
	printf("--------\n");
}

void main() {
	int r, c;
	here = entry;

	printMaze(maze);
	printStack();
	while (maze[here.r][here.c] != 'x') {
		printMaze(maze);
		r = here.r;
		c = here.c;
		maze[r][c] = '.'; //방문한 위치는 .으로 표시
		PushLoc(r, c + 1); // 오른 (가장 먼저 스택에 쌓이고, 가장 나중에 꺼냄)
		PushLoc(r, c - 1); // 왼
		PushLoc(r + 1, c); // 아래
		PushLoc(r - 1, c); // 위 (가장 나중에 넣어서 가장 먼저 pop됨)
		printStack();
		if (isEmpty()) //스택이 비어있으면 종료
			return;
		else
			here = pop();
		printMaze(maze);
		printStack();
		_getch();
	}
	printf("탈출 성공!\n");
}