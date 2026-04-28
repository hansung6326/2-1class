#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 5

int main(void) {
	int buffer[SIZE];
	FILE* fp = NULL;
	int i;

	fp = fopen("C:\\2026_class\\프로그래밍랩\\실습\\week7\\chap\\fopenb\\binary.bin", "rb");
	if (fp == NULL) {
		fprintf(stderr, "파일 binary.bin를 열 수 없습니다\n");
		return 1;
	}

	fread(buffer, sizeof(int), SIZE, fp);
	for (i = 0; i < SIZE; i++)
		printf("%d ", buffer[i]);
	fclose(fp);

	return 0;
}