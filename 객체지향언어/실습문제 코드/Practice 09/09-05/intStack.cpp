#include <iostream>
using namespace std;

class AbstractStack {
public:
	virtual bool push(int n) = 0; // ���ÿ� n�� Ǫ���Ѵ�. ������ full�̸� false ����
	virtual bool pop(int& n) = 0; // ���ÿ��� ���� ������ n�� �����Ѵ�. ������ empty�̸� false ����
	virtual int size() = 0; // ���� ���ÿ� ����� ������ ���� ����
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
	int size() { return tos; } // tos�� ���� ���ÿ� ���Ե� ������ ������ ����
};

IntStack::IntStack(int size) {
	p = new int[size];
	this->capacity = size;
	tos = 0;
}

IntStack::~IntStack() {
	if (p)
		delete[] p;
}

bool IntStack::push(int n) {
	if (tos >= capacity) // full
		return false;

	p[tos] = n;
	tos++;
	return true;
}

bool IntStack::pop(int& n) {
	if (tos == 0) // empty
		return false;

	tos--;
	n = p[tos];
	return true;
}

int main() {
	IntStack a(5);
	for (int i = 0; i < 10; i++) { // ó�� 5 ���� ���������� push�ǰ� ���� 5 ���� ���� full�� push ����
		if (a.push(i)) cout << "push ����" << endl;
		else cout << "���� full" << endl;
	}

	int n;
	for (int i = 0; i < 10; i++) { // ó�� 5 ���� ���������� pop�ǰ� ���� 5 ���� ���� empty�� pop ����
		if (a.pop(n)) cout << "pop ���� " << n << endl;
		else cout << "���� empty" << endl;
	}
}