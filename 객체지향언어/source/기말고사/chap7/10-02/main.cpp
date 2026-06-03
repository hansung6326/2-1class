#include <iostream>
using namespace std;

template <class T>
void print(T a, T b) {
	for (T i = a; i <= b; i++) {
		cout << i << ' ';
	}
	cout << endl;
}

int main() {
	print(500, 507);
	print(3.5, 6.5);
	print('b', 'y');
}