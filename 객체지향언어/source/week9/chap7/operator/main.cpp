#include <iostream>
using namespace std;

class Power {
	int punch;
	int kick;
public:
	Power(int punch = 0, int kick = 0) {
		this->punch = punch;
		this->kick = kick;
	}

	/*Power operator+(Power b);*/
	Power operator+(int b);
	bool operator == (Power b);
	Power& operator +=(Power b);
	bool operator !();
	Power& operator ++(); // 전위 연산자는 매개변수 없음
	Power operator ++(int n); // 후위 연산자
	friend Power operator +(int n, Power a);
	friend Power operator +(Power a, Power b);
	Power& operator <<(int n);
	Power& operator <<(Power b);

	void show();
};
//Power Power::operator+(Power b) {
//	Power tmp;
//	tmp.punch = punch + b.punch;
//	tmp.kick = kick + b.kick;
//	return tmp;
//}
Power Power::operator+(int b) {
	Power tmp;
	tmp.punch = punch + b;
	tmp.kick = kick + b;
	return tmp;
}
bool Power::operator==(Power b) {
	if (punch == b.punch && kick == b.kick)
		return true;
	else
		return false;
}
Power& Power::operator+=(Power b) {
	punch += b.punch;
	kick += b.kick;
	return *this;
}
bool Power::operator!() {
	if (punch == 0 && kick == 0)
		return true;
	else
		return false;
}
Power& Power::operator++() { // 전위 연산자
	punch++;
	kick++;
	return *this;
}
Power Power::operator++(int n) { // 후위 연산자
	Power tmp = *this;
	punch++;
	kick++;
	return tmp;
}

void Power::show() {
	cout << "(" << punch << ", " << kick << ")" << endl;
}

Power operator +(int n, Power a) {
	Power tmp;
	tmp.punch = n + a.punch;
	tmp.kick = n + a.kick;

	return tmp;
}
Power operator +(Power a, Power b) {
	Power tmp;
	tmp.punch = a.punch + b.punch;
	tmp.kick = a.kick + b.kick;
	return tmp;
}
Power& Power::operator <<(int n) {
	punch += n;
	kick += n;
	return *this;
}
Power& Power::operator <<(Power b) {
	punch += b.punch;
	kick += b.kick;
	return *this;
}

int main() {
	int n = 2 + 3;
	Power a(2, 3), b(20, 30), c;
	c = a + b; // a.+(b) +를 함수 이름으로 봄
	cout << n << endl;
	a.show();
	b.show();
	c.show();

	if (a == b)
		cout << "equals" << endl;
	else
		cout << "not equals" << endl;

	(a += b) += c;
	c = a + 2;
	a.show();
	b.show();
	c.show();

	if (!Power(0,0)) // a.!()
		cout << "Power 없음" << endl;
	else
		a.show();
	b = ++a; // a.++()
	++c = b;
	a.show();
	b.show();

	++++a;
	a.show();

	b = a++; // a.++(0);
	b.show();
	a.show();

	c = 2 + a; // 2.+(a) 이렇게했는데 2는 객체가 아니니까 컴파일러가 이렇게 실행해봄  +(2,a)
	a.show();
	c.show();

	a << 3 << c << 5; // a.<<(3), <<(a,3)
	a.show();
}