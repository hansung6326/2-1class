#include <iostream>
using namespace std;

void swap(int& a, int& b) {
	int tmp;
	tmp = a;
	a = b; 
	b = tmp;
	cout << a << ' ' << b << endl;
}

int main() {
	int a = 2, b = 9;
	swap(a, b);
	cout << a << ' ' << b << endl;

	return 0;
}