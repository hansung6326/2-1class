#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

	int score, a, count = 0;

	srand(time(NULL));
	score = rand() % 100 + 1;

	do {
		printf("정답을 맞춰보세요: ");
		scanf("%d", &a);
		count++;

		if (a > score) {
			printf("입력한 값이 큽니다.\n");
		}
		else if (a < score) {
			printf("입력한 값이 작습니다.\n");
		}

	} while (score != a);

	printf("정답입니다. 시도횟수=%d\n", count);

	return 0;
}