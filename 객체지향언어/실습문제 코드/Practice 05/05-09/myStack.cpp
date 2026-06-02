#include <iostream>
using namespace std;

class MyStack {
	int p[10]; // 정수가 저장될 배열. 최대 10개
	int tos=0; // 다음에 저장될 배열 원소의 인덱스. 초기값 0
public:
	MyStack();
	bool push(int n); // 정수 n 푸시. 꽉 차 있으면 false, 아니면 true 리턴
	bool pop(int& n); // 스택의 꼭대기에 있는 정수를 p[]에서 제거하고 n에 저장
					  // 스택이 비어 있으면 false, 아니면 true 리턴
};

MyStack::MyStack() { }

bool MyStack::push(int n) {
	if (tos == 10)
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
	MyStack st;
	for (int i = 0; i < 11; i++) { // 11개의 정수 푸시
		if (st.push(i)) cout << i << ' '; // 푸시된 값 화면 출력
		else cout << endl << i + 1 << "번째 푸시 실패! 스택 차 있음" << endl;
	}
	int n;
	for (int i = 0; i < 11; i++) { // 11번 팝
		if (st.pop(n)) cout << n << ' '; // 팝으로 받아온 값 출력
		else cout << endl << i + 1 << "번째 팝 실패! 스택이 비어 있음" << endl;
	}
}