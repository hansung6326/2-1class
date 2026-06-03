#include <iostream>
using namespace std;

template<class T>
T biggest(T a[], int size) {
	T big = a[0];
	for (int i = 1; i < size; i++) {
		if (a[i] > big)
			big = a[i];
	}
	return big;
}

int main() {
	int x[] = { 1, 10, 100, 5, 4 };
	cout << biggest(x, 5) << endl;

	double y[] = { 3.5, 20.7, 6.2, 5.4 };
	cout << biggest(y, 4) << endl;
}