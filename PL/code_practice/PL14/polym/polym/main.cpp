#include <iostream>
using namespace std;

template<class T>
void swap_function(T& x, T& y) {
	T t;
	t = x;
	x = y;
	y = t;
}

int main() {
	int a, b;
	double c, d;
	char x, y;

	a = 10;
	b = 20;

	cout << "a= " << a << ", b= " << b << endl;
	swap_function(a, b);
	cout << "a= " << a << ", b= " << b << endl;

	c = 10.5;
	d = 20.4;

	cout << "c= " << c << ", d= " << d << endl;
	swap_function(c, d);
	cout << "c= " << c << ", d= " << d << endl;

	x = 'X';
	y = 'Y';

	cout << "x= " << x << ", y= " << y << endl;
	swap_function(x, y);
	cout << "x= " << x << ", y= " << y << endl;

}