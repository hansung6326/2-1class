#include <iostream>
using namespace std;

void f() {
	cout << "입력하세요>>";
	int ch; // char로 안하고 관례적으로 int로 함
	int n = 1;

	cout << "1: ";
	while ((ch = cin.get()) != EOF) { // ctrl + z == EOF
		cout.put(ch);

		if (ch == '\n') {
			n++;
			cout << n << ": ";
		}
	}
}

void f2() {
	cout << "입력하세요>>";
	char ch;
	while (true) {
		cin.get(ch); // call by reference
		if (cin.eof())
			break;
		cout.put(ch);
		if (ch == '\n')
			break;
	}
}

int main() {
	f2();
}