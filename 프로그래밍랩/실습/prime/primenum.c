#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 소수인지 판별하는 함수
int prime_number(int n) {
	int is_prime = 1; // 일단 소수라고 가정 (1)

	// 2부터 n-1까지 나누어 떨어지는 숫자가 있는지 확인
	for (int i = 2; i < n; i++) {
		if (n % i == 0) { // 나누어 떨어지면 소수가 아님
			is_prime = 0; // 0으로 변경
			break;        // 더 확인할 필요 없으므로 반복문 탈출
		}
	}
	return is_prime; // 1이면 소수, 0이면 소수 아님
}

int main(void) {
	int k;
	printf("정수를 입력하세요: "); // 깨진 부분: 입력 안내 문구
	scanf("%d", &k); // scanf_s 사용 시 환경에 따라 매개변수 차이가 있을 수 있어 scanf로 표기

	// 함수를 호출하여 결과값에 따라 출력
	if (prime_number(k) == 1)
		printf("소수입니다. \n"); // 깨진 부분: 소수일 때
	else if (prime_number(k) == 0)
		printf("소수가 아닙니다. \n"); // 깨진 부분: 소수가 아닐 때

	return 0;
}