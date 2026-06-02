#include <iostream>
using namespace std;

void twice(int &n) {
	n *= 2;
}

int main() {
	int n = 12;
	twice(n); // n을 2배로 증가시킴
	cout << n; // 24 출력
}