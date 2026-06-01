#include <stdio.h>

void outputData(int score1[], int score2[], float average[], int count, const char *filename)
{
	FILE* fp = fopen(filename, "w");
	if(fp == NULL){
		perror("파일 열기 실패");
		return;
	}

	for(int i = 0; i < count; i++){
		printf("%d %d %.1f\n", score1[i], score2[i], average[i]);
		fprintf(fp, "%d %d %.1f\n", score1[i], score2[i], average[i]);
	}
	fclose(fp);
}
