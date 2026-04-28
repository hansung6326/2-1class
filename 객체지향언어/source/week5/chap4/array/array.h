#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; cout << "생성자 호출" << radius << endl; }
	Circle(int r) { radius = r; cout << "생성자 호출" << radius << endl;}
	~Circle() { cout << "소멸자 호출" << radius << endl; }
	void setRadius(int r) { radius = r; }
	double getArea();
};