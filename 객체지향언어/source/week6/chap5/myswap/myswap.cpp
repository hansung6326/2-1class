#include <iostream>
using namespace std;

void myswap(int* a, int* b) { // 함수 정의, 함수 구현
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;

	return; //void 타입은 생략 가능
}

int main() {
	int m = 2, n = 9;

	myswap(&m, &n); //함수 호출
	cout << m << ' ' << n << endl;
}