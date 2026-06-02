#ifndef MYSTACK_H
#define MYSTACK_H

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

#endif
