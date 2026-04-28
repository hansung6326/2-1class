#include <iostream>
using namespace std;

int main() {
	for (int i = 0; i <= 4; i++) {
		for (int j = 1; j <= 10; j++) {
			cout << i * 10 + j << "\t";
		}
		cout << endl;
	}
	for (int i = 51; i <= 55; i++)
		cout << i << "\t";
	cout << endl;
}