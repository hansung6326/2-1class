#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

// 보드를 화면에 출력하는 함수
void printBoard(char a[3][3]) {
	for (int i = 0; i < 3; i++) {
		printf("---|---|---\n");
		for (int j = 0; j < 3; j++) {
			printf(" %c ", a[i][j]);
			if (j < 2)
				printf("|");
		}
		printf("\n");
	}
	printf("---|---|---\n");
}

int main(void) {
	char board[3][3];
	int x, y;
	char player = 'X'; // 처음 시작은 'X' 플레이어

	// 보드를 공백(' ')으로 초기화
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}

	while (1) {
		// 깨진 부분: 좌표 입력 안내
		printf("(x, y) 좌표: ");
		scanf("%d %d", &x, &y);

		// 입력한 좌표가 비어있는지 확인
		if (board[x][y] == ' ') {
			if (player == 'X') {
				board[x][y] = 'X';
				player = 'O'; // 차례 교체
			}
			else {
				board[x][y] = 'O';
				player = 'X'; // 차례 교체
			}
		}
		else {
			// 깨진 부분: 이미 돌이 놓여 있는 자리일 경우
			printf("이미 입력된 자리입니다. 다시 입력하세요.\n");
		}

		printBoard(board); // 현재 보드 상태 출력
	}
	return 0;
}