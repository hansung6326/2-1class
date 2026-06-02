#include <iostream>
using namespace std;

int main() {
	int ch;
	cout << "입력하세요>>";
	while ((ch = cin.get()) != EOF) { // 키보드에서 문자 읽기
		if (ch == ';') // 읽은 문자가 ';' 이면 읽기 종료
			break;
		else
			cout.put(ch); // 읽은 문자 출력
	}
}