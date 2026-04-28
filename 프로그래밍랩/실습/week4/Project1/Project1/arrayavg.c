#include <stdio.h>
#define SIZE 5

// 배열 요소들의 평균을 구하는 함수
double getArrayAvg(int values[], int n) {
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += values[i];
	}
	return (sum / n);
}

// 배열의 내용을 출력하는 함수
void printArray(int values[], int n) {
	printf("[ ");
	for (int i = 0; i < n; i++) {
		printf("%d ", values[i]);
	}
	printf("]\n");
}

int main(void) {
	int data[SIZE] = { 10, 20, 30, 40, 50 };
	double result;

	result = getArrayAvg(data, SIZE);
	printArray(data, SIZE);

	// 깨진 부분: "배열 원소들의 평균 = %f\n"
	printf("배열 원소들의 평균 = %f\n", result);

	return 0;
}