#include <iostream>
using namespace std;

void show(string x) {
	cout << x << endl;
}

void print() {
	cout << "hello2" << endl;
}

int main() {
	void (*f)(string); // 선언문

	f = show;
	f("hello"); // 실행문
	//f = print;
	//f();
}