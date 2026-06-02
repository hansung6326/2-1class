#include <iostream>
#include <string>
using namespace std;

int main() {
	string cmd;
	while (true) {
		cout << "종료하려면 암호를 입력하세요>>";
		getline(cin,cmd); // 크기 제한없이 문자 입력
		if (cmd =="see you later") {
			cout << "프로그램을 종료합니다....";
			return 0;
		}
	}
}