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
	int x[] = { 1, 2, 3, 4 };
	int avgg;
	bool success = average(x, 4, avgg);
	if (success == false)
		cout << "오류" << endl;
	else
		cout << "평균 = " << avgg << endl;

}