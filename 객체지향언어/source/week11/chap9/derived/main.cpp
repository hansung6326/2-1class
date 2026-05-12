#include <iostream>
using namespace std;

class Base {
public:
	virtual void f() { cout << "Base::f() called" << endl; }

};

class Derived : public Base {
public:
	virtual void f() { cout << "Derived::f() called" << endl; } //함수 재정의 
};

int main() {
	Base b;
	b.f();
	Derived d;
	d.f();
	d.Base::f();

	Derived* p;
	p = &d;
	p->f();
	p->Base::f();

	Base* q;
	q = p; // 업캐스팅
	q->f(); //실제 객체는 d(Derived)일지라도, 포인터의 타입이 Base이므로 기본적으로 부모의 f()를 본다

}