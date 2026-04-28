#include <iostream>
#include <string>

using namespace std;

int main() {
	char user[100]; //사용자로부터 입력받은 문자열 암호를 저장하는 배열
	//string user;

	//루프를 돌면서 문자열을 입력받고, 암호와 비교하여 같으면 종료, 아니면 계속 루프
	while (true) {
		cout << "암호를 입력하세요 ";
		cin.getline(user, 100, '\n');
		if (strcmp(user, "C++ GOOD")) {
			cout << "통과";
			break;
		}
		else
			cout << "틀렸습니다, 다시 입력하세요" << endl;
	}

	return 0;
}