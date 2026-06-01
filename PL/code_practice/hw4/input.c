#include <stdio.h>

int readData(int score1[], int score2[], const char* filename)
{
	int count = 0;

	FILE* fp = fopen(filename, "r");
	if(fp == NULL){
		perror("파일 열기 실패");
		return -1;
	}

	while(fscanf(fp, "%d %d", &score1[count], &score2[count]) == 2){
		count++;
	}

	fclose(fp);
	return count;
}

