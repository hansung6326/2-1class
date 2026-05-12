#include <iostream>
using namespace std;

class Shape { // 추상 클래스
	Shape* next;
protected:
	virtual void draw() = 0; // 순수 가상 함수 선언, 오버라이딩 할 것을 기본 클래스에서 명시
public:
	Shape(){next = NULL; }
	void paint() {
		draw();
	}
	Shape* add(Shape* p) {
		next = p;
		return p;
	}
	Shape* getNext() {
		return next;
	}
	//virtual void draw() { cout << "shape" << endl; } //동적바인딩 virtual 없으면 shape 출력됨
};

class Line : public Shape {
protected:
	virtual void draw() { cout << "Line" << endl; }
};
class Rect : public Shape {
protected:
	virtual void draw() { cout << "Rect" << endl; }
};
class Circle : public Shape {
protected:
	virtual void draw() { cout << "Circle" << endl; }
};

//void paint(Shape* p) { //line을 넘기면서 shape으로 업캐스팅
//	p->draw();
//}

void drawAll(Shape* p) {
	while (p != NULL) {
		p->paint();
		p = p->getNext();
	}
}

int main() {
	/*Line line;
	paint(&line);
	Circle circle;
	paint(&circle);*/

	Shape* pStart = NULL;
	Shape* pLast = NULL;

	pStart = new Circle();
	pLast = pStart;

	pLast = pLast->add(new Rect());
	pLast = pLast->add(new Line());
	pLast = pLast->add(new Circle());

	drawAll(pStart);

}