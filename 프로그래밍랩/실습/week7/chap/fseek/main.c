#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	long length;

	FILE* fp = fopen("C:\\2026_class\\프로그래밍랩\\실습\\week7\\chap\\fopenb\\binary.bin", "rb");

	if (fp == NULL) {
		printf("binary.bin 파일을 열 수 없습니다.");
		exit(1);
	}

	fseek(fp, 0, SEEK_END);
	length = ftell(fp);
	printf("파일 크기 = %d 바이트 \n", length);
	fclose(fp);
	return 0;
}