#include <iostream>
using namespace std;

class MyStack {
	int* p;
	int size = 0;
	int tos = 0;
public:
	MyStack();
	MyStack(int size);
	MyStack(const MyStack& src);
	~MyStack();
	bool push(int n);
	bool pop(int& n);
};

MyStack::MyStack() {
	size = 10;
	tos = 0;
	p = new int[size];
}
MyStack::MyStack(int size) {
	this->size = size;
	tos = 0;
	p = new int[size];
}
MyStack::MyStack(const MyStack& src) {
	this->size = src.size;
	this->tos = src.tos;
	this->p = new int[size];

	for (int i = 0; i < tos; i++) {
		this->p[i] = src.p[i];
	}
}
MyStack::~MyStack() {
	delete[] p;
}
bool MyStack::push(int n) {
	if (tos >= size)
		return false;
	p[tos++] = n;
	return true;
}
bool MyStack::pop(int& n) {
	if (tos <= 0)
		return false;
	n = p[--tos];
	return true;
}


int main() {
	MyStack a(10);
	a.push(10);
	a.push(20);

	MyStack b = a;
	b.push(30);
	int n;
	a.pop(n);
	cout << "스택 a에서 팝한 값 " << n << endl;
	b.pop(n);
	cout << "스택 b에서 팝한 값 " << n << endl;

}