#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE* fp1, * fp2;
	char file1[100], file2[100];
	int c;

	printf("원본 파일 이름: ");
	scanf("%s", &file1);
	printf("복사 파일 이름: ");
	scanf("%s", &file2);

	if ((fp1 = fopen(file1, "r")) == NULL) {
		printf("%s 파일을 읽지 못했습니다.\n", file1);
		exit(1);
	}
	if ((fp2 = fopen(file2, "w")) == NULL) {
		printf("%s 파일을 작성하지 못했습니다.\n", file2);
		exit(1);
	}
	
	while ((c = fgetc(fp1)) != EOF) {
		fputc(c, fp2);
	}

	fclose(fp1);
	fclose(fp2);

	return 0;
}