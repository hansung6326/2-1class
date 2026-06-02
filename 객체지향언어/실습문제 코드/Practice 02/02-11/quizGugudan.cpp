#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
	cout << "*** 구구단 맞추기 귀즈입니다. ***" << endl;
	int seed = (unsigned)time(0);
	srand(seed); // 램덤 수 발생기 초기화
	int missCount = 0;
	while (true) {
		int n = rand()%9 + 1; // [1,9] 사이의 랜덤한 정수 발생
		int m = rand()%9 + 1; // [1,9] 사이의 랜덤한 정수 발생
		cout << n << "x" << m << "=";
		int input;
		cin >> input;
		if (n * m == input) // 정답!
			cout << "정답입니다. 잘했습니다." << endl;
		else {
			missCount++; // 틀린 횟수 증가
			if (missCount == 3) {
				cout << missCount << "번 틀렸습니다. 퀴즈 종료합니다." << endl;
				break; // 루프 탈출. 프로그램 종료
			}
			else
				cout << missCount << "번 틀렸습니다. 분발하세요." << endl;
		}
	}
}