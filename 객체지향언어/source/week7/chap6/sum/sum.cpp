#include <iostream>
using namespace std;

int sum(int a, int b) {
	int sum = 0;
	for (a; a <= b; a++) {
		sum += a;
	}
	return sum;
}
int sum(int a) {
	int sum = 0;
	for (int i = 1; i <= a; i++) {
		sum += i;
	}
	return sum;
}

int main() {
	cout << sum(3, 5) << endl;
	cout << sum(3) << endl;
	cout << sum(100) << endl;
}