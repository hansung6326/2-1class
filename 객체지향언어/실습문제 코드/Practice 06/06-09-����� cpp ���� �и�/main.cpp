#include <iostream>
#include <string>
using namespace std;

#include "DebugInfo.h"
#include "Trace.h"

int sumTo(int start, int end);

int sumTo(int start, int end) {
	Trace::put("sumTo()", "매개변수 start=" + to_string(start)); // Trace에 디버깅 정보 저장
	Trace::put("sumTo()", "매개변수 end=" + to_string(end)); // Trace에 디버깅 정보 저장
	int sum = 0;
	for (int i = start; i <= end; i++) {
		sum += i;
		Trace::put("sumTo()", "sum=" + to_string(sum)); // Trace에 디버깅 정보 저장
	}
	return sum;
}

int main() {
	Trace::put("main()", "프로그램 시작"); // Trace에 디버깅 정보 저장
	int n = sumTo(1, 5); // 1에서 5까지 더하기, n은 15
	Trace::put("main()", "n=" + to_string(n)); // Trace에 디버깅 정보 저장
	Trace::print("main()"); // "main()"태그의 디버깅 정보 모두 출력
	cout << endl;
	Trace::print(); // 모든 디버깅 정보 출력
}