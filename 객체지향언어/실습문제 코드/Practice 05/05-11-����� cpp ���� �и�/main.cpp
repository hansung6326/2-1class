#include <iostream>
using namespace std;

#include "MyStack.h"

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