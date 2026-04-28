#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle();
	Circle(int radius);
	~Circle();
	double getArea();
	int getRadius();
	void setRadius(int radius);
};

Circle::~Circle() {
	cout << "소멸자 실행 " << radius << endl;
}
Circle::Circle() {
	radius = 1;
	cout << "생성자 실행 " << radius << endl;
}
Circle::Circle(int radius) {
	this->radius = radius;
	cout << "생성자 실행 " << radius << endl;
}
double Circle::getArea() {
	return 3.14 * radius * radius;
}
int Circle::getRadius() {
	return radius;
}
void Circle::setRadius(int radius) {
	this->radius = radius;
}

//void increase(Circle c) { 
//	int r = c.getRadius();
//	r++;
//	c.setRadius(r);
//}

void increase(Circle* c) { 
	int r = c->getRadius();
	r++;
	c->setRadius(r);
}

int main() {
	Circle circle;
	Circle& ref = circle; //ref라는 객체가 생긴것이 아니라 circle객체를 부르는 다른 이름 ref가 생긴 것
	ref.setRadius(10);
	cout << ref.getRadius() << ' ' << circle.getRadius() << endl;



//	Circle waffle(30);
//
////	increase(waffle); //값에 의한 호출
//	increase(&waffle); //주소에 의한 호출
//	cout << waffle.getRadius() << endl;

	return 0;
}
