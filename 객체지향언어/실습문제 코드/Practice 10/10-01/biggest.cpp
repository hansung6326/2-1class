#include <iostream>
using namespace std;

template <class T>
T biggest(T ar[], int n) {
	T big = ar[0];
	for (int i = 0; i < n; i++) {
		if (big < ar[i])
			big = ar[i];
	}

	return big;
}

int main() {
	int x[] = {1, 10, 100, 5, 4};
	cout << biggest(x, 5) << endl; // 5는 크기. 배열 x에서 가장 큰 값 리턴
	
	double y[] = {3.5, 20.7, 6.2, 5.4};
	cout << biggest(y, 4) << endl; // 4는 크기. 배열 y에서 가장 큰 값 리턴
}