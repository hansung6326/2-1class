#include <iostream>
using namespace std;

int main() {
	int n = 2;
	int& ref = n; // 변수 n에 대한 참조 변수 ref선언
	n++; //3
	ref++; //4
	ref = 10;

	cout << ref << ' ' << n << endl;
	
	int m = 6;
	ref = m; // n = m;
	cout << ref << ' ' << n << endl;

	int* p = &ref; //&n
	*p = 20;
	cout << ref << ' ' << n << endl;
}