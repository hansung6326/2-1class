#include <stdio.h>
#define ROWS 3
#define COLS 5

void matrix_transpose(int A[ROWS][COLS], int B[COLS][ROWS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			B[j][i] = A[i][j];
		}
	}
}
void matrix_print(int A[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("%d", A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void matrix_print_T(int B[COLS][ROWS]) {
	for (int i = 0; i < COLS; i++) {
		for (int j = 0; j < ROWS; j++) {
			printf("%d", B[i][j]);
		}
		printf("\n");
	}
}

int main(void) {
	int array1[ROWS][COLS] = { { 2,3,0,1,2 }, { 8,9,1,3,4 }, { 7,0,5,6,7 } };
	int array2[COLS][ROWS];
	matrix_print(array1);
	matrix_transpose(array1, array2);
	matrix_print_T(array2);

	return 0;
}