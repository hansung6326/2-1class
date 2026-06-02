#include <iostream>
using namespace std;

class Matrix {
	int a, b, c, d;
public:
	Matrix(int a = 0, int b = 0, int c = 0, int d = 0) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
	}
	void operator >>(int x[]) {
		x[0] = a;
		x[1] = b;
		x[2] = c;
		x[3] = d;
	}
	void operator <<(int y[]) {
		a = y[0];
		b = y[1];
		c = y[2];
		d = y[3];
	}
	void show() {
		cout << "Matrix = { " << a << " " << b << " " << c << " " << d << " }" << endl;
	}
	
};

int main() {
	Matrix a(4, 3, 2, 1), b;
	int x[4], y[4] = { 1,2,3,4 };
	a >> x;
	b << y;
	for (int i = 0; i < 4; i++)
		cout << x[i] << ' ';
	cout << endl;
	b.show();
}