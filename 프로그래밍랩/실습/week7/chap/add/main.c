#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE* fp;
	fp = fopen("sales.txt", "a");
	fprintf(fp, "2022.3.1 매출: %d \n", 200000);

	fclose(fp);
	return 0;
} 