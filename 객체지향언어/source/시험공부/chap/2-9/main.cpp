#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {
	char text[100];
	while (1) {
		cout << "끝내려면 OK를 입력하세요>> ";
		cin.getline(text, 100);
		if (!strcmp(text, "OK"))
			break;
	}
	cout << "종료합니다." << endl;
}