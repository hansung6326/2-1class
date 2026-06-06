#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin("ShowNoComment.cpp");
	if (!fin) {
		cout << "ShowNoComment.cpp 파일 열기 오류";
		return 0;
	}
	int ch;
	bool found = false;
	while ((ch = fin.get()) != EOF) {
		if (ch == '/') {
			if (found == false)
				found = true; // 슬래시 한 개 발견. 주석 시작 가능성
			else { // 연속된 두 개의 슬래시 // 발견
				fin.ignore(100, '\n'); // '\n'이 나올 때까지 최대 100개의 문자 건너뛰기
				cout.put('\n');
				found = false; // 주석 처리 완료
			}
		}
		else {
			if (found == true) { // 슬래시가 한 개만 나오고 다른 문자가 나오는 경우
				cout << "/"; // '/'가 발견된 뒤 연속된 '/'가 아니었으므로 생략했던 '/' 출력
				found = false; // 주석 처리 클리어
			}
			cout.put(ch);
		}
	}

	fin.close();
}