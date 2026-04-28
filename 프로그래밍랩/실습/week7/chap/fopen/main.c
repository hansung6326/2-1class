#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE* fp = NULL;

	fp = fopen("alphabet.txt", "w"); // 파일 이름, 모드(r(읽기), w(쓰기), a(추가))
	if (fp == NULL) {
		fprintf(stderr, "파일 alphabet.txt를 열 수 없습니다\n");
		exit(1);
	}

	char c;
	for (c = 'a'; c <= 'z'; c++)
		fputc(c, fp);
	fclose(fp);
	return 0;
}