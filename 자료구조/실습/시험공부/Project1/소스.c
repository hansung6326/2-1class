#include <stdio.h>

int factorial(int f) {
	if (f == 0) //if(f<=1)
		return 1;
	else if (f == 1)  
		return 1;
	else
		return f * factorial(f - 1);
}
int factorial2(int f) {
	int result = 1;
	for (int i = 1; i <= f; i++) {
		result *= i;
	}
	return result;
}

int power(int x, int p) {
	if (p == 0)
		return 1;
	else if (p % 2 == 0)
		return power(x * x, p / 2);
	else
		return x * power(x * x, (p - 1) / 2);
}
int power2(int x, int p) {
	int result = 1;
	for (int i = 0; i < p; i++) {
		result *= x;
	}
	return result;
}

int fibonacci(int f) {
	if (f == 0)
		return 0;
	else if (f == 1)
		return 1;
	else
		return fibonacci(f - 2) + fibonacci(f - 1);
}
int fibonacci2(int f) {
	if (f == 0)
		return 0;
	else if (f == 1)
		return 1;
	int a = 0; int b = 1; int c;
	for (int i = 2; i <= f; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	return b;
}

int main(void) {
	int num = 6; // 4

	printf("숫자 : %d\n", num);
	printf("1. 팩토리얼 : %d!의 결과 %d \n", num, factorial(num));
	printf("2. 거듭제곱 : 2의 %d승의 결과 %d \n", num, power(2, num));
	printf("3. 피보나치 : n=%d인 피보나치 수의 결과 %d\n", num, fibonacci(num));

	return 0;
}