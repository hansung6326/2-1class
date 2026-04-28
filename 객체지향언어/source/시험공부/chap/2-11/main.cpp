#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	srand((unsigned)time(0));
	int count = 0;

	cout << "*** 구구단 맞추기 퀴즈입니다. ***" << endl;
	while (count < 3) {
		int a = rand() % 10;
		int b = rand() % 10;
		int c;
		cout << a << "x" << b << "=";
		cin >> c;
		if ((a * b) == c) {
			cout << "정답입니다." << endl;
		}
		else {
			count++;
			cout << count << "번 틀렸습니다." << endl;
		}


	}
}