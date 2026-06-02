#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char buf[100]; // 빈 칸을 포함하는 텍스트를 저장할 배열
	while (true) {
		cout << "끝내려면 OK를 입력하세요>>";
		cin.getline(buf, 100); // 텍스트 입력
		if (strcmp(buf, "OK") == 0) {
			cout << "종료합니다." << endl;
			break;
		}
	}
}