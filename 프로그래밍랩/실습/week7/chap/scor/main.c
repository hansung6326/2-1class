#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE* fp;
	int id;
	char name[100];
	double score;
	char c;

	fp = fopen("score.txt", "w");
	if (fp == NULL) {
		printf("score.txt 파일을 만들지 못했습니다.\n");
		exit(1);
	}

	do {
		printf("학번 : ");
		scanf("%d", &id);
		printf("이름 : ");
		scanf("%s", name);
		printf("성적 : ");
		scanf("%lf", &score);

		fprintf(fp, "%d %s %.1f\n", id, name, score);

		printf("데이터 추가를 계속? (y/n) : ");
		scanf(" %c", &c);
	} while (c == 'y');

	fclose(fp);
	return 0;
}