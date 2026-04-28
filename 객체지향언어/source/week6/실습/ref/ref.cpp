#include <iostream>
using namespace std;

int main() {
	int n = 5;
	int* p = &n;
	int& ref = n; // int& ref; 오류 무엇에 대한 참조 변수인지 선언해줘야함
	ref++; // n++;
	n = 20;
	p = &ref;
	ref++;

	cout << n << ',' << ref << ',' << *p << endl;
}