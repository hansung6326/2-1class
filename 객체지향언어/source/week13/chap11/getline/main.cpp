#include <iostream>
#include <cstring>
using namespace std;

int main() {
	while (true) {
		cout << "암호를 입력하세요 >>";
		char pw[80];
		cin.getline(pw, 80); // 79개 까지 입력 가능 제일 마지막은 \n
		if (strcmp(pw, "Good Morning") == 0) {
			cout << "통과" << endl;
			break;
		}
			
	}
	

}