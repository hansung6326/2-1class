#include <iostream>
using namespace std;

bool average(int a[], int size, int& avg) {
	if (size <= 0)
		return false;
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += a[i];
	}
	avg = sum / size;
	return true;
}

int main() {
	int x[] = {-2, -1, -1 };
	int avg;
	bool res = average(x, 3, avg);
	if (res == false) {
		cout << "error!" << endl;
	}
	else {
		cout << avg << endl;
	}
	
}