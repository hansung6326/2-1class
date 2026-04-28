#include <stdio.h>
#include <malloc.h>

int main() {
	char** p;
	p = (char**)malloc(sizeof(char*) * 2);
	for (int i = 0; i < 2; i++) {
		*(p + i) = (char*)malloc(sizeof(char) * 3);
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			*(*(p + i) + j) = i * 3 + j;
			printf("%d \t", *(*(p + i) + j));
		}
		printf("\n");
	}

	for (int i = 0; i < 2; i++)
		free(*(p + i));
	free(p);

}