#define _CRT_SECURE_NO_WARNINGS // Visual Studio scanf 에러 방지
#include <stdio.h>

// 보드를 화면에 그리는 함수 (하나의 루프)
void drawBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        printf("---|---|---\n");
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
    }
    printf("---|---|---\n");
}

int main() {
    // 1. 보드를 초기화한다
    char board[3][3];
    char turn = 'X'; // 'X' 플레이어부터 시작
    int x, y;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' '; // 빈 공간으로 초기화
        }
    }

    // 2. 게임 루프 시작
    while (1) {
        // 3. 보드를 화면에 표시한다
        drawBoard(board);

        // 4. 사용자로부터 좌표 x, y를 받는다.
        printf("(x, y) 좌표 입력 (0~2): ");
        if (scanf("%d %d", &x, &y) != 2) { // 숫자 입력 오류 처리
            while (getchar() != '\n'); // 입력 버퍼 비우기
            printf("잘못된 입력입니다. 숫자 0~2를 입력하세요.\n");
            continue;
        }

        // 보드 범위를 벗어난 경우 체크
        if (x < 0 || x > 2 || y < 0 || y > 2) {
            printf("오류: 좌표는 0, 1, 2 중에서 선택해야 합니다.\n");
            continue;
        }

        // 5. 만약 선택한 칸이 비어있다면
        if (board[x][y] == ' ') {
            // 6. 현재 차례가 'X'이면
            if (turn == 'X') {
                // 7. 해당 칸에 'X' 저장
                board[x][y] = 'X';
                turn = 'O'; // 차례 변경
            }
            // 8. 아니면(차례가 'O'이면)
            else {
                board[x][y] = 'O';
                turn = 'X'; // 차례 변경
            }
        }
        else {
            // 이미 돌이 놓여 있는 경우
            printf("오류: 이미 돌이 놓여 있는 자리입니다!\n");
        }
    }

    return 0;
}