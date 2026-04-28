#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a, b;
	for (a = 0; a < 5; a++) {
		for (b = 0; b < 10; b++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}