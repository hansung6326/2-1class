#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE* fp = NULL;
	char str[100];

	fp = fopen("file.txt", "w");
	if (fp == NULL) {
		fprintf(stderr, "파일 file.txt를 열 수 없습니다\n");
		exit(1);
	}

	do {
		gets_s(str, sizeof(str));
		fputs(str, fp);
	} while (strlen(str) != 0);
	fclose(fp);
	return 0;
}