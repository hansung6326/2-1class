#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define MAP_W 25
#define MAP_H 18
#define MAX_STAGE 2

// 뷰포트(화면에 보이는 맵 영역 크기)
#define VIEW_W 15
#define VIEW_H 11

char map[MAP_H][MAP_W];
int playerX, playerY;
int playerHP = 5;
int hasKey = 0;
int hasMap = 0;                 // 지도 보유 여부
int currentStage = 0;
int portalInX, portalInY;
int portalOutX, portalOutY;
int showKeyMsg = 0;
int stageClear[MAX_STAGE] = { 0, };  // 각 스테이지 클리어 여부

// ================= 공통 출력 유틸 =================

void gotoxy(int x, int y) {
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void getConsoleSize(int* cols, int* rows) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    *cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    *rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

// ================= 타이틀 =================

void showTitle() {
    system("cls");

    int cols, rows;
    getConsoleSize(&cols, &rows);

    const char* line1 = "  ██████   ██████  ███    ██ ███    ██ ███████  ██████ ████████ ";
    const char* line2 = " ██       ██    ██ ████   ██ ████   ██ ██      ██         ██    ";
    const char* line3 = " ██       ██    ██ ██ ██  ██ ██ ██  ██ █████   ██         ██    ";
    const char* line4 = " ██       ██    ██ ██  ██ ██ ██  ██ ██ ██      ██         ██    ";
    const char* line5 = "  ██████   ██████  ██   ████ ██   ████ ███████  ██████    ██    ";
    const char* line6 = "                PRESS ANY KEY TO START";
    const char* line7 = "                ESC : 종료";

    int w = (int)strlen(line1);

    int startX = 20;
    if (startX < 0) startX = 0;

    int startY = (rows - 8) / 2;
    if (startY < 0) startY = 0;

    gotoxy(startX, startY);
    printf("%s", line1);

    gotoxy(startX, startY + 1);
    printf("%s", line2);

    gotoxy(startX, startY + 2);
    printf("%s", line3);

    gotoxy(startX, startY + 3);
    printf("%s", line4);

    gotoxy(startX, startY + 4);
    printf("%s", line5);

    gotoxy(startX, startY + 6);
    printf("%s", line6);

    gotoxy(startX, startY + 7);
    printf("%s", line7);

    int ch = _getch();
    if (ch == 27) {   // ESC
        exit(0);
    }
    system("cls");
}

// ================= 로비 / 메뉴 =================

int showLobby() {
    while (1) {
        system("cls");

        int cols, rows;
        getConsoleSize(&cols, &rows);

        const char* title = "=== CONNECT LOBBY ===";
        const char* m1 = "1. 게임 시작";
        const char* m2 = "2. 이어하기";
        const char* m3 = "3. 조작법";
        const char* m4 = "4. 종료";

        int w = (int)strlen(title);
        int startX = (cols - w) / 2;
        if (startX < 0) startX = 0;

        int startY = rows / 2 - 3;
        if (startY < 0) startY = 0;

        gotoxy(startX, startY);
        printf("%s\n", title);
        gotoxy(startX, startY + 2);
        printf("%s\n", m1);
        gotoxy(startX, startY + 3);
        printf("%s\n", m2);
        gotoxy(startX, startY + 4);
        printf("%s\n", m3);
        gotoxy(startX, startY + 5);
        printf("%s\n", m4);

        gotoxy(startX, startY + 7);
        printf("번호를 선택하세요 (1-4): ");

        int ch = _getch();
        if (ch == '1') {
            currentStage = 0; // 새 게임: 항상 1스테이지부터
            return 1;
        }
        else if (ch == '2') {
            return 2; // 이어하기
        }
        else if (ch == '3') {
            return 3; // 조작법
        }
        else if (ch == '4' || ch == 27) {
            return 4; // 종료
        }
    }
}

int showStageSelect() {
    system("cls");

    int cols, rows;
    getConsoleSize(&cols, &rows);

    const char* title = "=== 이어하기 : 스테이지 선택 ===";
    int w = (int)strlen(title);
    int startX = (cols - w) / 2;
    if (startX < 0) startX = 0;

    int startY = rows / 2 - (MAX_STAGE + 4) / 2;
    if (startY < 0) startY = 0;

    gotoxy(startX, startY);
    printf("%s\n\n", title);

    for (int i = 0; i < MAX_STAGE; i++) {
        int canPlay = 0;
        if (i == 0) canPlay = 1;
        else if (stageClear[i - 1] == 1) canPlay = 1;

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
        printf("%s\n", line);
    }

    gotoxy(startX, startY + 2 + MAX_STAGE + 1);
    printf("플레이할 스테이지 번호를 선택하세요 (1-%d), ESC: 뒤로", MAX_STAGE);

    while (1) {
        int ch = _getch();
        if (ch == 27) { // ESC
            return -1;
        }
        else if (ch >= '1' && ch <= '0' + MAX_STAGE) {
            int sel = ch - '1';
            int canPlay = 0;
            if (sel == 0) canPlay = 1;
            else if (stageClear[sel - 1] == 1) canPlay = 1;

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

        int cols, rows;
        getConsoleSize(&cols, &rows);

        int startX = cols / 2 - 20;
        if (startX < 0) startX = 0;
        int startY = rows / 2 - 4;
        if (startY < 0) startY = 0;

        gotoxy(startX, startY);
        printf("=== 조작법 (페이지 %d / %d) ===\n\n", page + 1, maxPage);

        if (page == 0) {
            gotoxy(startX, startY + 2);
            printf("이동 : W A S D 또는 방향키");
            gotoxy(startX, startY + 3);
            printf("재시작 : R");
            gotoxy(startX, startY + 4);
            printf("종료 : ESC");
        }
        else if (page == 1) {
            gotoxy(startX, startY + 2);
            printf("G : 목표 지점 (열쇠가 있어야 통과)");
            gotoxy(startX, startY + 3);
            printf("K : 열쇠");
            gotoxy(startX, startY + 4);
            printf("* : 가시 (밟으면 HP -1)");
            gotoxy(startX, startY + 5);
            printf("B / V : 밀 수 있는 블록");
            gotoxy(startX, startY + 6);
            printf("V + 가시 = 지도 아이템 생성");
            gotoxy(startX, startY + 7);
            printf("O / Ø : 포탈 입구 / 출구");
        }

        gotoxy(startX, startY + 9);
        if (page < maxPage - 1)
            printf("아무 키나 누르면 다음 페이지, ESC : 뒤로");
        else
            printf("아무 키나 누르면 로비로 돌아갑니다. (ESC도 가능)");

        int ch = _getch();
        if (ch == 27) {
            break;
        }
        else {
            page++;
            if (page >= maxPage) break;
        }
    }
}

// ================= 맵 데이터 =================

char startMap[MAX_STAGE][MAP_H][MAP_W] = {
    // 스테이지 1
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
    // 스테이지 2 (예시로 V 하나 포함)
    {
        "#########################",
        "#.....................O.#",
        "#.......#...***.........#",
        "#.#.#.B.#..#***#..#..##.#",
        "#.#.....#..#.K.#........#",
        "#.#.#####..#####.#####..#",
        "#...............B.......#", // V 상자 예시
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

// ================= 전체 지도 보기 (M) =================

void showFullMap() {
    system("cls");

    int cols, rows;
    getConsoleSize(&cols, &rows);

    int totalWidth = MAP_W;
    int totalHeight = MAP_H + 4;

    int startX = (cols - totalWidth) / 2;
    if (startX < 0) startX = 0;
    int startY = (rows - totalHeight) / 2;
    if (startY < 0) startY = 0;

    gotoxy(startX, startY);
    printf("=== 전체 지도 ===\n");

    int mapStartY = startY + 2;
    for (int y = 0; y < MAP_H; y++) {
        gotoxy(startX, mapStartY + y);
        for (int x = 0; x < MAP_W; x++) {
            if (x == playerX && y == playerY) {
                printf("◎ ");   // 1칸 문자 + 공백 = 2칸
            }
            else if (map[y][x] == '#') {
                printf("■ ");   // 1칸 + 공백 = 2칸
            }
            else if (map[y][x] == 'B' || map[y][x] == 'V') {
                printf("□ ");   // 1칸 + 공백 = 2칸
            }
            else if (map[y][x] == 'K') {
                printf("🔑");   // 이모지는 이미 2칸 (공백 없음)
            }
            else if (map[y][x] == 'G') {
                printf("🚪");   // 이모지는 이미 2칸 (공백 없음)
            }
            else if (map[y][x] == 'T') {
                printf("? ");   // 1칸 + 공백 = 2칸
            }
            else if (map[y][x] == 'O') {
                printf("O ");   // 1칸 + 공백 = 2칸
            }
            else if (map[y][x] == 'Q') {
                printf("Q ");   // 1칸 + 공백 = 2칸
            }
            else if (map[y][x] == '*') {
                printf("^ ");   // 1칸 + 공백 = 2칸
            }
            else if (map[y][x] == '.') {
                printf("  ");   // 공백 2칸
            }
            else {
                printf("%c ", map[y][x]);  // 1칸 + 공백 = 2칸
            }
        }
    }

    gotoxy(startX, mapStartY + MAP_H + 1);
    printf("현재 위치: @   |   아무 키나 누르면 돌아갑니다.");

    _getch();
    system("cls");
}

// ================= 뷰포트 기반 맵 그리기 =================

void drawMap() {
    int cols, rows;
    getConsoleSize(&cols, &rows);

    // 플레이어 기준 뷰포트 계산
    int viewX = playerX - VIEW_W / 2;
    int viewY = playerY - VIEW_H / 2;

    if (viewX < 0) viewX = 0;
    if (viewY < 0) viewY = 0;
    if (viewX + VIEW_W > MAP_W) viewX = MAP_W - VIEW_W;
    if (viewY + VIEW_H > MAP_H) viewY = MAP_H - VIEW_H;
    if (viewX < 0) viewX = 0;
    if (viewY < 0) viewY = 0;

    int drawW = VIEW_W;
    int drawH = VIEW_H;
    if (drawW > MAP_W) drawW = MAP_W;
    if (drawH > MAP_H) drawH = MAP_H;

    int totalHeight = drawH + 8;
    int totalWidth = drawW;

    int startY = (rows - totalHeight) / 2;
    if (startY < 0) startY = 0;
    int startX = (cols - totalWidth) / 2;
    if (startX < 0) startX = 0;

    // 상단 UI
    gotoxy(startX, startY);
    printf("STAGE %d\n", currentStage + 1);

    // HP 줄 잔상 제거
    gotoxy(startX, startY + 1);
    for (int i = 0; i < 40; i++) printf(" ");

    gotoxy(startX, startY + 1);
    printf("HP : ");
    for (int i = 0; i < playerHP; i++) {
        printf("♥ ");
    }

    gotoxy(startX, startY + 2);
    if (hasKey == 1) printf("열쇠 : 보유중");
    else             printf("열쇠 : 없음");

    gotoxy(startX, startY + 3);
    if (hasMap == 1) printf("지도 : 보유중 (M 키로 보기)");
    else             printf("지도 : 없음");

    // 맵(뷰포트)
    int mapStartY = startY + 5;
    for (int sy = 0; sy < drawH; sy++) {
        int my = viewY + sy;
        gotoxy(startX, mapStartY + sy);
        for (int sx = 0; sx < drawW; sx++) {
            int mx = viewX + sx;

            if (mx == playerX && my == playerY) {
                printf("◎ ");   // 1칸 문자 + 공백 = 2칸
            }
            else if (map[my][mx] == '#') {
                printf("■ ");   // 1칸 + 공백 = 2칸
            }
            else if (map[my][mx] == 'B' || map[my][mx] == 'V') {
                printf("□ ");   // 1칸 + 공백 = 2칸
            }
            else if (map[my][mx] == 'K') {
                printf("🔑");   // 이모지는 이미 2칸 (공백 없음)
            }
            else if (map[my][mx] == 'G') {
                printf("🚪");   // 이모지는 이미 2칸 (공백 없음)
            }
            else if (map[my][mx] == 'T') {
                printf("? ");   // 1칸 + 공백 = 2칸
            }
            else if (map[my][mx] == 'O') {
                printf("O ");   // 1칸 + 공백 = 2칸
            }
            else if (map[my][mx] == 'Q') {
                printf("Q ");   // 1칸 + 공백 = 2칸
            }
            else if (map[my][mx] == '*') {
                printf("^ ");   // 1칸 + 공백 = 2칸
            }
            else if (map[my][mx] == '.') {
                printf("  ");   // 공백 2칸
            }
            else {
                printf("%c ", map[my][mx]);  // 1칸 + 공백 = 2칸
            }
        }
    }

    // 하단 UI
    gotoxy(startX, mapStartY + drawH + 1);
    printf("이동: WASD 또는 방향키  |  R: 재시작  |  ESC: 종료");

    gotoxy(startX, mapStartY + drawH + 2);
    printf("포탈 :  O = 입구   Ø = 출구");

    gotoxy(startX, mapStartY + drawH + 4);
    if (showKeyMsg == 1) {
        printf("  !! 열쇠가 필요합니다 !!");
    }
    else {
        printf("                              ");
    }
}

// ================= 게임 진행 =================

void runGame() {
    initMap();

    while (1) {
        drawMap();

        // GAME OVER 체크
        if (playerHP <= 0) {
            system("cls");

            int cols, rows;
            getConsoleSize(&cols, &rows);

            const char* l1 = "=========================";
            const char* l2 = "        GAME OVER        ";
            const char* l3 = "=========================";
            const char* l4 = "  R : 재시작";
            const char* l5 = "  ESC : 종료";

            int w = (int)strlen(l1);
            int startX = (cols - w) / 2;
            if (startX < 0) startX = 0;

            int startY = rows / 2 - 2;
            if (startY < 0) startY = 0;

            gotoxy(startX, startY);
            printf("%s\n", l1);
            gotoxy(startX, startY + 1);
            printf("%s\n", l2);
            gotoxy(startX, startY + 2);
            printf("%s\n", l3);
            gotoxy(startX, startY + 4);
            printf("%s\n", l4);
            gotoxy(startX, startY + 5);
            printf("%s\n", l5);

            int key = _getch();
            if (key == 'r' || key == 'R') {
                system("cls");
                initMap();
                continue;
            }
            else {
                break;
            }
        }

        // ===== 입력 처리 (WASD만 사용) =====
        int key = _getch();

        // 버그 수정 오른쪽 방향키를 누르면 지도가 열리는 버그를 수정
        if (key == 224 || key == 0) {
            key = _getch();
            continue;
        }
        else if (hasMap && (key == 'm' || key == 'M')) { // 지도 보기
            showFullMap();
            continue;
        }

        // 재시작
        if (key == 'r' || key == 'R') {
            initMap();
            continue;
        }

        // ESC 종료
        if (key == 27) break;

        int nx = playerX;
        int ny = playerY;

        // WASD 이동만 허용
        if (key == 'w' || key == 'W') {
            ny--;
            showKeyMsg = 0;
        }
        else if (key == 's' || key == 'S') {
            ny++;
            showKeyMsg = 0;
        }
        else if (key == 'a' || key == 'A') {
            nx--;
            showKeyMsg = 0;
        }
        else if (key == 'd' || key == 'D') {
            nx++;
            showKeyMsg = 0;
        }

        if (map[ny][nx] != '#') {

            // 목표 G
            if (map[ny][nx] == 'G') {
                if (hasKey == 1) {
                    stageClear[currentStage] = 1; // 현재 스테이지 클리어 기록

                    if (currentStage == MAX_STAGE - 1) {
                        system("cls");

                        int cols, rows;
                        getConsoleSize(&cols, &rows);

                        const char* l1 = "=========================";
                        const char* l2 = "      GAME  CLEAR !      ";
                        const char* l3 = "   모든 스테이지 완료!   ";
                        const char* l4 = "=========================";
                        const char* l5 = "  R : 처음부터 다시";
                        const char* l6 = "  ESC : 종료";

                        int w = (int)strlen(l1);
                        int startX = (cols - w) / 2;
                        if (startX < 0) startX = 0;

                        int startY = rows / 2 - 3;
                        if (startY < 0) startY = 0;

                        gotoxy(startX, startY);
                        printf("%s\n", l1);
                        gotoxy(startX, startY + 1);
                        printf("%s\n", l2);
                        gotoxy(startX, startY + 2);
                        printf("%s\n", l3);
                        gotoxy(startX, startY + 3);
                        printf("%s\n", l4);
                        gotoxy(startX, startY + 5);
                        printf("%s\n", l5);
                        gotoxy(startX, startY + 6);
                        printf("%s\n", l6);

                        int k = _getch();
                        if (k == 'r' || k == 'R') {
                            currentStage = 0;
                            system("cls");
                            initMap();
                            continue;
                        }
                        else {
                            break;
                        }
                    }
                    else {
                        system("cls");

                        int cols, rows;
                        getConsoleSize(&cols, &rows);

                        const char* l1 = "=========================";
                        const char* l2 = "      STAGE  CLEAR !     ";
                        const char* l3 = "=========================";
                        const char* l4 = "  다음 스테이지로 이동합니다...";
                        const char* l5 = "  아무 키나 누르세요";

                        int w = (int)strlen(l1);
                        int startX = (cols - w) / 2;
                        if (startX < 0) startX = 0;

                        int startY = rows / 2 - 2;
                        if (startY < 0) startY = 0;

                        gotoxy(startX, startY);
                        printf("%s\n", l1);
                        gotoxy(startX, startY + 1);
                        printf("%s\n", l2);
                        gotoxy(startX, startY + 2);
                        printf("%s\n", l3);
                        gotoxy(startX, startY + 4);
                        printf("%s\n", l4);
                        gotoxy(startX, startY + 5);
                        printf("%s\n", l5);

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

            // 지도 아이템 획득
            else if (map[ny][nx] == 'T') {
                hasMap = 1;
                map[ny][nx] = '.';
                playerX = nx;
                playerY = ny;
            }

            // 열쇠
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

            // 블록 밀기 (B/V)
            else if (map[ny][nx] == 'B' || map[ny][nx] == 'V') {
                int bx = nx + (nx - playerX);
                int by = ny + (ny - playerY);

                if (map[by][bx] == '*') {
                    if (map[ny][nx] == 'V') {
                        // V가 가시에 닿으면 지도 아이템 생성
                        map[by][bx] = 'T';
                    }
                    else {
                        // 일반 B는 가시만 제거
                        map[by][bx] = '.';
                    }
                    map[ny][nx] = '.';
                    playerX = nx;
                    playerY = ny;
                }
                else if (map[by][bx] == '.') {
                    map[by][bx] = map[ny][nx]; // B 또는 V 그대로 이동
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

            // 빈 칸 등
            else {
                playerX = nx;
                playerY = ny;
            }
        }
    }
}

// ================= main =================

int main() {

    while (1) {
        showTitle();  // 타이틀

        while (1) {
            int sel = showLobby();
            if (sel == 1) {
                // 새 게임
                currentStage = 0;
                system("cls");
                runGame();
            }
            else if (sel == 2) {
                // 이어하기
                int st = showStageSelect();
                if (st >= 0) {
                    system("cls");
                    runGame();
                }
                // -1이면 로비로 돌아감
            }
            else if (sel == 3) {
                // 조작법
                showHowToPlay();
            }
            else if (sel == 4) {
                // 종료
                return 0;
            }
        }
    }

    return 0;
}