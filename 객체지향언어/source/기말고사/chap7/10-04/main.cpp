#include <iostream>
using namespace std;

template <class T>
bool add(T a[], int size, int addindex, T b) {
	if (addindex < 0 || addindex >= size)
		return false;
	a[addindex] = b;
	return true;
}

template <class T>
void print(T a[], int size) {
	for (int i = 0; i < size; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
}

int main() {
	int intArray[10] = { 1, 2, 3, 4, 5 };
	bool ret = add(intArray, 10, 5, 20);
	if (ret == true)
		print(intArray, 6);
	else
		cout << "삽입 실패" << endl;

	char charArray[6] = { 'C', '+', '+' };
	ret = add(charArray, 6, 3, '!');

	if (ret == true)
		print(charArray, 4);
	else
		cout << "삽입 실패" << endl;
}