#include <iostream>
using namespace std;

void f(char c = ' ', int size = 1) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 10; j++) {
			cout << c;
		}
		cout << endl;
	}
}

int main() {
	f();
	f('%');
	f('@', 5);

	return 0;
}