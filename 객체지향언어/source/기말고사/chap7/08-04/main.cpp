#include <iostream>
using namespace std;

class Point {
	int x, y;
public:
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
protected:
	void move(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

class Point3D : public Point {
	int z;
public:
	Point3D(int x, int y, int z) : Point(x, y) {
		this->z = z;
	}
	void show() {
		cout << "(" << getX() << "," << getY() << "," << z << ")" << endl;
	}
	void upZ() {
		z++;
	}
	void left() {
		move(getX() - 1, getY());
	}
	void up() {
		move(getX(), getY() + 1);
	}
	void set(int x, int y, int z) {
		move(x, y);
		this->z = z;
	}
};

int main() {
	Point3D p(1, 2, 3);
	p.show();
	p.upZ();
	p.left();
	p.up();
	p.show();
	p.set(10, 20, 30);
	p.show();
}