#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int buffer[] = { 10, 20, 30, 40, 50 };
	FILE* fp = NULL;
	size_t i, size, count;

	fp = fopen("binary.bin", "wb");
	if (fp == NULL) {
		fprintf(stderr, "파일 binary.bin을 열 수 없습니다\n");
		exit(1);
	}

	size = sizeof(buffer[0]);
	count = sizeof(buffer) / sizeof(buffer[0]);

	i = fwrite(buffer, size, count, fp);

	if (i != count)
		printf("쓰기 실패\n");

	fclose(fp);
	return 0;
}