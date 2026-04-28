#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int prime(int n) {
	int is_prime = 1;
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			is_prime = 0;
			break;
		}	
	}
	return is_prime;
}

int main() {
	int n, flag = 0;

	printf("양의 정수를 입력하세요: ");
	scanf("%d", &n);

	for (int i = 2; i < n; i++) {
		if (prime(i) == 1) {
			if (prime(n - i) == 1) {
				printf("%d = %d + %d\n", n, i, n - i);
				flag = 1;
				break;
			}
		}

	}
	if (flag == 0)
		printf("소수들의 합으로 표현될 수 없습니다\n");
}