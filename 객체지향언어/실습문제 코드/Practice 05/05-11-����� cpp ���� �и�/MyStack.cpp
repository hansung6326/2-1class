#include <iostream>
using namespace std;

#include "MyStack.h"

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