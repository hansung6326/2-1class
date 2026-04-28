#include <iostream>
using namespace std;

int main() {
	int a;
	int b;
	cout << "정수를 입력하세요>>";
	cin >> a;
	b = (a / 10) % 10;
	cout << a << "의 10자리 수는 " << b << "입니다." << endl;
}