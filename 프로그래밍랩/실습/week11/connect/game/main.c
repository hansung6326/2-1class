#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define MAP_W 25
#define MAP_H 18
#define MAX_STAGE 2 

char map[MAP_H][MAP_W];
int playerX, playerY;
int playerHP = 5;
int hasKey = 0;
int currentStage = 0;
int portalInX, portalInY;
int portalOutX, portalOutY;
int showKeyMsg = 0;

char startMap[MAX_STAGE][MAP_H][MAP_W] = {
    // 스테이지 1
    {
       "#########################",
        "#.......................#",
        "#.......................#",
        "#...................Q...#",
        "#.......................#",
        "#.....BBB...............#",
        "#.......................#",
        "#.....***...............#",
        "#.......................#",
        "#..........@............#",
        "#.......................#",
        "#....K..................#",
        "#.......................#",
        "#..........G............#",
        "#.......................#",
        "#..O....................#",
        "#.......................#",
        "#########################"
    },
    // 스테이지 2
    {
        "#########################",
        "#.....................O.#",
        "#.......#...***.........#",
        "#.#.#.B.#..#***#..#..##.#",
        "#.#.....#..#.K.#........#",
        "#.#.#####..#####.#####..#",
        "#...............B.......#",
        "############.#########.##",
        "#....***.......##.......#",
        "#.@..***..BBB..**B.B....#",
        "#....***......##......Q.#",
        "#....####################",
        "#....#.#........*.......#",
        "#.####.#.######.#.#####.#",
        "#.#....#......#.#....G..#",
        "#...####.####.#.#.#######",
        "#....B....**............#",
        "#########################"
    },
};

void initMap() {
    hasKey = 0;
    showKeyMsg = 0;
    playerHP = 5;

    for (int y = 0; y < MAP_H; y++) {
        for (int x = 0; x < MAP_W; x++) {
            if (startMap[currentStage][y][x] == '@') {
                playerX = x;
                playerY = y;
                map[y][x] = '.';
            }
            else if (startMap[currentStage][y][x] == 'O') {
                portalInX = x;
                portalInY = y;
                map[y][x] = 'O';
            }
            else if (startMap[currentStage][y][x] == 'Q') {
                portalOutX = x;
                portalOutY = y;
                map[y][x] = 'Q';
            }
            else {
                map[y][x] = startMap[currentStage][y][x];
            }
        }
    }
}

void drawMap() {
    system("cls");

    printf("STAGE %d\n", currentStage + 1);

    printf("HP : ");
    for (int i = 0; i < playerHP; i++) {
        printf("♥ ");
    }
    printf("\n");

    if (hasKey == 1) {
        printf("열쇠 : 보유중\n");
    }
    else {
        printf("열쇠 : 없음\n");
    }
    printf("\n");

    //출력되는 모양 변경
    for (int y = 0; y < MAP_H; y++) {
        for (int x = 0; x < MAP_W; x++) {
            if (x == playerX && y == playerY) {
                printf("@");
            }
            else if (map[y][x] == 'B') {
                printf("■");
            }
            else if (map[y][x] == 'O') {
                printf("O");
            }
            else if (map[y][x] == 'Q') {
                printf("Ø");
            }
            else {
                printf("%c", map[y][x]);
            }
        }
        printf("\n");
    }
    printf("\n이동: WASD 또는 방향키  |  R: 재시작  |  ESC: 종료\n");
    printf("포탈 :  O = 입구   Ø = 출구\n");

    if (showKeyMsg == 1) {
        printf("\n  !! 열쇠가 필요합니다 !!\n");
    }
}

void runGame() {
    initMap();

    while (1) {
        drawMap();

        if (playerHP <= 0) {
            system("cls");
            printf("=========================\n");
            printf("        GAME OVER        \n");
            printf("=========================\n");
            printf("\n");
            printf("  R : 재시작\n");
            printf("  ESC : 종료\n");

            int key = _getch();
            if (key == 'r' || key == 'R') {
                initMap();
                continue;
            }
            else {
                break;
            }
        }

        int key = _getch();

        if (key == 224 || key == 0) {
            key = _getch();
        }
        if (key == 'r' || key == 'R') {
            initMap();
            continue;
        }

        if (key == 27) break;

        int nx = playerX;
        int ny = playerY;

        if (key == 'w' || key == 'W' || key == 72) {
            ny--;
            showKeyMsg = 0;
        } 
        else if (key == 's' || key == 'S' || key == 80) {
            ny++;
            showKeyMsg = 0;
        } 
        else if (key == 'a' || key == 'A' || key == 75) {
            nx--;
            showKeyMsg = 0;
        } 
        else if (key == 'd' || key == 'D' || key == 77) {
            nx++;
            showKeyMsg = 0;
        }

        if (map[ny][nx] != '#') {

            // G 에 닿았을 때
            if (map[ny][nx] == 'G') {
                if (hasKey == 1) {
                    if (currentStage == MAX_STAGE - 1) {
                        system("cls");
                        printf("=========================\n");
                        printf("      GAME  CLEAR !      \n");
                        printf("   모든 스테이지 완료!   \n");
                        printf("=========================\n");
                        printf("\n");
                        printf("  R : 처음부터 다시\n");
                        printf("  ESC : 종료\n");

                        int k = _getch();
                        if (k == 'r' || k == 'R') {
                            currentStage = 0;
                            initMap();
                            continue;
                        }
                        else {
                            break;
                        }
                    }
                    // 다음 스테이지
                    else {
                        system("cls");
                        printf("=========================\n");
                        printf("      STAGE  CLEAR !     \n");
                        printf("=========================\n");
                        printf("\n");
                        printf("  다음 스테이지로 이동합니다...\n");
                        printf("  아무 키나 누르세요\n");
                        _getch();

                        currentStage++;
                        initMap();
                        continue;
                    }
                }
                else {
                    showKeyMsg = 1;
                }
            }

            // 열쇠 획득
            else if (map[ny][nx] == 'K') {
                hasKey = 1;
                map[ny][nx] = '.';
                playerX = nx;
                playerY = ny;
            }

            // 가시
            else if (map[ny][nx] == '*') {
                playerHP--;
                playerX = nx;
                playerY = ny;
            }

            // 블록 밀기
            else if (map[ny][nx] == 'B') {
                int bx = nx + (nx - playerX);
                int by = ny + (ny - playerY);

                if (map[by][bx] == '*') {
                    map[by][bx] = '.';
                    map[ny][nx] = '.';
                    playerX = nx;
                    playerY = ny;
                }
                else if (map[by][bx] == '.') {
                    map[by][bx] = 'B';
                    map[ny][nx] = '.';
                    playerX = nx;
                    playerY = ny;
                }
            }

            // 포탈
            else if (nx == portalInX && ny == portalInY) {
                playerX = portalOutX;
                playerY = portalOutY;
            }

            // 빈 칸
            else {
                playerX = nx;
                playerY = ny;
            }
        }
    }
}

int main() {
    system("cls");
    runGame();
    return 0;
}