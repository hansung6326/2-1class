#include <iostream>
using namespace std;

int main() {
	cout << "입력하세요>>";
	int c;
	while ((c = cin.get()) != EOF) {
		if (c == ';')
			break;
		cout.put(c);
	}
}