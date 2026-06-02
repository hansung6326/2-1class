#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "정수를 입력하세요>>";
	cin >> n;

	int m = n % 100; // 100으로 나눈 나머지 구하기
	m = m / 10; // 10으로 나눈 몫 구하기
	cout << n << "의 10자리 수는 " << m << "입니다." << endl;
}
