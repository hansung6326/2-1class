#include <iostream>
using namespace std;

class Circle {
private:
	int radius;
public:
	Circle() {
		radius = 1;
	}
	Circle(int radius) {
		this->radius = radius;
	}
	int getRadius() {
		return radius;
	}
	double getArea() {
		return 3.14 * radius * radius;
	}
	Circle(const Circle& c);


};
Circle::Circle(const Circle& c) {
	this->radius = c.radius + 1;
	cout << "복사 생성자 호출" << endl;
}
//Circle::Circle(const Circle& c) { // 디폴트 복사 생성자
//	this->radius = c.radius;
//} 

int main() {
	Circle a;
	Circle src(30);
	Circle dest(src); // 복사 생성

	cout << src.getRadius() << endl;
	cout << dest.getRadius() << endl;
}