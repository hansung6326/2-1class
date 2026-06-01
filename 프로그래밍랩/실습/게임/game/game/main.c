#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define MAP_W 25
#define MAP_H 18
#define MAX_STAGE 2

#define VIEW_W 15
#define VIEW_H 11

char map[MAP_H][MAP_W];
int playerX, playerY;
int playerHP = 5;
int hasKey = 0;
int hasMap = 0;
int currentStage = 0;
int portalInX, portalInY;
int portalOutX, portalOutY;
int showKeyMsg = 0;
int stageClear[MAX_STAGE] = { 0, };

// ================= 공통 출력 유틸 =================

void gotoxy(int x, int y) {
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// ================= 타이틀 =================

void showTitle() {
    system("cls");

    // 콘솔 80x30 기준 고정 좌표
    // 아스키 아트 너비 약 64자 → startX = (80-64)/2 = 8
    int startX = 27;
    int startY = 12;

    const char* line1 = "  ██████   ██████  ███    ██ ███    ██ ███████  ██████ ████████ ";
    const char* line2 = " ██       ██    ██ ████   ██ ████   ██ ██      ██         ██    ";
    const char* line3 = " ██       ██    ██ ██ ██  ██ ██ ██  ██ █████   ██         ██    ";
    const char* line4 = " ██       ██    ██ ██  ██ ██ ██  ██ ██ ██      ██         ██    ";
    const char* line5 = "  ██████   ██████  ██   ████ ██   ████ ███████  ██████    ██    ";
    const char* line6 = "                PRESS ANY KEY TO START";
    const char* line7 = "                ESC : 종료";

    gotoxy(startX, startY);     printf("%s", line1);
    gotoxy(startX, startY + 1); printf("%s", line2);
    gotoxy(startX, startY + 2); printf("%s", line3);
    gotoxy(startX, startY + 3); printf("%s", line4);
    gotoxy(startX, startY + 4); printf("%s", line5);
    gotoxy(startX, startY + 6); printf("%s", line6);
    gotoxy(startX, startY + 7); printf("%s", line7);

    int ch = _getch();
    if (ch == 27) exit(0);
    system("cls");
}

// ================= 로비 / 메뉴 =================

int showLobby() {
    while (1) {
        system("cls");

        // 80x30 기준: 메뉴 중앙 정렬
        // "=== CONNECT LOBBY ===" 길이 21 → startX = (80-21)/2 = 29
        int startX = 50;
        int startY = 10;

        gotoxy(startX, startY);     printf("=== CONNECT LOBBY ===");
        gotoxy(startX, startY + 2); printf("1. 게임 시작");
        gotoxy(startX, startY + 3); printf("2. 이어하기");
        gotoxy(startX, startY + 4); printf("3. 조작법");
        gotoxy(startX, startY + 5); printf("4. 종료");
        gotoxy(startX, startY + 7); printf("번호를 선택하세요 (1-4): ");

        int ch = _getch();
        if (ch == '1') { currentStage = 0; return 1; }
        else if (ch == '2') return 2;
        else if (ch == '3') return 3;
        else if (ch == '4' || ch == 27) return 4;
    }
}

int showStageSelect() {
    system("cls");

    // "=== 이어하기 : 스테이지 선택 ===" 길이 약 33 → startX = (80-33)/2 = 23
    int startX = 38;
    int startY = 12;

    gotoxy(startX, startY);
    printf("=== 이어하기 : 스테이지 선택 ===");

    for (int i = 0; i < MAX_STAGE; i++) {
        int canPlay = (i == 0) || (stageClear[i - 1] == 1);

        char line[64];
        if (canPlay) {
            if (stageClear[i] == 1)
                sprintf(line, "%d. STAGE %d  (클리어)", i + 1, i + 1);
            else
                sprintf(line, "%d. STAGE %d  (잠금 해제)", i + 1, i + 1);
        }
        else {
            sprintf(line, "%d. STAGE %d  (잠김)", i + 1, i + 1);
        }

        gotoxy(startX, startY + 2 + i);
        printf("%s", line);
    }

    gotoxy(startX, startY + 2 + MAX_STAGE + 1);
    printf("플레이할 스테이지 번호를 선택하세요 (1-%d), ESC: 뒤로", MAX_STAGE);

    while (1) {
        int ch = _getch();
        if (ch == 27) return -1;
        else if (ch >= '1' && ch <= '0' + MAX_STAGE) {
            int sel = ch - '1';
            int canPlay = (sel == 0) || (stageClear[sel - 1] == 1);

            if (canPlay) {
                currentStage = sel;
                return sel;
            }
            else {
                gotoxy(startX, startY + 2 + MAX_STAGE + 3);
                printf("이 스테이지는 아직 잠겨 있습니다.");
            }
        }
    }
}

void showHowToPlay() {
    int page = 0;
    const int maxPage = 2;

    while (1) {
        system("cls");

        // 조작법 박스 → startX = 20, startY = 8
        int startX = 40;
        int startY = 10;

        gotoxy(startX, startY);
        printf("=== 조작법 (페이지 %d / %d) ===", page + 1, maxPage);

        if (page == 0) {
            gotoxy(startX, startY + 2); printf("이동 : W A S D 또는 방향키");
            gotoxy(startX, startY + 3); printf("재시작 : R");
            gotoxy(startX, startY + 4); printf("종료 : ESC");
        }
        else if (page == 1) {
            gotoxy(startX, startY + 2); printf("G : 목표 지점 (열쇠가 있어야 통과)");
            gotoxy(startX, startY + 3); printf("K : 열쇠");
            gotoxy(startX, startY + 4); printf("* : 가시 (밟으면 HP -1)");
            gotoxy(startX, startY + 5); printf("B / V : 밀 수 있는 블록");
            gotoxy(startX, startY + 6); printf("V + 가시 = 지도 아이템 생성");
            gotoxy(startX, startY + 7); printf("O / Ø : 포탈 입구 / 출구");
        }

        gotoxy(startX, startY + 9);
        if (page < maxPage - 1)
            printf("아무 키나 누르면 다음 페이지, ESC : 뒤로");
        else
            printf("아무 키나 누르면 로비로 돌아갑니다. (ESC도 가능)");

        int ch = _getch();
        if (ch == 27) break;
        else { page++; if (page >= maxPage) break; }
    }
}

// ================= 맵 데이터 =================

char startMap[MAX_STAGE][MAP_H][MAP_W] = {
    {
        "#########################",
        "#.......................#",
        "#.......................#",
        "#...................Q...#",
        "#.......................#",
        "#.....VBB...............#",
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
        "#.@..***..BBB..**V.B....#",
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
    hasMap = 0;
    playerHP = 5;

    for (int y = 0; y < MAP_H; y++) {
        for (int x = 0; x < MAP_W; x++) {
            if (startMap[currentStage][y][x] == '@') {
                playerX = x; playerY = y;
                map[y][x] = '.';
            }
            else if (startMap[currentStage][y][x] == 'O') {
                portalInX = x; portalInY = y;
                map[y][x] = 'O';
            }
            else if (startMap[currentStage][y][x] == 'Q') {
                portalOutX = x; portalOutY = y;
                map[y][x] = 'Q';
            }
            else {
                map[y][x] = startMap[currentStage][y][x];
            }
        }
    }
}

// ================= 전체 지도 보기 (M) =================

void showFullMap() {
    system("cls");

    // MAP_W=25, 이모지 2칸씩 → 실제 출력 너비 50
    // 80열 기준 startX = (80-50)/2 = 15
    // MAP_H=18 + 상하 여백 → startY = (30-22)/2 = 4
    int startX = 35;
    int startY = 4;

    gotoxy(startX, startY);
    printf("=== 전체 지도 ===");

    int mapStartY = startY + 2;
    for (int y = 0; y < MAP_H; y++) {
        gotoxy(startX, mapStartY + y);
        for (int x = 0; x < MAP_W; x++) {
            if (x == playerX && y == playerY)      printf("👤");
            else if (map[y][x] == '#')             printf("🧱");
            else if (map[y][x] == 'B' || map[y][x] == 'V') printf("📦");
            else if (map[y][x] == 'K')             printf("🔑");
            else if (map[y][x] == 'G')             printf("🚪");
            else if (map[y][x] == 'T')             printf("📜");
            else if (map[y][x] == 'O')             printf("🔵");
            else if (map[y][x] == 'Q')             printf("🔴");
            else if (map[y][x] == '*')             printf("❌");
            else if (map[y][x] == '.')             printf("  ");
            else                                   printf("%c ", map[y][x]);
        }
    }

    gotoxy(startX, mapStartY + MAP_H + 1);
    printf("현재 위치: @   |   아무 키나 누르면 돌아갑니다.");

    _getch();
    system("cls");
}

// ================= 뷰포트 기반 맵 그리기 =================

void drawMap() {
    // 뷰포트 이모지 출력 너비: VIEW_W(15) * 2 = 30
    // UI 포함 전체 높이: VIEW_H(11) + 상단5줄 + 하단5줄 = 21
    // 80열 기준: startX = (80-30)/2 = 25
    // 30행 기준: startY = (30-21)/2 = 4
    int startX = 35;
    int startY = 4;

    // 플레이어 기준 뷰포트 계산
    int viewX = playerX - VIEW_W / 2;
    int viewY = playerY - VIEW_H / 2;
    if (viewX < 0) viewX = 0;
    if (viewY < 0) viewY = 0;
    if (viewX + VIEW_W > MAP_W) viewX = MAP_W - VIEW_W;
    if (viewY + VIEW_H > MAP_H) viewY = MAP_H - VIEW_H;
    if (viewX < 0) viewX = 0;
    if (viewY < 0) viewY = 0;

    int drawW = VIEW_W < MAP_W ? VIEW_W : MAP_W;
    int drawH = VIEW_H < MAP_H ? VIEW_H : MAP_H;

    // 상단 UI
    gotoxy(startX, startY);
    printf("STAGE %d", currentStage + 1);

    gotoxy(startX, startY + 1);
    printf("                                        "); // 잔상 제거
    gotoxy(startX, startY + 1);
    printf("HP : ");
    for (int i = 0; i < playerHP; i++) printf("♥ ");

    gotoxy(startX, startY + 2);
    if (hasKey) printf("열쇠 : 보유중       ");
    else        printf("열쇠 : 없음         ");

    gotoxy(startX, startY + 3);
    if (hasMap) printf("지도 : 보유중 (M 키로 보기)");
    else        printf("지도 : 없음                ");

    // 맵(뷰포트)
    int mapStartY = startY + 5;
    for (int sy = 0; sy < drawH; sy++) {
        int my = viewY + sy;
        gotoxy(startX, mapStartY + sy);
        for (int sx = 0; sx < drawW; sx++) {
            int mx = viewX + sx;
            if (mx == playerX && my == playerY)             printf("👤");
            else if (map[my][mx] == '#')                    printf("🧱");
            else if (map[my][mx] == 'B' || map[my][mx] == 'V') printf("📦");
            else if (map[my][mx] == 'K')                    printf("🔑");
            else if (map[my][mx] == 'G')                    printf("🚪");
            else if (map[my][mx] == 'T')                    printf("📜");
            else if (map[my][mx] == 'O')                    printf("🔵");
            else if (map[my][mx] == 'Q')                    printf("🔴");
            else if (map[my][mx] == '*')                    printf("❌");
            else if (map[my][mx] == '.')                    printf("  ");
            else                                            printf("%c ", map[my][mx]);
        }
    }

    // 하단 UI
    gotoxy(startX, mapStartY + drawH + 1);
    printf("이동: WASD 또는 방향키  |  R: 재시작  |  ESC: 종료");
    gotoxy(startX, mapStartY + drawH + 2);
    printf("포탈 :  O = 입구   Q = 출구");
    gotoxy(startX, mapStartY + drawH + 4);
    if (showKeyMsg) printf("  !! 열쇠가 필요합니다 !!");
    else            printf("                              ");
}

// ================= 게임 진행 =================

void runGame() {
    initMap();

    while (1) {
        drawMap();

        // GAME OVER 체크
        if (playerHP <= 0) {
            system("cls");

            // "=========================" 길이 25 → startX = (80-25)/2 = 27
            int startX = 45;
            int startY = 12;

            gotoxy(startX, startY);     printf("=========================");
            gotoxy(startX, startY + 1); printf("        GAME OVER        ");
            gotoxy(startX, startY + 2); printf("=========================");
            gotoxy(startX, startY + 4); printf("  R : 재시작");
            gotoxy(startX, startY + 5); printf("  ESC : 종료");

            int key = _getch();
            if (key == 'r' || key == 'R') {
                system("cls");
                initMap();
                continue;
            }
            else break;
        }

        int key = _getch();

        if (key == 224 || key == 0) {
            key = _getch();
            continue;
        }
        else if (hasMap && (key == 'm' || key == 'M')) {
            showFullMap();
            continue;
        }

        if (key == 'r' || key == 'R') { initMap(); continue; }
        if (key == 27) break;

        int nx = playerX;
        int ny = playerY;

        if (key == 'w' || key == 'W') { ny--; showKeyMsg = 0; }
        else if (key == 's' || key == 'S') { ny++; showKeyMsg = 0; }
        else if (key == 'a' || key == 'A') { nx--; showKeyMsg = 0; }
        else if (key == 'd' || key == 'D') { nx++; showKeyMsg = 0; }

        if (map[ny][nx] != '#') {

            if (map[ny][nx] == 'G') {
                if (hasKey == 1) {
                    stageClear[currentStage] = 1;

                    if (currentStage == MAX_STAGE - 1) {
                        system("cls");

                        int startX = 45;
                        int startY = 12;

                        gotoxy(startX, startY);     printf("=========================");
                        gotoxy(startX, startY + 1); printf("      GAME  CLEAR !      ");
                        gotoxy(startX, startY + 2); printf("   모든 스테이지 완료!   ");
                        gotoxy(startX, startY + 3); printf("=========================");
                        gotoxy(startX, startY + 5); printf("  R : 처음부터 다시");
                        gotoxy(startX, startY + 6); printf("  ESC : 종료");

                        int k = _getch();
                        if (k == 'r' || k == 'R') {
                            currentStage = 0;
                            system("cls");
                            initMap();
                            continue;
                        }
                        else break;
                    }
                    else {
                        system("cls");

                        int startX = 45;
                        int startY = 12;

                        gotoxy(startX, startY);     printf("=========================");
                        gotoxy(startX, startY + 1); printf("      STAGE  CLEAR !     ");
                        gotoxy(startX, startY + 2); printf("=========================");
                        gotoxy(startX, startY + 4); printf("  다음 스테이지로 이동합니다...");
                        gotoxy(startX, startY + 5); printf("  아무 키나 누르세요");

                        _getch();

                        currentStage++;
                        system("cls");
                        initMap();
                        continue;
                    }
                }
                else {
                    showKeyMsg = 1;
                }
            }

            else if (map[ny][nx] == 'T') {
                hasMap = 1;
                map[ny][nx] = '.';
                playerX = nx; playerY = ny;
            }
            else if (map[ny][nx] == 'K') {
                hasKey = 1;
                map[ny][nx] = '.';
                playerX = nx; playerY = ny;
            }
            else if (map[ny][nx] == '*') {
                playerHP--;
                playerX = nx; playerY = ny;
            }
            else if (map[ny][nx] == 'B' || map[ny][nx] == 'V') {
                int bx = nx + (nx - playerX);
                int by = ny + (ny - playerY);

                if (map[by][bx] == '*') {
                    if (map[ny][nx] == 'V') map[by][bx] = 'T';
                    else                    map[by][bx] = '.';
                    map[ny][nx] = '.';
                    playerX = nx; playerY = ny;
                }
                else if (map[by][bx] == '.') {
                    map[by][bx] = map[ny][nx];
                    map[ny][nx] = '.';
                    playerX = nx; playerY = ny;
                }
            }
            else if (map[ny][nx] == 'O') {
                playerX = portalOutX;
                playerY = portalOutY;
            }
            else {
                playerX = nx; playerY = ny;
            }
        }
    }
}

// ================= main =================

int main() {
    while (1) {
        showTitle();

        while (1) {
            int sel = showLobby();
            if (sel == 1) {
                currentStage = 0;
                system("cls");
                runGame();
            }
            else if (sel == 2) {
                int st = showStageSelect();
                if (st >= 0) {
                    system("cls");
                    runGame();
                }
            }
            else if (sel == 3) {
                showHowToPlay();
            }
            else if (sel == 4) {
                return 0;
            }
        }
    }
    return 0;
}