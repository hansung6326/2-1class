#include <iostream>
using namespace std;

class MyStack {
	int p[10];
	int tos = 0;
public:
	MyStack();
	bool push(int n);
	bool pop(int& n);
};
MyStack::MyStack() {
	tos = 0;
}
bool MyStack::push(int n) {
	if (tos >= 10)
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
	MyStack st;
	for (int i = 0; i < 11; i++) {
		if (st.push(i))
			cout << i << ' ';
		else
			cout << endl << i + 1 << "번째 푸시 실패! 스택 차 있음" << endl;
	}
	int n;
	for (int i = 0; i < 11; i++) {
		if (st.pop(n))
			cout << n << ' ';
		else
			cout << endl << i + 1 << "번째 팝 실패! 스택이 비어있음" << endl;
	}

}