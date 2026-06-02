#include <iostream>
using namespace std;

#include "Oval.h"

int main() {
	Oval kitae, jane(10, 15);
	kitae.set(3, 4); // kitae 타원 너비와 높이를 3x4로 변경
	kitae.show(); // kitae 타원의 모양 출력
	cout << jane.getWidth() << "x" << jane.getHeight() << ", 면적 " << jane.area() << endl;
}