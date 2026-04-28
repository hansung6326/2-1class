#include <iostream>
#include <string>
using namespace std;

void star(int n = 10) { // 매개변수가 입력되지 않으면 10으로 설정
	for (int i = 0; i < n; i++)
		cout << '*';
	cout << endl;
}

void msg(int id=5, string text = "Hello") {
	cout << id << ',' << text << endl;
}

int main() {
	star(); //컴파일러에 의해 star(10)으로 출력됨
	star(20);

	msg();
	msg(10);
	msg(20, "Good Morning");
}