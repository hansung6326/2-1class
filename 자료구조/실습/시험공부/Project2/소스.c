#include <stdio.h>

void a(int n) { // 5 22 1111 
	if (n > 0) {
		a(n / 2);
		a(n / 2);
		printf("\n");
	}
	printf("*");
}

int main() {
	a(5);
	return 0;
}