#include <stdio.h>

int A(int x);

int main() {

	int a[3];
	
	a[0] = 10;
	a[1] = 20;
	
	A(a);
	printf("a[0] = %d : a[1] = %d\n", a[0], a[1]);

	return 0;
}