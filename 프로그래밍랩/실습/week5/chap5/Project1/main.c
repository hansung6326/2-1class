#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct TIME {
	int hours, minutes, seconds;
};

// t1: 시작시간, t2: 종료 시간, differ: 두 시간의 차이
void diff_time(struct TIME t1, struct TIME t2, struct TIME* differ) {
	differ->hours = t2.hours - t1.hours;
	differ->minutes = t2.minutes - t1.minutes;
	differ->seconds = t2.seconds - t1.seconds;

	// 초가 음수이면 분에서 1분을 빌려옴
	if (differ->seconds < 0) {
		differ->minutes--;
		differ->seconds += 60;
	}
	// 분이 음수이면 시에서 1시간을 빌려옴
	if (differ->minutes < 0) {
		differ->hours--;
		differ->minutes += 60;
	}
}

int main(void) {
	struct TIME t1, t2, diff;

	printf("시작 시간(시, 분, 초): ");
	scanf("%d %d %d", &t1.hours, &t1.minutes, &t1.seconds);

	printf("종료 시간(시, 분, 초): ");
	scanf("%d %d %d", &t2.hours, &t2.minutes, &t2.seconds);

	// 두 시간의 차이 계산
	diff_time(t1, t2, &diff);

	// 결과 출력
	printf("차이: %d시간 %d분 %d초\n", diff.hours, diff.minutes, diff.seconds);

	return 0;
}