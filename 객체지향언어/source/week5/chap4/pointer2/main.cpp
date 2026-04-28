#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; cout << "생성자 실행 " << radius << endl; }
	Circle(int r) { radius = r; cout << "생성자 실행 " << radius << endl;}
	~Circle() { cout << "소멸자 호출 " << radius << endl; }
	void setRadius(int r) { radius = r; }
	double getArea();
};

double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	Circle* p = new Circle[3];
	p[0].setRadius(10);
	p[1].setRadius(20);
	p[2].setRadius(30);

	for (int i = 0; i < 3; i++) {
		cout << p[i].getArea() << endl;
	}

	Circle* a = p;

	for (int i = 0; i < 3; i++) {
		cout << a->getArea() << endl;
		a++;
	}

	a = p;
	for (int i = 0; i < 3; i++) {
		cout << (a+i)->getArea() << endl;
	}

	for (int i = 0; i < 3; i++) {
		cout << (*(a + i)).getArea() << endl;
	}

	for (int i = 0; i < 3; i++) {
		cout << a[i].getArea() << endl;
	}

	delete[] p;

	/* Circle* p, * q;
	p = new Circle; //기본 생성자 호출
	q = new Circle(30); //Circle(int r) 생성자 호출

	cout << p->getArea() << endl << q->getArea();

	delete p;
	delete q; //delete 하지 않으면 소멸하지 않음 */

	
}