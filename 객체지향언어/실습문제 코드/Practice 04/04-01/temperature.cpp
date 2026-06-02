#include <iostream>
using namespace std;

#define SIZE 5
// constexpr auto SIZE = 5; // #define 대신 이 문장을 사용할 것을 권함

int main() {
	double* p = new double[SIZE]; // 5개의 실수 배열 동적 할당
		
	// 5개의 온도 입력
	cout << "온도 " << SIZE << "개 입력>>";
	for (int i = 0; i < SIZE; i++)
		cin >> p[i];

	// 배열의 합 구하기
	double sum = 0;
	for (int i = 0; i < SIZE; i++)
		sum += p[i];

	cout << "평균은 " << sum / SIZE << endl;

	delete[] p; // 동적 배열 반환
}