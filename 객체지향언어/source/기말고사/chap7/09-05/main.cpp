#include <iostream>
using namespace std;

class AbstractStack {
public:
	virtual bool push(int n) = 0;
	virtual bool pop(int& n) = 0;
	virtual int size() = 0;
};

class IntStack : public AbstractStack {
	int capacity;
	int tos;
	int* p;
public:
	IntStack(int size);
	~IntStack();
	bool push(int n);
	bool pop(int& n);
	int size();
};
IntStack::IntStack(int size) {
	p = new int[size];
	this->capacity = size;
	tos = 0;
}
IntStack::~IntStack() {
	delete[] p;
}

bool IntStack::push(int n) {
	if (tos >= capacity)
		return false;
	p[tos++] = n;
	return true;
}
bool IntStack::pop(int& n) {
	if (tos <= 0)
		return false;
	n = p[--tos];
	return true;
}
int IntStack::size() {
	return tos;
}

int main() {
	IntStack a(5);
	for (int i = 0; i < 10; i++) { // 처음 5 번은 성공적으로 push되고 나머지 5 번은 스택이 full로 push 실패
		if (a.push(i)) cout << "push 성공" << endl;
		else cout << "스택 full" << endl;
	}

	int n;
	for (int i = 0; i < 10; i++) { // 처음 5 번은 성공적으로 pop되고 나머지 5 번은 스택이 empty로 pop 실패
		if (a.pop(n)) cout << "pop 성공 " << n << endl;
		else cout << "스택 empty" << endl;
	}
}