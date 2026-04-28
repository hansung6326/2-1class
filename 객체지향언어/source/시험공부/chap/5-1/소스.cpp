#include <iostream>
using namespace std;

int twice(int& n) {
	return n *= 2;
}

int main() {
	int n = 12;
	twice(n);
	cout << n;
}