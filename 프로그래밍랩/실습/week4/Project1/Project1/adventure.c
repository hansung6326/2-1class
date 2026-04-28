#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define ROWS 10
#define COLS 10

// 게임 보드를 화면에 그리는 함수
void drawGameboard(char map[ROWS][COLS]) {
    system("cls"); // 화면을 깨끗하게 지움 (Windows용)
    printf("이동 w(위) s(아래) a(왼쪽) d(오른쪽)\n"); // 깨진 한글 복구

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

// 괴물의 X 좌표 이동 결정 (플레이어 쪽으로 한 칸 접근)
int moveMonsterX(int mX, int pX) {
    if (mX > pX) return mX - 1;
    else if (mX < pX) return mX + 1;
    return mX;
}

// 괴물의 Y 좌표 이동 결정 (플레이어 쪽으로 한 칸 접근)
int moveMonsterY(int mY, int pY) {
    if (mY > pY) return mY - 1;
    else if (mY < pY) return mY + 1;
    return mY;
}

int main(void) {
    srand(time(NULL)); // 매번 다른 랜덤값을 위해 설정
    int pX = 1, pY = 1; // 플레이어 시작 위치
    char input;
    char map[ROWS][COLS];

    // 맵 초기화 (모두 . 으로 채움)
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            map[i][j] = '.';
        }
    }

    // 괴물 1, 2의 랜덤 위치 생성
    int mX1 = rand() % 10, mY1 = rand() % 10;
    int mX2 = rand() % 10, mY2 = rand() % 10;

    // 괴물이 시작 위치나 골인 지점에 생성되지 않도록 조정
    while ((mX1 == 1 && mY1 == 1) || (mX1 == 9 && mY1 == 9)) {
        mX1 = rand() % 10; mY1 = rand() % 10;
    }
    while ((mX2 == 1 && mY2 == 1) || (mX2 == 9 && mY2 == 9)) {
        mX2 = rand() % 10; mY2 = rand() % 10;
    }

    map[pX][pY] = '#';  // 플레이어 표시
    map[mX1][mY1] = 'M'; // 괴물 1 표시
    map[mX2][mY2] = 'M'; // 괴물 2 표시
    map[9][9] = 'G';     // 목적지(Goal) 표시

    while (1) {
        drawGameboard(map);
        input = _getch(); // 키보드 입력을 즉시 받음
        int iX = pX;
        int iY = pY;

        // 사용자 입력 처리
        switch (input) {
        case 'w': case 'W': iX--; break;
        case 's': case 'S': iX++; break;
        case 'a': case 'A': iY--; break;
        case 'd': case 'D': iY++; break;
        default: continue;
        }

        // 맵 경계를 벗어나면 무시
        if (iX < 0 || iX >= ROWS || iY < 0 || iY >= COLS)
            continue;

        // 플레이어의 이전 위치 지우기 및 이동
        map[pX][pY] = '.';
        pX = iX; pY = iY;

        // 괴물의 이전 위치 지우기
        map[mX1][mY1] = '.';
        map[mX2][mY2] = '.';

        // 괴물 이동 (50% 확률로 X축 혹은 Y축으로 접근)
        if (rand() % 2 == 0) mX1 = moveMonsterX(mX1, pX);
        else mY1 = moveMonsterY(mY1, pY);

        if (rand() % 2 == 0) mX2 = moveMonsterX(mX2, pX);
        else mY2 = moveMonsterY(mY2, pY);

        // 충돌 체크 (플레이어와 괴물이 같은 칸일 때)
        if ((mX1 == pX && mY1 == pY) || (mX2 == pX && mY2 == pY)) {
            map[pX][pY] = 'M';
            drawGameboard(map);
            printf("괴물에게 잡아 먹혔습니다!\n"); // 깨진 한글 복구
            break;
        }

        map[mX1][mY1] = 'M';
        map[mX2][mY2] = 'M';

        // 목적지 도착 체크
        if (pX == 9 && pY == 9) { // map[iX][iY] == 'G' 대신 좌표로 체크가 정확
            map[pX][pY] = '#';
            drawGameboard(map);
            printf("Game Clear!\n");
            break;
        }

        map[pX][pY] = '#'; // 현재 위치에 플레이어 표시
    }
    return 0;
}