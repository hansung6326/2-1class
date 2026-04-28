#include <stdio.h>

typedef struct Complex{
	int real;
	int imginary;
}Complex;

Complex add(Complex a, Complex b) {
	Complex c;
	c.real = a.real + b.real;
	c.imginary = a.imginary + b.imginary;
	return c;
}

int main(void) {
	Complex A = { 21, 30 };
	Complex B = { 15, 99 };
	Complex C;
	C = add(A, B);
	printf("%d \t %d \n", C.real, C.imginary);

}