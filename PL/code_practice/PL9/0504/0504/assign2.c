#include <stdio.h>

double a, b, c, d;

void func();

int main() {
	func();
}

void func() {
	int i;
	int* ip;

	a = 10.1;
	i = 10;
	ip = (int*)malloc(sizeof(int));
	*ip = 10;
}