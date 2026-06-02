#include <iostream>
using namespace std;

template <class T>
bool equals(T a[], T b[], int size) {
	for (int i = 0; i < size; i++) {
		if (a[i] != b[i])
			return false;
	}

	return true;
}

int main() {
	int x[] = { 3, 5, 9, 7 };
	int y[] = { 3, 5, 7, 9 };
	if (equals(x, y, 4)) cout << "같다." << endl; // 배열 x와 y의 4개의 값이 같다.
	else cout << "다르다" << endl;

	char c[] = { 'j', 'a', 'v', 'a' };
	char d[] = { 'j', 'a', 'v', 'A'};
	if (equals(c, d, 3)) cout << "같다." << endl; // 배열 c와 d의 3개의 값이 같다.
	else cout << "다르다" << endl;
}