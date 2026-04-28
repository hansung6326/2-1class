#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE* fp1, * fp2;
	char file1[100], file2[100];
	char buffer[100];

	printf("원본 파일 이름: ");
	scanf("%s", file1);

	printf("복사 파일 이름: ");
	scanf("%s", file2);

	if ((fp1 = fopen(file1, "r")) == NULL) {
		fprintf(stderr, "파일 %s를 열 수 없습니다\n", file1);
		exit(1);
	}
	if ((fp2 = fopen(file2, "w")) == NULL) {
		fprintf(stderr, "복사 파일 %s를 열 수 없습니다\n", file2);
		exit(1);
	}

	int c;
	while ((c = fgetc(fp1)) != EOF)
		fputc(c, fp2);

	fclose(fp1);
	fclose(fp2);
	return 0;
}