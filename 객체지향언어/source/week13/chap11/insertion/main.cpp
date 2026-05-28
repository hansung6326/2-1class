#include <iostream>
#include <string>
using namespace std;

class Point {
	int x, y;
public:
	Point(int x = 0, int y = 0) {
		this->x = x; this->y = y;
	}
	friend ostream& operator <<(ostream& out, Point p);
	friend istream& operator >>(istream& in, Point& p);
};

ostream& operator <<(ostream& out, Point p) {
	out << "(" << p.x << "," << p.y << ")" << endl;
	return out;
}
istream& operator >>(istream& in, Point& p) { // 반드시 Point& 해야함 안그러면 복사본에 저장되기에
	cout << "x=";
	in >> p.x;
	cout << "y=";
	in >> p.y;
	return in;
}

int main() {
	Point a, b(3, 5);
	string x = "hello";

	cout << x << endl; // <<(cout, x)
	cin >> a >> b;
	cout << a << b; // cout.<<(a), <<(cout, a)
}