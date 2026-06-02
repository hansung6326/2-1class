#ifndef MYSTACK_H
#define MYSTACK_H

class MyStack {
	int p[10]; // 정수가 저장될 배열. 최대 10개
	int tos = 0; // 다음에 저장될 배열 원소의 인덱스. 초기값 0
public:
	MyStack();
	bool push(int n); // 정수 n 푸시. 꽉 차 있으면 false, 아니면 true 리턴
	bool pop(int& n); // 스택의 꼭대기에 있는 정수를 p[]에서 제거하고 n에 저장
					  // 스택이 비어 있으면 false, 아니면 true 리턴
};

#endif
