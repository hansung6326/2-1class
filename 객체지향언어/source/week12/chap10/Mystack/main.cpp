#include <iostream>
using namespace std;

template <class T>
class MyStack {
	T data[100];
	int tos;
public:
	MyStack();
	void push(T element);
	T pop();
	int size();
};

template <class T>
MyStack<T>::MyStack() {
	tos = -1;
}

template <class T>
void MyStack<T>::push(T element) {
	if (tos == 99) {
		cout << "stack is full" << endl;
		return;
	}
	data[++tos] = element;
}

template <class T>
T MyStack<T>::pop() {
	if (tos == -1) {
		cout << "stack is empty" << endl;
		return T(); //int 면 0, double이면 0.0을 반환 NULL을 한다면 double이나 point 같은 사용자 정의 객체를 넣는다면 컴파일 에러 발생
	}
	return data[tos--];
}

template <class T>
int MyStack<T>::size() {
	return tos + 1;
}


int main() {
	MyStack<int> iStack;
	iStack.push(10);
	iStack.push(20);
	iStack.push(30);

	int size = iStack.size();
	for (int i = 0; i < size; i++) {
		cout << iStack.pop() << endl;
	}

	MyStack<string> sStack;
	sStack.push("I");
	sStack.push("love you");
	size = sStack.size();
	for (int i = 0; i < size; i++) {
		cout << sStack.pop() << endl;
	}

}