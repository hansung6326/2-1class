#include <stdio.h>

int factorial(int f) {
	if (f <= 1)
		return 1;
	else
		return (f * factorial(f - 1));
}

int power(int x, int n) {
	if (n == 0)
		return 1;
	else if ((n % 2) == 0)
		return power(x * x, n / 2);
	else
		return x * power(x * x, (n - 1) / 2);
}

int fib(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return (fib(n - 2) + fib(n - 1));
}

int main(void) {
	int id = 2371172;
	int num = (id % 10) + 2; // 4

	printf("결과물: 학번(%d)\n", id);
	printf("학번의 마지막 자리 숫자는 %d이고 2를 더하면 %d입니다.\n", id % 10, num);
	printf("1. 팩토리얼 : %d!의 결과 %d \n", num, factorial(num));
	printf("2. 거듭제곱 : 2의 %d승의 결과 %d \n", num, power(2, num));
	printf("3. 피보나치 : n=%d인 피보나치 수의 결과 %d\n", num, fib(num));

	return 0;
}