#include <iostream>
using namespace std;

void printMatrix(int x = 2, int y = 2, char c = '*') {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << c;
		}
		cout << endl;
	}
}

int main() {
	printMatrix();
	printMatrix(2, 5, 'a');
	printMatrix(1, 10);
}