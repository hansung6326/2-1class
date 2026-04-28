#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 가위(0), 바위(1), 보(2)를 열거형으로 정의
enum game { scissor, rock, paper };

// 열거형 값을 문자열로 변환해주는 함수
const char* toString(enum game g) {
	if (g == scissor) return "가위";
	else if (g == rock) return "바위";
	else return "보";
}

int main(void) {
	int user_input; // scanf로 직접 enum에 넣기보다 int로 받는 것이 안전합니다.
	enum game user;
	enum game computer;

	// 난수 생성기 초기화는 프로그램 시작 시 한 번만 수행하는 것이 좋습니다.
	srand((unsigned int)time(NULL));

	while (1) {
		printf("가위(0), 바위(1), 보(2) / 종료(-1): ");
		scanf("%d", &user_input);

		if (user_input == -1) {
			printf("게임 종료\n");
			break;
		}

		user = (enum game)user_input; // 입력받은 숫자를 열거형으로 변환
		computer = rand() % 3;       // 0, 1, 2 중 랜덤 생성

		printf("사용자: %s, 컴퓨터: %s\n", toString(user), toString(computer));

		// 승패 판정 로직
		if (user == computer)
			printf("비겼습니다\n");
		else if ((user == scissor && computer == paper) ||
			(user == rock && computer == scissor) ||
			(user == paper && computer == rock))
			printf("이겼습니다\n");
		else
			printf("졌습니다\n");
		printf("\n");
	}
	return 0;
}