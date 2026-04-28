#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 소수인지 확인하는 함수 (소수이면 1, 아니면 0 반환)
int prime_number(int n) {
	int is_prime = 1; // 일단 소수라고 가정
	for (int i = 2; i < n; i++) {
		if (n % i == 0) { // 2부터 n-1까지 나누어 떨어지는 수가 있다면
			is_prime = 0; // 소수가 아님
			break;
		}
	}
	return is_prime;
}

int main(void) {
	int k, flag = 0;
	printf("양의 정수를 입력하세요: "); // 깨진 부분 복구
	scanf("%d", &k); // scanf_s 대신 일반적인 scanf 사용 (또는 환경에 따라 유지)

	// i와 k-i 두 숫자가 모두 소수인지 확인하여 합으로 표현 가능성 체크
	for (int i = 2; i < k; i++) {
		if (prime_number(i) == 1) { // 첫 번째 수(i)가 소수이고
			if (prime_number(k - i) == 1) { // 두 번째 수(k-i)도 소수라면
				printf("%d = %d + %d\n", k, i, k - i); // 합의 공식 출력
				flag = 1; // 합으로 표현 가능한 케이스를 찾았음을 표시
				break; // 한 가지만 보고 싶다면 여기서 break (모든 경우를 보려면 생략)
			}
		}
	}

	if (flag == 0)
		// 깨진 부분: 소수들의 합으로 나타낼 수 없는 경우
		printf("%d는 소수들의 합으로 표시될 수 없습니다.\n", k);

	return 0;
}