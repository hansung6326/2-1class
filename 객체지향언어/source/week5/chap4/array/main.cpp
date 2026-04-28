#include <iostream>
using namespace std;
#include "array.h"

int main() {
	int n[10];
	n[0] = 5;

	Circle circleArray[3] = { Circle(10), Circle(20), Circle() };

	/* Circle circleArray[3]; //배열의 이름은 circleArray, Circle 객체 3개
	circleArray[0].setRadius(10);
	circleArray[1].setRadius(20);
	circleArray[2].setRadius(30); */
	
	for (int i = 0; i < 3; i++)
		cout << circleArray[i].getArea() << endl;
	Circle* p;
	p = circleArray;

	for (int i = 0; i < 3; i++) {
		cout << p->getArea() << endl;
		p++;
	}

}//메인 함수가 끝날 때 소멸자 호출