#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE* fp = NULL;
	int c;

	fp = fopen("C:\\2026_class\\프로그래밍랩\\실습\\week7\\chap\\fopen\\alphabet.txt", "r");
	if (fp == NULL) {
		fprintf(stderr, "파일 alphabet.txt를 열 수 없습니다\n");
		exit(1);
	}

	while ((c = fgetc(fp)) != EOF) //End Of File 파일의 끝까지 읽음(\0)
		putchar(c);

	fclose(fp);
	return 0;
}