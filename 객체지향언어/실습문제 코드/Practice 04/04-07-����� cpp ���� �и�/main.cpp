#include <iostream>
#include <string>
using namespace std;

#include "IdGenerator.h"

int main() {
	IdGenerator gen;
	while (true) {
		cout << "사용자 ID 생성(yes/no)>>";
		string res;
		cin >> res;
		if (res != "yes")
			break; // "yes"가 입력되면 프로그램 종료
		cout << gen.next() << endl; // 사용자 ID 생성
	}
}