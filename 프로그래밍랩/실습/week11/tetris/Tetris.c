#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

// 방향키 아스키 코드
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27

// 보드의 시작 위치
#define BX 5
#define BY 1

// 보드의 크기
#define BW 10
#define BH 20

// 커서 표시 여부
#define NOCURSOR 0
#define NORMALCURSOR 1

// 보드의 상태값
#define EMPTY 0
#define BRICK 1
#define WALL 2

// BOOL 타입 정의
typedef int BOOL;
#define TRUE 1
#define FALSE 0

// 좌표 구조체 선언
typedef struct Point {
	int x, y;
} Point;

// 테트리스 블록 정보 저장 (7개의 블록과 4개의 회전 상태)
// Shape[블록 번호][회전 상태][블록 4칸의 좌표]

Point Shape[][4][4] = {
	// 0번 블록: I모양
	{
		{{0,0},{1,0},{2,0},{-1,0}},
		{{0,0},{0,1},{0,-1},{0,-2}},
		{{0,0},{1,0},{2,0},{-1,0}},
		{{0,0},{0,1},{0,-1},{0,-2}}
	},

	// 1번 블록: 네모
	{
		{{0,0},{1,0},{0,1},{1,1}},
		{{0,0},{1,0},{0,1},{1,1}},
		{{0,0},{1,0},{0,1},{1,1}},
		{{0,0},{1,0},{0,1},{1,1}}
	},

	// 2번 블록: Z모양
	{
		{{0,0},{-1,0},{0,-1},{1,-1}},
		{{0,0},{0,1},{-1,0},{-1,-1}},
		{{0,0},{-1,0},{0,-1},{1,-1}},
		{{0,0},{0,1},{-1,0},{-1,-1}}
	},

	// 3번 블록: S모양
	{
		{{0,0},{-1,-1},{0,-1},{1,0}},
		{{0,0},{-1,0},{-1,1},{0,-1}},
		{{0,0},{-1,-1},{0,-1},{1,0}},
		{{0,0},{-1,0},{-1,1},{0,-1}}
	},

	// 4번 블록: L모양
	{
		{{0,0},{-1,0},{1,0},{-1,-1}},
		{{0,0},{0,-1},{0,1},{-1,1}},
		{{0,0},{-1,0},{1,0},{1,1}},
		{{0,0},{0,-1},{0,1},{1,-1}}
	},

	// 5번 블록: J모양
	{
		{{0,0},{1,0},{-1,0},{1,-1}},
		{{0,0},{0,1},{0,-1},{-1,-1}},
		{{0,0},{1,0},{-1,0},{-1,1}},
		{{0,0},{0,-1},{0,1},{1,1}}
	},

	// 6번 블록: T모양
	{
		{{0,0},{-1,0},{1,0},{0,1}},
		{{0,0},{0,-1},{0,1},{1,0}},
		{{0,0},{-1,0},{1,0},{0,-1}},
		{{0,0},{-1,0},{0,-1},{0,1}}
	}
};

int rot = 0;
char* arTile[] = { "  ", "■", "□" };
int board[BW + 2][BH + 2]; // 게임판 배열

void gotoxy(int x, int y) {
	COORD pos;

	pos.X = (SHORT)(x - 1);
	pos.Y = (SHORT)(y - 1);

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void DrawBoard() {
	for (int x = 0; x < BW + 2; x++) {
		for (int y = 0; y < BH + 2; y++) {
			gotoxy(BX + x * 2, BY + y);
			printf("%s", arTile[board[x][y]]);
		}
	}
}

void PrintBlock(int block, int startX, int startY)
{
	// 한 블록의 4칸 출력
	for (int i = 0; i < 4; i++) {
		int x = startX + Shape[block][rot][i].x * 2; // 콘솔 폭이 2칸이라 x좌표를 2배
		int y = startY + Shape[block][rot][i].y;

		gotoxy(x, y);
		printf("■");
	}
}

int main(void) {
	int ch;
	for (int x = 0; x < BW + 2; x++) {
		for (int y = 0; y < BH + 2; y++) {
			if (x == 0 || x == BW + 1 || y == BH + 1) {
				board[x][y] = WALL;
			}
			else {
				board[x][y] = EMPTY;
			}
				
		}
	}
	while (1) {
		system("cls");

		// 블록 7개를 화면에 출력하는 테스트 코드
		for (int i = 0; i < 7; i++) {
			gotoxy(0, 3 + i * 4); // 각 블록을 아래로 간격 두고 출력
			printf("블록 %d: ", i);

			PrintBlock(i, 15, 3 + i * 4); // 각 블록을 오른쪽에 출력
			printf("\n");
		}
		ch = _getch();
		if (ch == 224) {
			ch = _getch();

			if (ch == UP) {
				rot++;
				if (rot > 3)
					rot %= 4;
			}
			else {
				system("cls");
				DrawBoard();
				_getch();
			}
		}
	}

	
	system("cls");
	return 0;
}