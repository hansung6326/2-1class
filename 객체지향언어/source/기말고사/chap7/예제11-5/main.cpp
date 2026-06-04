#include <iostream>
using namespace std;

int main() {
	int n = 30;

	cout << n << endl;

	cout.unsetf(ios::dec);
	cout.setf(ios::hex);
	cout << n << endl;

	cout.setf(ios::showbase);
	cout << n << endl;

	cout.setf(ios::uppercase);
	cout << n << endl;

	cout.setf(ios::dec | ios::showpoint);
	cout << 23.5 << endl;

	cout.setf(ios::scientific);
	cout << 23.5 << endl;

	cout.setf(ios::showpos);
	cout << 23.5 << endl;
}