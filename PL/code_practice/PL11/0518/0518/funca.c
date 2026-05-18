#include <stdio.h>

void A(int x[]) {
	printf("x[0] = %d : x[1] = %d\n", x[0], x[1]);
	x[0] = 100;
	x[1] = 200;
}