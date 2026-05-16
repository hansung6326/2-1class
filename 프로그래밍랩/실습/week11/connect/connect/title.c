#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

// ============================================================
//  콘솔 색상 코드
// ============================================================
#define RED      "\033[1;31m"
#define GREEN    "\033[1;32m"
#define YELLOW   "\033[1;33m"
#define BLUE     "\033[1;34m"
#define MAGENTA  "\033[1;35m"
#define CYAN     "\033[1;36m"
#define WHITE    "\033[1;37m"
#define GRAY     "\033[1;90m"
#define RESET    "\033[0m"

// ============================================================
//  게임 상수
// ============================================================
#define MAP_W        15
#define MAP_H        10
#define MAX_STAGES   10
#define MAX_UNDO     50   // 되돌리기 최대 횟수

// ============================================================
//  타일 종류
// ============================================================
#define TILE_EMPTY   '.'
#define TILE_WALL    '#'
#define TILE_BLOCK   'B'
#define TILE_SPIKE   '*'
#define TILE_GOAL    'G'
#define TILE_KEY     'K'
#define TILE_LOCK    'L'
#define TILE_PLAYER  '@'

// ============================================================
//  방향키 / 키 입력
// ============================================================
#define KEY_UP    72
#define KEY_DOWN  80
#define KEY_LEFT  75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_ESC   27
#define KEY_R     'r'
#define KEY_Z     'z'
#define KEY_W     'w'
#define KEY_S     's'
#define KEY_A     'a'
#define KEY_D     'd'

// ============================================================
//  씬 정의
// ============================================================
typedef enum {
    SCENE_TITLE,
    SCENE_MAINMENU,
    SCENE_HOWTOPLAY,
    SCENE_STAGESELECT,
    SCENE_GAME,
    SCENE_CLEAR,
    SCENE_GAMEOVER,
    SCENE_EXIT
} Scene;

// ============================================================
//  스테이지 상태
// ============================================================
typedef enum {
    STAGE_LOCKED,
    STAGE_UNLOCKED,
    STAGE_CLEARED
} StageStatus;

// ============================================================
//  구조체 정의
// ============================================================
typedef struct {
    int x, y;
    int hasKey;
} Player;

// 되돌리기용 스냅샷
typedef struct {
    char map[MAP_H][MAP_W];
    Player player;
    int moveCount;
} Snapshot;

typedef struct {
    int id;
    char name[30];
    char description[50];
    int difficulty;
    StageStatus status;
    int bestMoves;
    int maxMoves;
} Stage;

typedef struct {
    char map[MAP_H][MAP_W];
    char originalMap[MAP_H][MAP_W];
    Player player;
    int moveCount;
    int isCleared;
    Snapshot undoStack[MAX_UNDO];
    int undoTop;
} GameState;

// ============================================================
//  전역 변수
// ============================================================
Scene   currentScene = SCENE_TITLE;
int     selectedStage = 0;
GameState gs;

Stage stages[MAX_STAGES] = {
    {1,  "악마의 관문",  "기초를 배워봐",        1, STAGE_UNLOCKED, 0, 15},
    {2,  "불꽃의 복도",  "밀기의 기초",          1, STAGE_LOCKED,   0, 20},
    {3,  "해골의 방",    "장애물을 넘어라",      2, STAGE_LOCKED,   0, 25},
    {4,  "얼음 감옥",    "순서가 중요해",        2, STAGE_LOCKED,   0, 30},
    {5,  "거울의 미로",  "생각하고 움직여",      3, STAGE_LOCKED,   0, 35},
    {6,  "시간의 방",    "최소 이동으로",        3, STAGE_LOCKED,   0, 30},
    {7,  "차원의 틈",    "규칙이 바뀐다",        4, STAGE_LOCKED,   0, 40},
    {8,  "악몽의 탑",    "집중력 시험",          4, STAGE_LOCKED,   0, 45},
    {9,  "심연의 경계",  "최후의 시험",          5, STAGE_LOCKED,   0, 50},
    {10, "심연의 왕좌",  "모든것의 끝",          5, STAGE_LOCKED,   0, 60},
};

// ============================================================
//  스테이지 맵 데이터
// ============================================================
// 각 맵: MAP_H x MAP_W
// @ = 플레이어 시작위치 (맵 로드 후 player 좌표로 변환)
const char stageMaps[MAX_STAGES][MAP_H][MAP_W] = {
    // Stage 1 - 악마의 관문
    {
        "###############",
        "#.............#",
        "#.............#",
        "#....BBB......#",
        "#.............#",
        "#.....@.......#",
        "#.............#",
        "#.....G.......#",
        "#.............#",
        "###############",
    },
    // Stage 2 - 불꽃의 복도
    {
        "###############",
        "#.............#",
        "#.B...........#",
        "#.............#",
        "#*****........#",
        "#.....@.......#",
        "#.............#",
        "#.........G...#",
        "#.............#",
        "###############",
    },
    // Stage 3 - 해골의 방
    {
        "###############",
        "#.............#",
        "#...B.....B...#",
        "#.............#",
        "#.....***....#",
        "#.....@......#",
        "#.............#",
        "#......G......#",
        "#.............#",
        "###############",
    },
    // Stage 4 - 얼음 감옥
    {
        "###############",
        "#.............#",
        "#.K...........#",
        "#.............#",
        "#.....L.......#",
        "#.....@.......#",
        "#.............#",
        "#.....G.......#",
        "#.............#",
        "###############",
    },
    // Stage 5 - 거울의 미로
    {
        "###############",
        "#.............#",
        "#.B.......B...#",
        "#.............#",
        "#..***...***..#",
        "#.....@.......#",
        "#.............#",
        "#.....G.......#",
        "#.............#",
        "###############",
    },
    // Stage 6 - 시간의 방
    {
        "###############",
        "#.............#",
        "#....B.B......#",
        "#.............#",
        "#.K...L..*....#",
        "#.....@.......#",
        "#.............#",
        "#.....G.......#",
        "#.............#",
        "###############",
    },
    // Stage 7 - 차원의 틈
    {
        "###############",
        "#.............#",
        "#..B.....B....#",
        "#.............#",
        "#.**...**.....#",
        "#.....@.......#",
        "#.K...........#",
        "#.....L..G....#",
        "#.............#",
        "###############",
    },
    // Stage 8 - 악몽의 탑
    {
        "###############",
        "#.............#",
        "#.B..B..B.....#",
        "#.............#",
        "#.*.*.*.*.....#",
        "#.....@.......#",
        "#.............#",
        "#.K...L..G....#",
        "#.............#",
        "###############",
    },
    // Stage 9 - 심연의 경계
    {
        "###############",
        "#.............#",
        "#.B.B.B.B.....#",
        "#.............#",
        "#.**.**.**....#",
        "#.....@.......#",
        "#.K...........#",
        "#..L.....G....#",
        "#.............#",
        "###############",
    },
    // Stage 10 - 심연의 왕좌
    {
        "###############",
        "#.............#",
        "#.B.B...B.B...#",
        "#.............#",
        "#.*.*.*.*.*.*.#",
        "#.....@.......#",
        "#.K...........#",
        "#.L.......G...#",
        "#.............#",
        "###############",
    },
};

// ============================================================
//  유틸리티 함수
// ============================================================

// 커서 이동
void setCursor(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// 커서 숨기기/보이기
void showCursor(int visible) {
    CONSOLE_CURSOR_INFO info = { 1, visible };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

// 콘솔 색상 설정
void setColor(const char* color) {
    printf("%s", color);
}

// 화면 지우기
void clearScreen() {
    system("cls");
}

// 키 입력 받기 (방향키 포함)
int getKey() {
    int ch = _getch();
    if (ch == 0 || ch == 224) {
        ch = _getch();
    }
    return ch;
}

// 텍스트 가운데 출력
void printCenter(int y, int width, const char* text, const char* color) {
    int len = (int)strlen(text);
    int x = (width - len) / 2;
    setCursor(x, y);
    printf("%s%s%s", color, text, RESET);
}

// 딜레이
void waitMs(int ms) {
    Sleep(ms);
}

// ============================================================
//  타이틀 화면
// ============================================================
void showTitle() {
    clearScreen();
    showCursor(0);

    int w = 56;

    setCursor(0, 1);
    printf(RED);
    printf("  ======================================================\n");
    printf("  =                                                    =\n");
    printf("  =   ██████╗ ██╗   ██╗███████╗███████╗██╗           =\n");
    printf("  =   ██╔══██╗██║   ██║╚══███╔╝╚══███╔╝██║           =\n");
    printf("  =   ██████╔╝██║   ██║  ███╔╝   ███╔╝ ██║           =\n");
    printf("  =   ██╔═══╝ ██║   ██║ ███╔╝   ███╔╝  ██║           =\n");
    printf("  =   ██║     ╚██████╔╝███████╗███████╗███████╗       =\n");
    printf("  =   ╚═╝      ╚═════╝ ╚══════╝╚══════╝╚══════╝      =\n");
    printf("  =                                                    =\n");
    printf(RESET);

    printf(YELLOW);
    printf("  =   ███████╗██████╗ ██╗   ██╗███████╗              =\n");
    printf("  =   ██╔════╝██╔══██╗██║   ██║██╔════╝              =\n");
    printf("  =   █████╗  ██████╔╝██║   ██║███████╗              =\n");
    printf("  =   ██╔══╝  ██╔═══╝ ██║   ██║╚════██║              =\n");
    printf("  =   ███████╗██║     ╚██████╔╝███████║              =\n");
    printf("  =   ╚══════╝╚═╝      ╚═════╝ ╚══════╝              =\n");
    printf(RESET);

    printf(WHITE);
    printf("  =                                                    =\n");
    printf("  =           심  연  의  퍼  즐                      =\n");
    printf("  =                                                    =\n");
    printf("  ======================================================\n");
    printf(RESET);

    // 깜빡이는 Press Any Key
    int blink = 1;
    clock_t t = clock();

    while (!_kbhit()) {
        if ((double)(clock() - t) / CLOCKS_PER_SEC > 0.5) {
            setCursor(14, 21);
            if (blink)
                printf(CYAN "   ▶  Press Any Key  ◀   " RESET);
            else
                printf("                         ");
            blink = !blink;
            t = clock();
        }
    }
    _getch();
}

// ============================================================
//  조작법 화면
// ============================================================
void showHowToPlay() {
    clearScreen();

    printf(YELLOW);
    printf("  ╔══════════════════════════════════════════╗\n");
    printf("  ║             📖  조  작  법               ║\n");
    printf("  ╠══════════════════════════════════════════╣\n");
    printf(RESET);

    printf(WHITE);
    printf("  ║                                          ║\n");
    printf("  ║  [ 이동 ]                                ║\n");
    printf("  ║    W / ↑  :  위로 이동                  ║\n");
    printf("  ║    S / ↓  :  아래로 이동                ║\n");
    printf("  ║    A / ←  :  왼쪽으로 이동              ║\n");
    printf("  ║    D / →  :  오른쪽으로 이동            ║\n");
    printf("  ║                                          ║\n");
    printf("  ║  [ 기능 ]                                ║\n");
    printf("  ║    Z       :  한 칸 되돌리기             ║\n");
    printf("  ║    R       :  스테이지 재시작            ║\n");
    printf("  ║    ESC     :  스테이지 선택으로          ║\n");
    printf("  ║                                          ║\n");
    printf("  ╠══════════════════════════════════════════╣\n");
    printf("  ║                                          ║\n");
    printf("  ║  [ 타일 설명 ]                           ║\n");
    printf(RESET);

    printf("  ║  " CYAN  "@" RESET WHITE "  : 플레이어                        ║\n" RESET);
    printf("  ║  " MAGENTA "G" RESET WHITE "  : 목표지점 (악마를 만나러!)      ║\n" RESET);
    printf("  ║  " YELLOW "B" RESET WHITE "  : 밀 수 있는 블록                ║\n" RESET);
    printf("  ║  " RED   "*" RESET WHITE "  : 가시 (이동 횟수 2배 소모)       ║\n" RESET);
    printf("  ║  " GREEN "K" RESET WHITE "  : 열쇠 (획득 후 문 열기)          ║\n" RESET);
    printf("  ║  " RED   "L" RESET WHITE "  : 잠긴 문 (열쇠 필요)             ║\n" RESET);
    printf("  ║  " BLUE  "#" RESET WHITE "  : 벽 (통과 불가)                  ║\n" RESET);

    printf(WHITE);
    printf("  ║                                          ║\n");
    printf("  ╠══════════════════════════════════════════╣\n");
    printf("  ║                                          ║\n");
    printf("  ║  [ 목표 ]                                ║\n");
    printf("  ║   제한 이동 횟수 안에 G에 도달하세요!   ║\n");
    printf("  ║   적은 이동 = 더 많은 별점!             ║\n");
    printf("  ║                                          ║\n");
    printf("  ╚══════════════════════════════════════════╝\n");
    printf(RESET);

    printf("\n");
    printf(CYAN "          [ 아무 키나 누르면 돌아갑니다 ]" RESET "\n");
    _getch();
}

// ============================================================
//  메인 메뉴
// ============================================================
Scene showMainMenu() {
    int selected = 0;
    int key;

    const char* items[] = {
        "  게임 시작  ",
        "  이어하기   ",
        "  조작법     ",
        "  종료       "
    };
    int itemCount = 4;

    while (1) {
        clearScreen();
        showCursor(0);

        printf(RED);
        printf("  ╔══════════════════════════════════════╗\n");
        printf("  ║         PUZZLE  ABYSS               ║\n");
        printf("  ║         심 연 의 퍼 즐              ║\n");
        printf("  ╠══════════════════════════════════════╣\n");
        printf(RESET);

        for (int i = 0; i < 2; i++)
            printf("  ║                                      ║\n");

        for (int i = 0; i < itemCount; i++) {
            printf("  ║      ");
            if (i == selected) {
                printf(YELLOW "  ▶ %-15s◀  " RESET, items[i]);
            }
            else {
                printf(WHITE "     %-15s   " RESET, items[i]);
            }
            printf("    ║\n");
            printf("  ║                                      ║\n");
        }

        printf(RED);
        printf("  ╠══════════════════════════════════════╣\n");
        printf("  ║   🔥  악마의 퍼즐을 풀어라!  🔥    ║\n");
        printf("  ╚══════════════════════════════════════╝\n");
        printf(RESET);

        printf("\n  " GRAY "[↑↓] 이동   [Enter] 선택" RESET "\n");

        key = getKey();

        if (key == KEY_UP)
            selected = (selected - 1 + itemCount) % itemCount;
        else if (key == KEY_DOWN)
            selected = (selected + 1) % itemCount;
        else if (key == KEY_ENTER) {
            switch (selected) {
            case 0: // 게임 시작 → 스테이지 선택
                return SCENE_STAGESELECT;
            case 1: // 이어하기 → 스테이지 선택
                return SCENE_STAGESELECT;
            case 2: // 조작법
                showHowToPlay();
                break;
            case 3: // 종료
                return SCENE_EXIT;
            }
        }
        else if (key == KEY_ESC) {
            return SCENE_EXIT;
        }
    }
}

// ============================================================
//  스테이지 선택 화면
// ============================================================
Scene showStageSelect() {
    int selected = 0;
    int key;

    // 첫 번째 해금된 스테이지로 커서 초기화
    for (int i = 0; i < MAX_STAGES; i++) {
        if (stages[i].status != STAGE_LOCKED) {
            selected = i;
        }
        else {
            break;
        }
    }

    while (1) {
        clearScreen();
        showCursor(0);

        // 상단 프레임
        printf(YELLOW);
        printf("  ╔══════════════════════════════════════════╗\n");
        printf("  ║           ◈  스 테 이 지  선 택  ◈       ║\n");
        printf("  ╠══════════════════════════════════════════╣\n");
        printf(RESET);

        // 스테이지 그리드 (5x2)
        printf("  ║                                          ║\n");

        for (int row = 0; row < 2; row++) {
            // 상단 테두리
            printf("  ║   ");
            for (int col = 0; col < 5; col++) {
                int idx = row * 5 + col;
                if (idx == selected)
                    printf(YELLOW "┌─────┐" RESET " ");
                else if (stages[idx].status == STAGE_CLEARED)
                    printf(GREEN  "┌─────┐" RESET " ");
                else if (stages[idx].status == STAGE_UNLOCKED)
                    printf(WHITE  "┌─────┐" RESET " ");
                else
                    printf(GRAY   "┌─────┐" RESET " ");
            }
            printf("   ║\n");

            // 번호 줄
            printf("  ║   ");
            for (int col = 0; col < 5; col++) {
                int idx = row * 5 + col;
                char cell[10];

                if (stages[idx].status == STAGE_CLEARED)
                    sprintf(cell, " %2d  ", idx + 1);
                else if (stages[idx].status == STAGE_UNLOCKED)
                    sprintf(cell, " %2d  ", idx + 1);
                else
                    sprintf(cell, " LK  ");

                if (idx == selected)
                    printf(YELLOW "│%s│" RESET " ", cell);
                else if (stages[idx].status == STAGE_CLEARED)
                    printf(GREEN  "│%s│" RESET " ", cell);
                else if (stages[idx].status == STAGE_UNLOCKED)
                    printf(WHITE  "│%s│" RESET " ", cell);
                else
                    printf(GRAY   "│%s│" RESET " ", cell);
            }
            printf("   ║\n");

            // 하단 테두리
            printf("  ║   ");
            for (int col = 0; col < 5; col++) {
                int idx = row * 5 + col;
                if (idx == selected)
                    printf(YELLOW "└─────┘" RESET " ");
                else if (stages[idx].status == STAGE_CLEARED)
                    printf(GREEN  "└─────┘" RESET " ");
                else if (stages[idx].status == STAGE_UNLOCKED)
                    printf(WHITE  "└─────┘" RESET " ");
                else
                    printf(GRAY   "└─────┘" RESET " ");
            }
            printf("   ║\n");

            // 상태 아이콘 줄
            printf("  ║   ");
            for (int col = 0; col < 5; col++) {
                int idx = row * 5 + col;
                if (stages[idx].status == STAGE_CLEARED)
                    printf(GREEN  "  [V]  " RESET " ");
                else if (stages[idx].status == STAGE_UNLOCKED)
                    printf(CYAN   "  [ ]  " RESET " ");
                else
                    printf(GRAY   "  [X]  " RESET " ");
            }
            printf("   ║\n");

            printf("  ║                                          ║\n");
        }

        // 구분선
        printf(YELLOW);
        printf("  ╠══════════════════════════════════════════╣\n");
        printf(RESET);

        // 선택된 스테이지 정보
        Stage* s = &stages[selected];
        printf("  ║  STAGE %2d : %-30s║\n", s->id, s->name);
        printf("  ║  설  명   : %-30s║\n", s->description);

        // 난이도 별점
        printf("  ║  난이도   : ");
        for (int i = 0; i < 5; i++) {
            if (i < s->difficulty)
                printf(YELLOW "★" RESET);
            else
                printf(GRAY "☆" RESET);
        }
        printf("                           ║\n");

        // 최고 기록 / 상태
        if (s->status == STAGE_CLEARED) {
            printf("  ║  " GREEN "최고기록: %d번 이동" RESET "                     ║\n",
                s->bestMoves);
        }
        else if (s->status == STAGE_UNLOCKED) {
            printf("  ║  " CYAN "▶ 도전해보세요! 제한: %d번" RESET "              ║\n",
                s->maxMoves);
        }
        else {
            printf("  ║  " RED "🔒 이전 스테이지를 클리어하세요" RESET "        ║\n");
        }

        printf(YELLOW);
        printf("  ╚══════════════════════════════════════════╝\n");
        printf(RESET);

        printf("\n  " GRAY "[←→↑↓] 이동   [Enter] 시작   [ESC] 메뉴" RESET "\n");
        printf("  " GRAY "[V] 클리어   [ ] 도전가능   [X] 잠김" RESET "\n");

        key = getKey();

        if (key == KEY_LEFT && selected > 0)          selected--;
        else if (key == KEY_RIGHT && selected < MAX_STAGES - 1) selected++;
        else if (key == KEY_UP && selected >= 5)    selected -= 5;
        else if (key == KEY_DOWN && selected < 5)     selected += 5;
        else if (key == KEY_ENTER) {
            if (stages[selected].status != STAGE_LOCKED) {
                selectedStage = selected;
                return SCENE_GAME;
            }
            else {
                // 잠긴 스테이지 경고
                setCursor(4, 28);
                printf(RED "  ⚠  잠긴 스테이지입니다! 이전 스테이지를 클리어하세요." RESET);
                waitMs(1500);
            }
        }
        else if (key == KEY_ESC) {
            return SCENE_MAINMENU;
        }
    }
}

// ============================================================
//  게임 로드 (맵 초기화)
// ============================================================
void loadStage(int stageIdx) {
    memset(&gs, 0, sizeof(GameState));
    gs.moveCount = 0;
    gs.isCleared = 0;
    gs.undoTop = -1;

    // 맵 복사 + 플레이어 위치 찾기
    for (int y = 0; y < MAP_H; y++) {
        for (int x = 0; x < MAP_W; x++) {
            char tile = stageMaps[stageIdx][y][x];
            if (tile == TILE_PLAYER) {
                gs.player.x = x;
                gs.player.y = y;
                gs.map[y][x] = TILE_EMPTY;
            }
            else {
                gs.map[y][x] = tile;
            }
        }
    }
    gs.player.hasKey = 0;
    memcpy(gs.originalMap, gs.map, sizeof(gs.map));
}

// ============================================================
//  되돌리기 스택
// ============================================================
void pushUndo() {
    if (gs.undoTop < MAX_UNDO - 1) {
        gs.undoTop++;
        memcpy(gs.undoStack[gs.undoTop].map, gs.map, sizeof(gs.map));
        gs.undoStack[gs.undoTop].player = gs.player;
        gs.undoStack[gs.undoTop].moveCount = gs.moveCount;
    }
}

int popUndo() {
    if (gs.undoTop >= 0) {
        memcpy(gs.map, gs.undoStack[gs.undoTop].map, sizeof(gs.map));
        gs.player = gs.undoStack[gs.undoTop].player;
        gs.moveCount = gs.undoStack[gs.undoTop].moveCount;
        gs.undoTop--;
        return 1;
    }
    return 0;
}

// ============================================================
//  게임 화면 렌더링
// ============================================================
void drawGame() {
    clearScreen();
    showCursor(0);

    Stage* s = &stages[selectedStage];

    // 상단 정보바
    printf(YELLOW);
    printf("  ╔══════════════════════════════════════════╗\n");
    printf("  ║  STAGE %-2d : %-20s         ║\n", s->id, s->name);
    printf("  ╠══════════════════════════════════════════╣\n");
    printf("  ║  이동: ");

    // 이동 횟수 색상 (남은 횟수에 따라)
    int remain = s->maxMoves - gs.moveCount;
    if (remain <= 5)        printf(RED);
    else if (remain <= 10)  printf(YELLOW);
    else                    printf(GREEN);

    printf("%3d / %3d", gs.moveCount, s->maxMoves);
    printf(RESET YELLOW);

    printf("   열쇠: ");
    if (gs.player.hasKey) printf(GREEN "보유" RESET YELLOW);
    else                   printf(GRAY "없음" RESET YELLOW);

    printf("              ║\n");
    printf("  ╚══════════════════════════════════════════╝\n");
    printf(RESET);

    printf("\n");

    // 맵 출력
    for (int y = 0; y < MAP_H; y++) {
        printf("  ");
        for (int x = 0; x < MAP_W; x++) {
            // 플레이어
            if (x == gs.player.x && y == gs.player.y) {
                printf(CYAN "@" RESET);
                continue;
            }
            char tile = gs.map[y][x];
            switch (tile) {
            case TILE_WALL:  printf(BLUE  "#" RESET); break;
            case TILE_BLOCK: printf(YELLOW "B" RESET); break;
            case TILE_SPIKE: printf(RED   "*" RESET); break;
            case TILE_GOAL:  printf(MAGENTA "G" RESET); break;
            case TILE_KEY:   printf(GREEN  "K" RESET); break;
            case TILE_LOCK:  printf(RED    "L" RESET); break;
            case TILE_EMPTY: printf(GRAY   "." RESET); break;
            default:         printf(" "); break;
            }
        }
        printf("\n");
    }

    // 하단 조작법
    printf("\n");
    printf(GRAY);
    printf("  ╔══════════════════════════════════════════╗\n");
    printf("  ║  [WASD/방향키] 이동    [Z] 되돌리기     ║\n");
    printf("  ║  [R] 재시작            [ESC] 스테이지   ║\n");
    printf("  ╚══════════════════════════════════════════╝\n");
    printf(RESET);

    // 범례
    printf("\n  ");
    printf(CYAN "@" RESET " 플레이어  ");
    printf(MAGENTA "G" RESET " 목표  ");
    printf(YELLOW "B" RESET " 블록  ");
    printf(RED "*" RESET " 가시  ");
    printf(GREEN "K" RESET " 열쇠  ");
    printf(RED "L" RESET " 잠긴문\n");
}

// ============================================================
//  플레이어 이동 처리
// ============================================================
// 반환값: 1 = 클리어, -1 = 게임오버, 0 = 계속
int movePlayer(int dx, int dy) {
    int nx = gs.player.x + dx;
    int ny = gs.player.y + dy;

    // 범위 체크
    if (nx < 0 || nx >= MAP_W || ny < 0 || ny >= MAP_H) return 0;

    char tile = gs.map[ny][nx];

    // 벽 충돌
    if (tile == TILE_WALL) return 0;

    // 블록 밀기
    if (tile == TILE_BLOCK) {
        int bnx = nx + dx;
        int bny = ny + dy;

        if (bnx < 0 || bnx >= MAP_W || bny < 0 || bny >= MAP_H) return 0;
        if (gs.map[bny][bnx] == TILE_WALL ||
            gs.map[bny][bnx] == TILE_BLOCK ||
            gs.map[bny][bnx] == TILE_LOCK) return 0;

        // 블록 이동 전 스냅샷 저장
        pushUndo();
        gs.map[bny][bnx] = TILE_BLOCK;
        gs.map[ny][nx] = TILE_EMPTY;
    }
    else {
        // 이동 전 스냅샷 저장
        pushUndo();
    }

    // 이동 처리
    gs.player.x = nx;
    gs.player.y = ny;
    gs.moveCount++;

    // 가시 → 이동 횟수 추가 소모
    if (tile == TILE_SPIKE) {
        gs.moveCount++;
    }

    // 열쇠 획득
    if (tile == TILE_KEY) {
        gs.player.hasKey = 1;
        gs.map[ny][nx] = TILE_EMPTY;
    }

    // 잠긴 문
    if (tile == TILE_LOCK) {
        if (gs.player.hasKey) {
            gs.player.hasKey = 0;
            gs.map[ny][nx] = TILE_EMPTY;
        }
        else {
            // 열쇠 없으면 이동 취소
            popUndo();
            return 0;
        }
    }

    // 목표 도달 → 클리어
    if (tile == TILE_GOAL) {
        return 1;
    }

    // 이동 횟수 초과 → 게임오버
    if (gs.moveCount >= stages[selectedStage].maxMoves) {
        return -1;
    }

    return 0;
}

// ============================================================
//  클리어 화면
// ============================================================
Scene showClearScreen() {
    clearScreen();
    showCursor(0);

    Stage* s = &stages[selectedStage];

    // 별점 계산
    int stars;
    float ratio = (float)gs.moveCount / s->maxMoves;
    if (ratio <= 0.5f)  stars = 3;
    else if (ratio <= 0.75f) stars = 2;
    else                     stars = 1;

    // 최고 기록 갱신
    int isNewRecord = 0;
    if (s->bestMoves == 0 || gs.moveCount < s->bestMoves) {
        s->bestMoves = gs.moveCount;
        isNewRecord = 1;
    }

    // 다음 스테이지 해금
    if (selectedStage + 1 < MAX_STAGES) {
        stages[selectedStage + 1].status = STAGE_UNLOCKED;
    }
    stages[selectedStage].status = STAGE_CLEARED;

    printf(GREEN);
    printf("\n");
    printf("  ╔══════════════════════════════════════════╗\n");
    printf("  ║                                          ║\n");
    printf("  ║         🎉  S T A G E  C L E A R !      ║\n");
    printf("  ║                                          ║\n");
    printf("  ╠══════════════════════════════════════════╣\n");
    printf("  ║                                          ║\n");
    printf(RESET);

    printf("  ║   스테이지  : " YELLOW "%-25s" RESET "  ║\n", s->name);
    printf("  ║   이동 횟수 : " CYAN "%3d" RESET " / " GRAY "%3d" RESET "                       ║\n",
        gs.moveCount, s->maxMoves);

    printf("  ║   평    가  : ");
    for (int i = 0; i < 3; i++) {
        if (i < stars) printf(YELLOW "★ " RESET);
        else           printf(GRAY   "☆ " RESET);
    }
    printf("                      ║\n");

    if (isNewRecord)
        printf("  ║   " GREEN "🏆 NEW RECORD! %d번 이동!" RESET "               ║\n",
            s->bestMoves);
    else
        printf("  ║   " GRAY "기존 기록: %d번 이동" RESET "                    ║\n",
            s->bestMoves);

    printf(GREEN);
    printf("  ║                                          ║\n");
    printf("  ╠══════════════════════════════════════════╣\n");
    printf("  ║                                          ║\n");

    if (selectedStage + 1 < MAX_STAGES)
        printf("  ║   " CYAN "[Enter]" RESET " 다음 스테이지                   ║\n");
    else
        printf("  ║   " YELLOW "[Enter]" RESET " 🎊 모든 스테이지 클리어!       ║\n");

    printf("  ║   " WHITE "[R]    " RESET " 이 스테이지 다시하기            ║\n");
    printf("  ║   " GRAY  "[ESC]  " RESET " 스테이지 선택으로               ║\n");
    printf("  ║                                          ║\n");
    printf("  ╚══════════════════════════════════════════╝\n");
    printf(RESET);

    while (1) {
        int key = getKey();
        if (key == KEY_ENTER) {
            if (selectedStage + 1 < MAX_STAGES) {
                selectedStage++;
                return SCENE_GAME;
            }
            else {
                return SCENE_STAGESELECT;
            }
        }
        else if (key == KEY_R) {
            return SCENE_GAME; // 재시작
        }
        else if (key == KEY_ESC) {
            return SCENE_STAGESELECT;
        }
    }
}

// ============================================================
//  게임오버 화면
// ============================================================
Scene showGameOverScreen() {
    clearScreen();
    showCursor(0);

    printf(RED);
    printf("\n");
    printf("  ╔══════════════════════════════════════════╗\n");
    printf("  ║                                          ║\n");
    printf("  ║          💀  G A M E  O V E R  💀       ║\n");
    printf("  ║                                          ║\n");
    printf("  ╠══════════════════════════════════════════╣\n");
    printf("  ║                                          ║\n");
    printf(RESET);
    printf("  ║   " RED "이동 횟수를 모두 소모했습니다..." RESET "        ║\n");
    printf("  ║                                          ║\n");
    printf("  ║   사용한 이동: " YELLOW "%3d" RESET " / " GRAY "%3d" RESET "                    ║\n",
        gs.moveCount, stages[selectedStage].maxMoves);
    printf("  ║                                          ║\n");
    printf(RED);
    printf("  ╠══════════════════════════════════════════╣\n");
    printf("  ║                                          ║\n");
    printf(RESET);
    printf("  ║   " CYAN "[R]  " RESET " 다시 시작                        ║\n");
    printf("  ║   " GRAY "[ESC]" RESET " 스테이지 선택으로                ║\n");
    printf("  ║                                          ║\n");
    printf(RED);
    printf("  ╚══════════════════════════════════════════╝\n");
    printf(RESET);

    while (1) {
        int key = getKey();
        if (key == KEY_R)   return SCENE_GAME;
        if (key == KEY_ESC) return SCENE_STAGESELECT;
    }
}

// ============================================================
//  게임 메인 루프
// ============================================================
Scene runGame() {
    loadStage(selectedStage);

    while (1) {
        drawGame();

        int key = getKey();
        int result = 0;

        switch (key) {
            // 이동
        case KEY_UP:    case KEY_W: case 'W':
            result = movePlayer(0, -1); break;
        case KEY_DOWN:  case KEY_S: case 'S':
            result = movePlayer(0, 1); break;
        case KEY_LEFT:  case KEY_A: case 'A':
            result = movePlayer(-1, 0); break;
        case KEY_RIGHT: case KEY_D: case 'D':
            result = movePlayer(1, 0); break;

            // 되돌리기
        case KEY_Z: case 'Z':
            popUndo();
            break;

            // 재시작
        case KEY_R: case 'R':
            loadStage(selectedStage);
            break;

            // 스테이지 선택으로
        case KEY_ESC:
            return SCENE_STAGESELECT;
        }

        // 클리어
        if (result == 1) {
            return showClearScreen();
        }
        // 게임오버
        if (result == -1) {
            Scene next = showGameOverScreen();
            if (next == SCENE_GAME) {
                loadStage(selectedStage); // 재시작이면 맵 초기화
            }
            return next;
        }
    }
}

// ============================================================
//  메인 함수
// ============================================================
int main() {
    // 콘솔 설정
    SetConsoleOutputCP(65001); // UTF-8
    system("mode con cols=60 lines=40");

    // ANSI 색상 활성화 (Windows 10+)
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

    srand((unsigned int)time(NULL));

    currentScene = SCENE_TITLE;

    while (currentScene != SCENE_EXIT) {
        switch (currentScene) {

        case SCENE_TITLE:
            showTitle();
            currentScene = SCENE_MAINMENU;
            break;

        case SCENE_MAINMENU:
            currentScene = showMainMenu();
            break;

        case SCENE_STAGESELECT:
            currentScene = showStageSelect();
            break;

        case SCENE_GAME:
            currentScene = runGame();
            break;

        case SCENE_EXIT:
            break;

        default:
            currentScene = SCENE_MAINMENU;
            break;
        }
    }

    // 종료 화면
    clearScreen();
    printf("\n\n");
    printf(RED "  ╔══════════════════════════════════════╗\n" RESET);
    printf(RED "  ║                                      ║\n" RESET);
    printf(RED "  ║     PUZZLE ABYSS를 플레이해주셔서    ║\n" RESET);
    printf(RED "  ║           감사합니다!  🔥            ║\n" RESET);
    printf(RED "  ║                                      ║\n" RESET);
    printf(RED "  ╚══════════════════════════════════════╝\n" RESET);
    waitMs(1500);

    showCursor(1);
    return 0;
}