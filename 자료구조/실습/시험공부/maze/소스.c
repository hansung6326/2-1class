#include <stdio.h>
#define MAZE_SIZE 6

typedef struct {
	short r;
	short c;
}StackObject;
StackObject stack[100];
int top = -1;

StackObject here = { 1, 0 }, entry = { 1, 0 };

char maze[MAZE_SIZE][MAZE_SIZE] = {
{ '1', '1', '1', '1', '1', '1' },
{'e', '0', '1', '0', '0', '1' },
{'1', '0', '0', '0', '1', '1' },
{'1', '0', '1', '0', '1', '1' },
{'1', '0', '1', '0', '0', 'x' },
{'1', '1', '1', '1', '1', '1' },
};

void init_stack() {
	top = -1;
}
int is_empty() {
	return top == -1;
}
int is_full() {
	return top == 99;
}
void push(StackObject item) {
	if (is_full())
		return;
	stack[++top] = item;
}
StackObject pop() {
	if (is_empty())
		return;
	return stack[top--];
}

void pushLoc(int r, int c) {
	if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE)
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
				if (m[r][c] == '0')
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
	printf("\n\n");
}

int main() {
	int r, c;
	here = entry;

	printMaze(maze);
	printStack();
	while (maze[here.r][here.c] != 'x') {
		printMaze(maze);
		r = here.r;
		c = here.c;
		maze[r][c] = '.';
		pushLoc(r, c + 1);
		pushLoc(r, c - 1);
		pushLoc(r + 1, c);
		pushLoc(r - 1, c);
		printStack();
		if (is_empty())
			return;
		else
			here = pop();
		printMaze(maze);
		printStack();
		_getch();
	}
	printf("탈출 성공\n");

}