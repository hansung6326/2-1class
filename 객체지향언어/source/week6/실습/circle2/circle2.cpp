#include <iostream>
using namespace std;

class Circle {
private:
	int radius;
public:
	Circle(const Circle& src);
	Circle() { radius = 1; }
	Circle(int radius) {
		this->radius = radius;
	}
	double getArea() { return 3.14 * radius * radius; }
};
Circle::Circle(const Circle& src) {
	this->radius = src.radius;
	cout << "복사 생성자 실행" << endl;
}

int main() {
	Circle src(30); // src 객체의  보통 생성자 호출
	Circle dest(src); // Circle dest = src, dest 객체의 복사 생성자 호출
	//dest = src 복사생성자 호출안됨

	cout << "원본의 면적 = " << src.getArea() << endl;
	cout << "사본의 면적 = " << dest.getArea() << endl;
}
