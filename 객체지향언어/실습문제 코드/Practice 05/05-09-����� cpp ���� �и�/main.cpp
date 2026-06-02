#include <iostream>
using namespace std;

#include "MyStack.h"

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