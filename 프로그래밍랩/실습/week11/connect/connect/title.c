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
#define MAP_W        25
#define MAP_H        18
#define MAX_STAGES   10
#define MAX_UNDO     50

// ============================================================
//  캐릭터 애니메이션 프레임 (졸라맨 스타일)
//  이동 방향에 따라 다른 모양 출력
// ============================================================
//  정지  : 人
//  위    : ↑ (머리위로)
//  아래  : ↓
//  왼쪽  : ←
//  오른쪽: →
// 유니코드 한자/특수문자로 표현
#define CHAR_IDLE    "人"   // 정지 (사람 인)

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
//  방향 정의
// ============================================================
typedef enum {
    DIR_IDLE,
    DIR_UP,
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT
} Direction;

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
    int hp;
    int maxHp;
    Direction dir;   // 현재 바라보는 방향
} Player;

typedef struct {
    char   map[MAP_H][MAP_W];
    Player player;
    int    moveCount;
} Snapshot;

typedef struct {
    int         id;
    char        name[30];
    char        description[50];
    int         difficulty;
    StageStatus status;
    int         bestMoves;
    int         maxMoves;   // 별점용 기준 이동수 (제한 아님)
    int         startHp;    // 스테이지별 시작 HP
} Stage;

typedef struct {
    char     map[MAP_H][MAP_W];
    char     originalMap[MAP_H][MAP_W];
    Player   player;
    int      moveCount;
    int      isCleared;
    Snapshot undoStack[MAX_UNDO];
    int      undoTop;
} GameState;

// ============================================================
//  전역 변수
// ============================================================
Scene     currentScene = SCENE_TITLE;
int       selectedStage = 0;
GameState gs;

//  스테이지별 startHp 설정
//  난이도 낮을수록 HP 많음 → 쉬움
//  난이도 높을수록 HP 적음 → 어려움
Stage stages[MAX_STAGES] = {
    {1,  "연결의 시작",  "기초를 배워봐",      1, STAGE_UNLOCKED, 0, 20, 10},
    {2,  "첫 번째 길",   "블록을 밀어봐",      1, STAGE_LOCKED,   0, 25,  9},
    {3,  "가시밭길",     "가시를 조심해",      2, STAGE_LOCKED,   0, 30,  8},
    {4,  "잠긴 방",      "열쇠를 찾아라",      2, STAGE_LOCKED,   0, 35,  7},
    {5,  "미로의 중심",  "길을 만들어라",      3, STAGE_LOCKED,   0, 40,  7},
    {6,  "시간의 압박",  "효율적으로 가라",    3, STAGE_LOCKED,   0, 35,  6},
    {7,  "복합 구조",    "모든 요소 등장",     4, STAGE_LOCKED,   0, 45,  5},
    {8,  "심층 미궁",    "집중력이 필요해",    4, STAGE_LOCKED,   0, 50,  4},
    {9,  "마지막 관문",  "최후의 시험",        5, STAGE_LOCKED,   0, 55,  3},
    {10, "연결의 완성",  "모든것을 연결하라",  5, STAGE_LOCKED,   0, 65,  3},
};

// ============================================================
//  스테이지 맵 데이터 (25x18)
// ============================================================
const char stageMaps[MAX_STAGES][MAP_H][MAP_W] = {

    // Stage 1 - 연결의 시작
    {
        "#########################",
        "#.......................#",
        "#.......................#",
        "#.......................#",
        "#.....BBB...............#",
        "#.......................#",
        "#.......................#",
        "#.......................#",
        "#..........@............#",
        "#.......................#",
        "#.......................#",
        "#.......................#",
        "#.......................#",
        "#..........G............#",
        "#.......................#",
        "#.......................#",
        "#.......................#",
        "#########################",
    },
    // Stage 2 - 첫 번째 길
    {
        "#########################",
        "#.......................#",
        "#.......................#",
        "#....BB.................#",
        "#.......................#",
        "#.......................#",
        "#.......................#",
        "#########.###############",
        "#.......................#",
        "#..........@............#",
        "#.......................#",
        "#.......................#",
        "#.......................#",
        "#.......................#",
        "#..........G............#",
        "#.......................#",
        "#.......................#",
        "#########################",
    },
    // Stage 3 - 가시밭길
    {
        "#########################",
        "#.......................#",
        "#.......................#",
        "#....B......B...........#",
        "#.......................#",
        "#.......................#",
        "#.......................#",
        "#.....*******...........#",
        "#.......................#",
        "#..........@............#",
        "#.......................#",
        "#.......................#",
        "#.......................#",
        "#.......................#",
        "#..........G............#",
        "#.......................#",
        "#.......................#",
        "#########################",
    },
    // Stage 4 - 잠긴 방
    {
        "#########################",
        "#.......................#",
        "#.......................#",
        "#....K..................#",
        "#.......................#",
        "#.......................#",
        "#.......................#",
        "#..........L............#",
        "#.......................#",
        "#..........@............#",
        "#.......................#",
        "#.......................#",
        "#.......................#",
        "#.......................#",
        "#..........G............#",
        "#.......................#",
        "#.......................#",
        "#########################",
    },
    // Stage 5 - 미로의 중심
    {
        "#########################",
        "#.......................#",
        "#.......................#",
        "#...BB.......BB.........#",
        "#.......................#",
        "#.......................#",
        "#.......................#",
        "#....***.....***........#",
        "#.......................#",
        "#..........@............#",
        "#.......................#",
        "#.......................#",
        "#.......................#",
        "#.......................#",
        "#..........G............#",
        "#.......................#",
        "#.......................#",
        "#########################",
    },
    // Stage 6 - 시간의 압박
    {
        "#########################",
        "#.......................#",
        "#.......................#",
        "#....B..B...............#",
        "#.......................#",
        "#....K..................#",
        "#.......................#",
        "#.....*...L.............#",
        "#.......................#",
        "#..........@............#",
        "#.......................#",
        "#.......................#",
        "#.....*........*........#",
        "#.......................#",
        "#..........G............#",
        "#.......................#",
        "#.......................#",
        "#########################",
    },
    // Stage 7 - 복합 구조
    {
        "#########################",
        "#.......................#",
        "#.......................#",
        "#...B.....B.............#",
        "#.......................#",
        "#...K...................#",
        "#.......................#",
        "#...**....**.L..........#",
        "#.......................#",
        "#..........@............#",
        "#.......................#",
        "#...K...................#",
        "#.......................#",
        "#...L......G............#",
        "#.......................#",
        "#.......................#",
        "#.......................#",
        "#########################",
    },
    // Stage 8 - 심층 미궁
    {
        "#########################",
        "#.......................#",
        "#.......................#",
        "#..B..B..B..............#",
        "#.......................#",
        "#.......................#",
        "#..*..*..*..*...........#",
        "#.......................#",
        "#..K....................#",
        "#..........@............#",
        "#.......................#",
        "#..L....................#",
        "#.......................#",
        "#........G..............#",
        "#.......................#",
        "#.......................#",
        "#.......................#",
        "#########################",
    },
    // Stage 9 - 마지막 관문
    {
        "#########################",
        "#.......................#",
        "#..B..B...B..B..........#",
        "#.......................#",
        "#.......................#",
        "#..**....**..**.........#",
        "#.......................#",
        "#..K....................#",
        "#.......................#",
        "#..........@............#",
        "#.......................#",
        "#..L....................#",
        "#.......................#",
        "#.......................#",
        "#........G..............#",
        "#.......................#",
        "#.......................#",
        "#########################",
    },
    // Stage 10 - 연결의 완성
    {
        "#########################",
        "#.......................#",
        "#..B..B....B..B.........#",
        "#.......................#",
        "#.*.*.*.....*.*.*.......#",
        "#.......................#",
        "#..K....................#",
        "#.......................#",
        "#..L....................#",
        "#..........@............#",
        "#.......................#",
        "#..K....................#",
        "#.......................#",
        "#..L.......G............#",
        "#.......................#",
        "#.......................#",
        "#.......................#",
        "#########################",
    },
};

// ============================================================
//  유틸리티
// ============================================================
void setCursor(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void showCursor(int visible) {
    CONSOLE_CURSOR_INFO info = { 1, visible };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void clearScreen() { system("cls"); }

int getKey() {
    int ch = _getch();
    if (ch == 0 || ch == 224) ch = _getch();
    return ch;
}

void waitMs(int ms) { Sleep(ms); }

// ============================================================
//  HP 바 출력 함수
//  예) HP: ♥♥♥♥♥♡♡♡♡♡  5/10
// ============================================================
void drawHpBar(int hp, int maxHp) {
    printf("HP: ");
    for (int i = 0; i < maxHp; i++) {
        if (i < hp)
            printf(RED "♥" RESET);
        else
            printf(GRAY "♡" RESET);
    }
    printf("  %d / %d", hp, maxHp);
}

// ============================================================
//  방향에 따른 캐릭터 심볼 반환
// ============================================================
const char* getCharSymbol(Direction dir) {
    return CHAR_IDLE;
}

// ============================================================
//  타이틀 화면
// ============================================================
void showTitle() {
    clearScreen();
    showCursor(0);

    setCursor(0, 1);
    printf(CYAN);
    printf("  ============================================================\n");
    printf("  =                                                          =\n");
    printf(RESET);
    printf(YELLOW);
    printf("  =  ██████╗ ██████╗ ███╗  ██╗███╗  ██╗███████╗ ██████╗████╗ =\n");
    printf("  =  ██╔════╝██╔══██╗████╗ ██║████╗ ██║██╔════╝██╔════╝╚══██╗=\n");
    printf("  =  ██║     ██║  ██║██╔██╗██║██╔██╗██║█████╗  ██║        ██╔╝=\n");
    printf("  =  ██║     ██║  ██║██║╚████║██║╚████║██╔══╝  ██║       ██╔╝ =\n");
    printf("  =  ╚██████╗╚██████╔╝██║ ╚███║██║ ╚███║███████╗╚██████╗██║   =\n");
    printf("  =   ╚═════╝ ╚═════╝ ╚═╝  ╚══╝╚═╝  ╚══╝╚══════╝ ╚═════╝╚═╝  =\n");
    printf(RESET);
    printf(CYAN);
    printf("  =                                                          =\n");
    printf(RESET);
    printf(WHITE);
    printf("  =        ┌──────────────────────────────────────┐         =\n");
    printf("  =        │   길을 만들고, 연결하고, 살아남아라!  │         =\n");
    printf("  =        └──────────────────────────────────────┘         =\n");
    printf(RESET);

    // 캐릭터 소개 애니메이션
    printf(CYAN);
    printf("  =                                                          =\n");
    printf(RESET);
    printf(GREEN);
    printf("  =          人  <-- 이 사람을 목표까지 이끌어라!           =\n");
    printf(RESET);
    printf(CYAN);
    printf("  =                                                          =\n");
    printf("  ============================================================\n");
    printf(RESET);

    int blink = 1;
    clock_t t = clock();
    printf("\n");

    while (!_kbhit()) {
        if ((double)(clock() - t) / CLOCKS_PER_SEC > 0.5) {
            setCursor(16, 16);
            if (blink)
                printf(YELLOW "   ▶▶  Press Any Key to Start  ◀◀   " RESET);
            else
                printf("                                     ");
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

    printf(CYAN);
    printf("  ╔════════════════════════════════════════════════╗\n");
    printf("  ║         📖  C O N N E C T  조작법              ║\n");
    printf("  ╠════════════════════════════════════════════════╣\n");
    printf(RESET);

    printf(WHITE);
    printf("  ║                                                ║\n");
    printf("  ║  [ 이동 ]                                      ║\n");
    printf("  ║    W / ↑  :  위로 이동     (仌  모양)         ║\n");
    printf("  ║    S / ↓  :  아래로 이동   (众 모양)         ║\n");
    printf("  ║    A / ←  :  왼쪽 이동     (〈 모양)         ║\n");
    printf("  ║    D / →  :  오른쪽 이동   (〉 모양)         ║\n");
    printf("  ║                                                ║\n");
    printf("  ║  [ 기능 ]                                      ║\n");
    printf("  ║    Z      :  한 칸 되돌리기 (Undo)            ║\n");
    printf("  ║    R      :  스테이지 재시작                   ║\n");
    printf("  ║    ESC    :  스테이지 선택으로                 ║\n");
    printf("  ║                                                ║\n");
    printf("  ╠════════════════════════════════════════════════╣\n");
    printf("  ║  [ 타일 ]                                      ║\n");
    printf(RESET);

    printf("  ║   " CYAN   "人/仌/众/〈/〉" RESET " : 플레이어 (방향따라 변함) ║\n");
    printf("  ║   " MAGENTA "G" RESET "  : 목표지점                            ║\n");
    printf("  ║   " YELLOW  "B" RESET "  : 밀 수 있는 블록                     ║\n");
    printf("  ║   " RED     "*" RESET "  : 가시 (밟으면 HP -1!)               ║\n");
    printf("  ║   " GREEN   "K" RESET "  : 열쇠                                ║\n");
    printf("  ║   " RED     "L" RESET "  : 잠긴 문                             ║\n");
    printf("  ║   " BLUE    "#" RESET "  : 벽                                  ║\n");

    printf(WHITE);
    printf("  ║                                                ║\n");
    printf("  ╠════════════════════════════════════════════════╣\n");
    printf("  ║  [ HP 시스템 ]                                 ║\n");
    printf("  ║   각 스테이지마다 HP가 다르게 주어집니다.     ║\n");
    printf("  ║   가시(*)를 밟을 때마다 HP -1 감소.           ║\n");
    printf("  ║   HP가 0이 되면 GAME OVER!                    ║\n");
    printf("  ║   이동 횟수 제한은 없으나,                    ║\n");
    printf("  ║   적게 이동할수록 높은 별점!                  ║\n");
    printf("  ║                                                ║\n");
    printf("  ╚════════════════════════════════════════════════╝\n");
    printf(RESET);

    printf("\n" YELLOW "        [ 아무 키나 누르면 돌아갑니다 ]" RESET "\n");
    _getch();
}

// ============================================================
//  메인 메뉴
// ============================================================
Scene showMainMenu() {
    int selected = 0;
    int key;

    const char* items[] = {
        "    게임 시작    ",
        "    이어하기     ",
        "    조작법       ",
        "    종료         "
    };
    int itemCount = 4;

    while (1) {
        clearScreen();
        showCursor(0);

        printf(CYAN);
        printf("  ╔══════════════════════════════════════════╗\n");
        printf("  ║                                          ║\n");
        printf("  ║         C  O  N  N  E  C  T             ║\n");
        printf("  ║                                          ║\n");
        printf("  ║       길을 만들고 목표에 닿아라          ║\n");
        printf("  ║                                          ║\n");
        printf("  ╠══════════════════════════════════════════╣\n");
        printf(RESET);

        printf("  ║                                          ║\n");

        for (int i = 0; i < itemCount; i++) {
            if (i == selected) {
                printf("  ║      " YELLOW "┌─────────────────────┐" RESET "      ║\n");
                printf("  ║      " YELLOW "│  ▶  %-16s│" RESET "      ║\n", items[i]);
                printf("  ║      " YELLOW "└─────────────────────┘" RESET "      ║\n");
            }
            else {
                printf("  ║           " WHITE "%-18s" RESET "          ║\n", items[i]);
            }
            printf("  ║                                          ║\n");
        }

        printf(CYAN);
        printf("  ╠══════════════════════════════════════════╣\n");
        printf("  ║     " GREEN "人" RESET "  연결하라, 살아남아라!  " GREEN "人" RESET "     ║\n");
        printf("  ╚══════════════════════════════════════════╝\n");
        printf(RESET);

        printf("\n  " GRAY "[↑↓] 이동   [Enter] 선택   [ESC] 종료" RESET "\n");

        key = getKey();

        if (key == KEY_UP)
            selected = (selected - 1 + itemCount) % itemCount;
        else if (key == KEY_DOWN)
            selected = (selected + 1) % itemCount;
        else if (key == KEY_ENTER) {
            switch (selected) {
            case 0: return SCENE_STAGESELECT;
            case 1: return SCENE_STAGESELECT;
            case 2: showHowToPlay(); break;
            case 3: return SCENE_EXIT;
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

    for (int i = 0; i < MAX_STAGES; i++) {
        if (stages[i].status != STAGE_LOCKED) selected = i;
        else break;
    }

    while (1) {
        clearScreen();
        showCursor(0);

        printf(CYAN);
        printf("  ╔══════════════════════════════════════════════╗\n");
        printf("  ║       ◈  C O N N E C T  스테이지  ◈         ║\n");
        printf("  ╠══════════════════════════════════════════════╣\n");
        printf(RESET);
        printf("  ║                                              ║\n");

        // 5x2 그리드
        for (int row = 0; row < 2; row++) {
            // 상단 테두리
            printf("  ║    ");
            for (int col = 0; col < 5; col++) {
                int idx = row * 5 + col;
                if (idx == selected)                      printf(YELLOW "┌──────┐" RESET "  ");
                else if (stages[idx].status == STAGE_CLEARED)  printf(GREEN  "┌──────┐" RESET "  ");
                else if (stages[idx].status == STAGE_UNLOCKED) printf(WHITE  "┌──────┐" RESET "  ");
                else                                            printf(GRAY   "┌──────┐" RESET "  ");
            }
            printf("║\n");

            // 번호
            printf("  ║    ");
            for (int col = 0; col < 5; col++) {
                int idx = row * 5 + col;
                char cell[10];
                if (stages[idx].status == STAGE_LOCKED) sprintf(cell, " LOCK ");
                else                                     sprintf(cell, "  %2d  ", idx + 1);

                if (idx == selected)                      printf(YELLOW "│%s│" RESET "  ", cell);
                else if (stages[idx].status == STAGE_CLEARED)  printf(GREEN  "│%s│" RESET "  ", cell);
                else if (stages[idx].status == STAGE_UNLOCKED) printf(WHITE  "│%s│" RESET "  ", cell);
                else                                            printf(GRAY   "│%s│" RESET "  ", cell);
            }
            printf("║\n");

            // 하단 테두리
            printf("  ║    ");
            for (int col = 0; col < 5; col++) {
                int idx = row * 5 + col;
                if (idx == selected)                      printf(YELLOW "└──────┘" RESET "  ");
                else if (stages[idx].status == STAGE_CLEARED)  printf(GREEN  "└──────┘" RESET "  ");
                else if (stages[idx].status == STAGE_UNLOCKED) printf(WHITE  "└──────┘" RESET "  ");
                else                                            printf(GRAY   "└──────┘" RESET "  ");
            }
            printf("║\n");

            // HP 아이콘 표시
            printf("  ║    ");
            for (int col = 0; col < 5; col++) {
                int idx = row * 5 + col;
                if (stages[idx].status == STAGE_CLEARED)
                    printf(GREEN "  [★]   " RESET "  ");
                else if (stages[idx].status == STAGE_UNLOCKED)
                    printf(CYAN  "  [▶]   " RESET "  ");
                else
                    printf(GRAY  "  [🔒]  " RESET "  ");
            }
            printf("║\n");
            printf("  ║                                              ║\n");
        }

        printf(CYAN "  ╠══════════════════════════════════════════════╣\n" RESET);

        Stage* s = &stages[selected];
        printf("  ║  STAGE %2d  :  %-31s║\n", s->id, s->name);
        printf("  ║  설   명   :  %-31s║\n", s->description);

        // 별점
        printf("  ║  난 이 도  :  ");
        for (int i = 0; i < 5; i++) {
            if (i < s->difficulty) printf(YELLOW "★" RESET);
            else                   printf(GRAY   "☆" RESET);
        }
        printf("                               ║\n");

        // HP 표시
        printf("  ║  시작  HP  :  ");
        for (int i = 0; i < s->startHp; i++) {
            if (i < s->startHp) printf(RED "♥" RESET);
        }
        printf("  (%d)               ║\n", s->startHp);

        if (s->status == STAGE_CLEARED)
            printf("  ║  " GREEN "최고기록 : %3d번 이동" RESET "                      ║\n", s->bestMoves);
        else if (s->status == STAGE_UNLOCKED)
            printf("  ║  " CYAN "▶ 도전해보세요!" RESET "                            ║\n");
        else
            printf("  ║  " RED "🔒 이전 스테이지 클리어 후 해금" RESET "          ║\n");

        printf(CYAN "  ╚══════════════════════════════════════════════╝\n" RESET);
        printf("\n  " GRAY "[←→↑↓] 이동   [Enter] 시작   [ESC] 메뉴" RESET "\n");

        key = getKey();

        if (key == KEY_LEFT && selected > 0)              selected--;
        else if (key == KEY_RIGHT && selected < MAX_STAGES - 1) selected++;
        else if (key == KEY_UP && selected >= 5)             selected -= 5;
        else if (key == KEY_DOWN && selected + 5 < MAX_STAGES) selected += 5;
        else if (key == KEY_ENTER) {
            if (stages[selected].status != STAGE_LOCKED) {
                selectedStage = selected;
                return SCENE_GAME;
            }
            else {
                setCursor(2, 31);
                printf(RED "  ⚠  잠긴 스테이지! 이전 스테이지를 클리어하세요!" RESET);
                waitMs(1500);
            }
        }
        else if (key == KEY_ESC) return SCENE_MAINMENU;
    }
}

// ============================================================
//  게임 로드
// ============================================================
void loadStage(int stageIdx) {
    memset(&gs, 0, sizeof(GameState));
    gs.moveCount = 0;
    gs.isCleared = 0;
    gs.undoTop = -1;

    // HP 설정
    gs.player.hp = stages[stageIdx].startHp;
    gs.player.maxHp = stages[stageIdx].startHp;
    gs.player.dir = DIR_IDLE;
    gs.player.hasKey = 0;

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
    memcpy(gs.originalMap, gs.map, sizeof(gs.map));
}

// ============================================================
//  되돌리기
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

    // ── 상단 정보바 ──
    printf(CYAN);
    printf("  ╔══════════════════════════════════════════════════╗\n");
    printf("  ║  CONNECT  │  STAGE %-2d : %-22s║\n", s->id, s->name);
    printf("  ╠══════════════════════════════════════════════════╣\n");
    printf("  ║  ");
    printf(RESET);

    // HP 바
    drawHpBar(gs.player.hp, gs.player.maxHp);

    printf(CYAN "   │  이동: " RESET);

    // 이동 횟수 색상 (기준 이동수 대비)
    if (gs.moveCount > s->maxMoves)       printf(RED);
    else if (gs.moveCount > s->maxMoves * 0.75) printf(YELLOW);
    else                                        printf(GREEN);
    printf("%3d", gs.moveCount);
    printf(RESET);

    printf(CYAN "회" RESET);
    printf(CYAN "   │  열쇠: " RESET);
    if (gs.player.hasKey) printf(GREEN "🔑" RESET);
    else                   printf(GRAY  "없음" RESET);

    printf(CYAN "  ║\n");
    printf("  ╚══════════════════════════════════════════════════╝\n");
    printf(RESET);

    printf("\n");

    // ── 맵 출력 ──
    for (int y = 0; y < MAP_H; y++) {
        printf("  ");
        for (int x = 0; x < MAP_W; x++) {
            // 플레이어 위치 → 방향에 따른 캐릭터
            if (x == gs.player.x && y == gs.player.y) {
                printf(CYAN "%s" RESET, getCharSymbol(gs.player.dir));
                continue;
            }
            char tile = gs.map[y][x];
            switch (tile) {
            case TILE_WALL:  printf(BLUE    "#" RESET); break;
            case TILE_BLOCK: printf(YELLOW  "B" RESET); break;
            case TILE_SPIKE: printf(RED     "*" RESET); break;
            case TILE_GOAL:  printf(MAGENTA "G" RESET); break;
            case TILE_KEY:   printf(GREEN   "K" RESET); break;
            case TILE_LOCK:  printf(RED     "L" RESET); break;
            case TILE_EMPTY: printf(GRAY    "." RESET); break;
            default:         printf(" ");               break;
            }
        }
        printf("\n");
    }

    // ── 하단 조작법 ──
    printf("\n");
    printf(GRAY);
    printf("  ╔══════════════════════════════════════════════════╗\n");
    printf("  ║  [WASD / 방향키] 이동     [Z] 되돌리기 (Undo)  ║\n");
    printf("  ║  [R] 재시작               [ESC] 스테이지 선택  ║\n");
    printf("  ╚══════════════════════════════════════════════════╝\n");
    printf(RESET);

    // ── 범례 ──
    printf("  ");
    printf(CYAN "人" RESET "/");
    printf(CYAN "仌" RESET "/");
    printf(CYAN "众" RESET "/");
    printf(CYAN "〈" RESET "/");
    printf(CYAN "〉" RESET " 나   ");
    printf(MAGENTA "G" RESET " 목표   ");
    printf(YELLOW  "B" RESET " 블록   ");
    printf(RED     "*" RESET " 가시(-HP)   ");
    printf(GREEN   "K" RESET " 열쇠   ");
    printf(RED     "L" RESET " 잠긴문\n");
}

// ============================================================
//  가시 피해 시각 효과 (화면 빨강 깜빡임)
// ============================================================
void spikeEffect() {
    // 커서를 맨 위로 올려 화면 테두리를 빨갛게 표시
    setCursor(0, 0);
    printf(RED "  !!! 가시에 찔렸다! HP -1 !!!" RESET);
    waitMs(300);
    setCursor(0, 0);
    printf("                              ");
    waitMs(100);
}

// ============================================================
//  플레이어 이동 처리
//  반환: 1 = 클리어, -1 = HP 0 게임오버, 0 = 계속
// ============================================================
int movePlayer(int dx, int dy) {
    int nx = gs.player.x + dx;
    int ny = gs.player.y + dy;

    // 방향 업데이트 (이동 시도 시 항상)
    if (dx == 0 && dy == -1) gs.player.dir = DIR_UP;
    else if (dx == 0 && dy == 1) gs.player.dir = DIR_DOWN;
    else if (dx == -1 && dy == 0) gs.player.dir = DIR_LEFT;
    else if (dx == 1 && dy == 0) gs.player.dir = DIR_RIGHT;

    if (nx < 0 || nx >= MAP_W || ny < 0 || ny >= MAP_H) return 0;

    char tile = gs.map[ny][nx];

    // 벽 → 이동 불가, 방향만 바뀜
    if (tile == TILE_WALL) return 0;

    // 블록 밀기
    if (tile == TILE_BLOCK) {
        int bnx = nx + dx;
        int bny = ny + dy;
        if (bnx < 0 || bnx >= MAP_W || bny < 0 || bny >= MAP_H) return 0;
        if (gs.map[bny][bnx] == TILE_WALL ||
            gs.map[bny][bnx] == TILE_BLOCK ||
            gs.map[bny][bnx] == TILE_LOCK)  return 0;

        pushUndo();
        gs.map[bny][bnx] = TILE_BLOCK;
        gs.map[ny][nx] = TILE_EMPTY;
    }
    else {
        pushUndo();
    }

    // 플레이어 이동
    gs.player.x = nx;
    gs.player.y = ny;
    gs.moveCount++;

    // ── 가시 처리 : HP -1 ──
    if (tile == TILE_SPIKE) {
        gs.player.hp--;
        spikeEffect();

        // HP 0 → 게임오버
        if (gs.player.hp <= 0) {
            return -1;
        }
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
            popUndo();
            return 0;
        }
    }

    // 목표 도달
    if (tile == TILE_GOAL) return 1;

    return 0;
}

// ============================================================
//  클리어 화면
// ============================================================
Scene showClearScreen() {
    clearScreen();
    showCursor(0);

    Stage* s = &stages[selectedStage];

    // 별점: 이동 횟수 기준
    int stars;
    float ratio = (float)gs.moveCount / s->maxMoves;
    if (ratio <= 0.5f)  stars = 3;
    else if (ratio <= 0.75f) stars = 2;
    else                     stars = 1;

    // 남은 HP에 따라 보너스 별점
    if (gs.player.hp == gs.player.maxHp && stars < 3) stars++;

    // 최고기록
    int isNewRecord = 0;
    if (s->bestMoves == 0 || gs.moveCount < s->bestMoves) {
        s->bestMoves = gs.moveCount;
        isNewRecord = 1;
    }

    // 다음 스테이지 해금
    if (selectedStage + 1 < MAX_STAGES)
        stages[selectedStage + 1].status = STAGE_UNLOCKED;
    stages[selectedStage].status = STAGE_CLEARED;

    printf("\n");
    printf(GREEN);
    printf("  ╔══════════════════════════════════════════════╗\n");
    printf("  ║                                              ║\n");
    printf("  ║      🎉  S T A G E   C L E A R  !  🎉      ║\n");
    printf("  ║                                              ║\n");
    printf("  ╠══════════════════════════════════════════════╣\n");
    printf("  ║                                              ║\n");
    printf(RESET);

    printf("  ║   스테이지  :  " YELLOW "%-28s" RESET "║\n", s->name);
    printf("  ║   사용 이동 :  " CYAN "%3d회" RESET "  (기준 " GRAY "%3d회" RESET ")                ║\n",
        gs.moveCount, s->maxMoves);

    // 남은 HP
    printf("  ║   남은  HP  :  ");
    for (int i = 0; i < gs.player.maxHp; i++) {
        if (i < gs.player.hp) printf(RED "♥ " RESET);
        else                   printf(GRAY "♡ " RESET);
    }
    printf("║\n");

    printf("  ║   평    가  :  ");
    for (int i = 0; i < 3; i++) {
        if (i < stars) printf(YELLOW "★  " RESET);
        else           printf(GRAY   "☆  " RESET);
    }
    printf("                        ║\n");

    printf("  ║                                              ║\n");

    if (isNewRecord)
        printf("  ║   " GREEN "🏆 NEW RECORD!  %d회 이동 달성!" RESET "         ║\n",
            s->bestMoves);
    else
        printf("  ║   " GRAY "이전 기록 : %d번 이동" RESET "                      ║\n",
            s->bestMoves);

    printf("  ║                                              ║\n");
    printf(GREEN);
    printf("  ╠══════════════════════════════════════════════╣\n");
    printf("  ║                                              ║\n");
    printf(RESET);

    if (selectedStage + 1 < MAX_STAGES)
        printf("  ║   " CYAN "[Enter]" RESET "  다음 스테이지로                  ║\n");
    else
        printf("  ║   " YELLOW "[Enter]" RESET "  🎊 모든 스테이지 클리어!       ║\n");

    printf("  ║   " WHITE "[R]    " RESET "  이 스테이지 다시 도전             ║\n");
    printf("  ║   " GRAY  "[ESC]  " RESET "  스테이지 선택으로                 ║\n");
    printf("  ║                                              ║\n");
    printf(GREEN "  ╚══════════════════════════════════════════════╝\n" RESET);

    while (1) {
        int key = getKey();
        if (key == KEY_ENTER) {
            if (selectedStage + 1 < MAX_STAGES) { selectedStage++; return SCENE_GAME; }
            else return SCENE_STAGESELECT;
        }
        else if (key == KEY_R || key == 'R') return SCENE_GAME;
        else if (key == KEY_ESC)             return SCENE_STAGESELECT;
    }
}

// ============================================================
//  게임오버 화면
// ============================================================
Scene showGameOverScreen() {
    clearScreen();
    showCursor(0);

    printf("\n");
    printf(RED);
    printf("  ╔══════════════════════════════════════════════╗\n");
    printf("  ║                                              ║\n");
    printf("  ║        💀  G A M E   O V E R  💀            ║\n");
    printf("  ║                                              ║\n");
    printf("  ╠══════════════════════════════════════════════╣\n");
    printf("  ║                                              ║\n");
    printf(RESET);

    printf("  ║   " RED "가시에 찔려 HP가 모두 소진됐습니다!" RESET "     ║\n");
    printf("  ║                                              ║\n");

    // 하트 표시
    printf("  ║   남은 HP : ");
    for (int i = 0; i < stages[selectedStage].startHp; i++)
        printf(GRAY "♡ " RESET);
    printf("║\n");

    printf("  ║                                              ║\n");
    printf("  ║   사용 이동 : " YELLOW "%3d회" RESET "                          ║\n",
        gs.moveCount);
    printf("  ║                                              ║\n");
    printf("  ║   " CYAN "다시 도전! 가시를 피해 나아가세요!" RESET "      ║\n");
    printf("  ║                                              ║\n");
    printf(RED);
    printf("  ╠══════════════════════════════════════════════╣\n");
    printf("  ║                                              ║\n");
    printf(RESET);
    printf("  ║   " CYAN "[R]    " RESET "  다시 시작                         ║\n");
    printf("  ║   " GRAY "[ESC]  " RESET "  스테이지 선택으로                 ║\n");
    printf("  ║                                              ║\n");
    printf(RED "  ╚══════════════════════════════════════════════╝\n" RESET);

    while (1) {
        int key = getKey();
        if (key == KEY_R || key == 'R') return SCENE_GAME;
        if (key == KEY_ESC)             return SCENE_STAGESELECT;
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
        case KEY_UP:    case KEY_W: case 'W':
            result = movePlayer(0, -1); break;
        case KEY_DOWN:  case KEY_S: case 'S':
            result = movePlayer(0, 1); break;
        case KEY_LEFT:  case KEY_A: case 'A':
            result = movePlayer(-1, 0); break;
        case KEY_RIGHT: case KEY_D: case 'D':
            result = movePlayer(1, 0); break;
        case KEY_Z: case 'Z':
            popUndo(); break;
        case KEY_R: case 'R':
            loadStage(selectedStage); break;
        case KEY_ESC:
            return SCENE_STAGESELECT;
        }

        if (result == 1) return showClearScreen();
        if (result == -1) {
            Scene next = showGameOverScreen();
            if (next == SCENE_GAME) loadStage(selectedStage);
            return next;
        }
    }
}

// ============================================================
//  메인 함수
// ============================================================
int main() {
    SetConsoleOutputCP(65001);
    system("mode con cols=70 lines=45");

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

    srand((unsigned int)time(NULL));
    currentScene = SCENE_TITLE;

    while (currentScene != SCENE_EXIT) {
        switch (currentScene) {
        case SCENE_TITLE:      showTitle();  currentScene = SCENE_MAINMENU;  break;
        case SCENE_MAINMENU:   currentScene = showMainMenu();                break;
        case SCENE_STAGESELECT:currentScene = showStageSelect();             break;
        case SCENE_GAME:       currentScene = runGame();                     break;
        case SCENE_EXIT:                                                      break;
        default:               currentScene = SCENE_MAINMENU;               break;
        }
    }

    clearScreen();
    printf("\n\n");
    printf(CYAN  "  ╔══════════════════════════════════════════╗\n" RESET);
    printf(CYAN  "  ║                                          ║\n" RESET);
    printf(CYAN  "  ║   CONNECT를 플레이해주셔서 감사합니다!   ║\n" RESET);
    printf(CYAN  "  ║                                          ║\n" RESET);
    printf(CYAN  "  ║           See You Again!                 ║\n" RESET);
    printf(CYAN  "  ║                                          ║\n" RESET);
    printf(CYAN  "  ╚══════════════════════════════════════════╝\n" RESET);
    waitMs(1500);

    showCursor(1);
    return 0;
}