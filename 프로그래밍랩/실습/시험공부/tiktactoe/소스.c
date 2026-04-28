#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void drawBoard(char board[3][3]) {
	for (int i = 0; i < 3; i++) {
		printf("---|---|---\n");
		for (int j = 0; j < 3; j++) {
			printf(" %c ", board[i][j]);
			if (j < 2)
				printf("|");
		}
		printf("\n");
	}
	printf("---|---|---\n");
}

int main(void) {
	char board[3][3];
	char turn = 'X';
	int x, y;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			board[i][j] = ' ';
	}

	while (1) {
		drawBoard(board);
		printf("(x, y) 입력: ");
		scanf("%d %d", &x, &y);
		if (x < 0 || x> 2 || y < 0 || y > 2) {
			printf("잘못된 입력입니다.\n");
			continue;
		}

		if (board[x][y] == ' ') {
			if (turn == 'X') {
				board[x][y] = 'X';
				turn = 'O';
			}
			else {
				board[x][y] = 'O';
				turn = 'X';
			}
		}
		else {
			printf("이미 돌이 놓여있습니다\n");

		}
		

	}


}