#include <iostream>
using namespace std;

template<class T>
T bigger(T a, T b) {
	if (a > b)
		return a;
	return b;
}

int main() {
	int a = 20, b = 50;
	char c = 'a', d = 'z';
	cout << bigger(a, b) << endl;
	cout << bigger(c, d) << endl;
}