#include <iostream>
using namespace std;

int add(int arr[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += arr[i];
	return sum;
}

int add(int arr[], int size, int c) {
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += arr[i];
	sum += c;
	return sum;
}

int main() {
	int a[] = { 1,2,3,4,5 };
	int b[] = { 6,7,8,9,10 };
	int c = add(a, 5); // 배열 a의 정수를 모두 더한 값 리턴
	int d = add(b, 3, c); // 배열 b의 처음 3개와 c를 더한 값 리턴
	cout << c << endl; // 1~5까지 합 = 15 출력
	cout << d << endl; // 6~8까지 합 + 15 = 36 출력
}