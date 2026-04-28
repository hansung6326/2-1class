#define _CRT_SECURE_NO_WARNINGS  //strcpy() 때문
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strcpy 함수 사용을 위해 필요합니다.
#include <malloc.h>

struct test {
	int i;
	char str[20];
};

int main(void) {
	struct test* p;
	p = (struct test*)malloc(sizeof(struct test));

	if (p == NULL) {
		// 깨진 부분: 메모리 할당 실패 시 출력되는 에러 메시지
		printf("메모리가 부족해서 할당할 수 없습니다.\n");
		exit(1);
	}

	p->i = 100;
	// 문자열 상수를 구조체 내 배열에 복사합니다.
	strcpy(p->str, "just testing");

	printf("i: %d\n", p->i);
	printf("str: %s\n", p->str);

	// 동적 할당된 메모리를 반드시 해제합니다.
	free(p);

	return 0;
}