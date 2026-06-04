#include <iostream>
using namespace std;

class Point {
	int x, y;
public:
	Point(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;
	}
	friend istream& operator >>(istream& stream, Point& p);
	friend ostream& operator <<(ostream& stream, Point p);
};

istream& operator >>(istream& stream, Point& p) {
	cout << "x 좌표>>";
	stream >> p.x;
	cout << "y 좌표>>";
	stream >> p.y;
	return stream;
}

ostream& operator <<(ostream& stream, Point p) {
	stream << "(" << p.x << "," << p.y << ")" << endl;
	return stream;
}

int main() {
	Point p;
	cin >> p;
	cout << p;
	return 0;
}