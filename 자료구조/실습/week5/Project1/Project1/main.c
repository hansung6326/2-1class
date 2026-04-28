#include <stdio.h>

int main(void) {
	int two[10];
	int value = 1;
	for (int i = 0; i < 10; i++) {
		two[i] = value;
		value *= 2;
		printf("two[%d] = %d 입니다.\n", i, two[i]);
	}

	return 0;
}