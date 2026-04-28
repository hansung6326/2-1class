#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand((unsigned int)time(NULL)); // 캐스팅 추가 (권장)

    int input = 0, score, count = 0;
    score = rand() % 100 + 1;

    printf("1부터 100 사이의 숫자를 맞춰보세요!\n");

    do {
        printf("입력: ");
        scanf("%d", &input);
        count++;

        if (input > score)
            printf("정답은 %d보다 작습니다. (Down)\n", input);
        else if (input < score)
            printf("정답은 %d보다 큽니다. (Up)\n", input);

    } while (input != score);

    printf("\n축하합니다! 정답입니다.\n");
    printf("총 시도 횟수: %d회\n", count);

    return 0;
}