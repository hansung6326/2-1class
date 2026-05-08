#include <iostream>
#include <string>
using namespace std;

class Point {
protected:
	int x, y;
public:
	void set(int x, int y) { this->x = x; this->y = y; }
	void showPoint() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};

class ColorPoint : public Point {
	string color;
public:
	void setColor(string color) { this->color = color; }
	void showColorPoint();
};

void ColorPoint::showColorPoint() {
	cout << color << ":" << x << " " << y << endl;
	//showPoint();
}

int main() {
	Point p;
	ColorPoint cp;
	cp.set(3, 4);
	cp.setColor("Red");
	cp.showColorPoint();

	ColorPoint* a = &cp;
	Point* b = a; //업캐스팅이 일어나고 있다. Point* b = (Point*)&cp;

	ColorPoint* q = (ColorPoint*)b; //다운 캐스팅
	q->showColorPoint();
}