#include <iostream>
using namespace std;

class MyStack {
	int* p; // 정수를 저장할 동적 배열을 가리키는 포인터
	int size = 0; // 할당받은 동적 배열의 크기. 초기값 0
	int tos = 0;  // 다음에 저장될 배열 원소의 인덱스. 초기값 0
public:
	MyStack();
	MyStack(int size);
	MyStack(const MyStack& src); // 복사 생성자
	~MyStack();
	bool push(int n); // 정수 n을 스택 푸시. 꽉 차 있으면 false, 아니면 true 리턴
	bool pop(int& n); // 스택의 탑에 있는 값을 n에 팝
					  // 스택이 비어 있으면 false, 아니면 true 리턴
};

MyStack::MyStack() : MyStack(10) { // 아래의 생성자 호출
	// 스택의 크기를 10으로 하여 객체 생성
} 

MyStack::MyStack(int size) {
	this->size = size;
	p = new int[size]; // 스택 메모리 할당
}

MyStack::MyStack(const MyStack& src) { // 복사 생성자
	size = src.size;
	tos = src.tos;
	p = new int[size]; // 원본 src 객체에 할당된 배열 크기로 동적 할당
	if (p == NULL)
		exit(0);
	for (int i = 0; i < size; i++)
		p[i] = src.p[i]; // 원본 MyStack 객체에 저장된 정수들 모두 복사
}

MyStack::~MyStack() {
	if (p)
		delete[] p; // 할당받은 동적 메모리 반환
}

bool MyStack::push(int n) {
	if (tos == size)
		return false; // stack full
	p[tos] = n;
	tos++;
	return true;
}

bool MyStack::pop(int& n) {
	if (tos == 0)
		return false; // stack empty
	tos--;
	n = p[tos];
	return true;
}

int main() {
	MyStack a(10); // 10개의 저장 공간을 가진 객체 생성
	a.push(10); a.push(20); // 스택 a에는 10, 20의 순서로 정수 저장

	MyStack b = a; // 복사 생성(객체 a를 복사하여 객체 b 생성)
	// 복사 후, 스택 b는 a와 같이 10, 20의 순서로 정수 저장
	b.push(30); // 스택 b에는 10, 20, 30의 순서로 정수 저장

	int n;
	a.pop(n); // 스택 a의 최상단에 저장된 정수 팝. n은 20
	cout << "스택 a에서 팝한 값 " << n << endl;
	b.pop(n); // 스택 b의 최상단에 저장된 정수 팝. n은 30
	cout << "스택 b에서 팝한 값 " << n << endl;
}