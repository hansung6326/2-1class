#include <iostream>
#include "헤더.h"
using namespace std;

int main() {
	Circle donut;
	Circle pizza(30);

	cout << donut.getArea() << endl;

	Circle* p; //p라는 변수 선언, p변수에 저장되는 값은 Circle 객체의 주소
	p = &donut;
	cout << p->getArea() << endl;
	cout << (*p).getArea() << endl;

	p = &pizza;
	cout << p->getArea() << endl;
	cout << (*p).getArea() << endl;

}