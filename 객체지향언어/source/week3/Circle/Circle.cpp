#include <iostream>
using namespace std;

//선언부
class Circle {
	int radius; 
public:
	double getArea();
	int getRadius();
	Circle(); // 생성자는 클래스 이름과 같다 && return을 하지 않는다
	Circle(int r);
	~Circle(); //소멸자는 매개변수를 줄 수 없다 오직 한 개만 있음
};

// 구현부
Circle::~Circle() {
	cout << radius << "의 원이 소멸됨 " << endl;
}

Circle::Circle() { //생성자는 객체 초기화의 역할을 함
	radius = 1;
	cout << "생성자 실행..." << endl;
}
Circle::Circle(int r) {
	radius = r;
	cout << "생성자 실행..." << endl;
}

double Circle::getArea() { //'::'는 범위 지정 연산자이다
	return 3.14 * radius * radius;
}

int Circle::getRadius() {
	return radius;
}

int main() {
	Circle donut; //선언문 //객체가 생성된 시점이므로 Circle()생성자 실행
	//donut.radius = 1; 생성자에서 radius를 초기화 했기에 필요하지 않음 -> public 바깥에 선언 되었기에 private화 되어서 메인 함수에서 접근할 수 없음
	double area = donut.getArea();
	cout << "도넛의 면적은 " << area << "입니다." << endl;
	Circle pizza(30);//객체가 생성된 시점이므로 Circle(int r)생성자 실행
	//pizza.radius = 30;
	cout << "피자의 면적은 " << pizza.getArea() << "입니다." << endl;
	return 0;
}