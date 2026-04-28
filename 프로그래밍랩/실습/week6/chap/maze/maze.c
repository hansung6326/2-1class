#include <stdio.h>
#include <conio.h>

char board[10][10] = {
{'#', '#', '#', '#', '.', '.', '.', '.', '.', '.' },
{'.', '.', '.', '.', '.', '#', '.', '.', '.', '.' },
{'#', '#', '#', '.', '#', '.', '.', '.', '.', '.' },
{'.', '.', '#', '.', '.', '#', '.', '.', '.', '.' },
{'.', '.', '#', '.', '.', '#', '.', '.', '.', '.' },
{'.', '.', '#', '.', '.', '#', '.', '.', '.', '.' },
{'.', '.', '.', '#', '.', '.', '#', '#', '.', '.' },
{'.', '.', '.', '.', '#', '.', '.', '.', '#', '#' },
{'.', '.', '.', '.', '.', '#', '.', '.', '.', '.' },
{'.', '.', '.', '.', '.', '#', '#', '#', '#', '#' }
};

void drawMap(char board[10][10], int xpos, int ypos) {
	system("cls");
	printf("왼쪽: <- 오른쪽: -> 위: ^ 아래: V\n");
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int y = 1;
	int x = 0;
	board[y][x] = '@';
    while (1) {
        system("cls");
        printf("왼쪽: <- 오른쪽: -> 위: ^ 아래: V\n");

        // 수정된 출력 루프
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                printf("%c", board[i][j]);  // [y][x]
            }
            printf("\n");
        }

        board[y][x] = '.'; // 현재 위치를 .으로 초기화

        int ch = getch();
        if (ch == 224) {
            int ch2 = getch();
            int xpos = x;
            int ypos = y;

            if (ch2 == 75) xpos--;      // 왼
            else if (ch2 == 80) ypos++; // 아래
            else if (ch2 == 72) ypos--; // 위
            else if (ch2 == 77) xpos++; // 오른쪽

            if (xpos >= 0 && xpos < 10 && ypos >= 0 && ypos < 10) {
                if (board[ypos][xpos] != '#') {
                    x = xpos;
                    y = ypos;
                }
            }
        }
        board[y][x] = '@';
    }
	return 0;

}