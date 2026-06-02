#include <iostream>
#include <string>
using namespace std;

class DebugInfo { // 하나의 디버깅 정보 저장
public:
	string tag; // 개발자 스스로 디버깅 정보를 구분하기위한 태그
	string comment; // 개발자가 기록하는 디버깅 정보
};

class Trace {
	static int index;
	static DebugInfo info[1000]; // 최대 1000 개의 디버깅 정보를 담는다.
public:
	static void put(string funcName, string msg);
	static void print(string tag = "");
};

void Trace::put(string tag, string comment) {
	if(index == 1000) {
		cout << "Trace 메모리 full" << endl;
		return;
	}

	DebugInfo dInfo;
	dInfo.tag = tag;
	dInfo.comment = comment;
	info[index] = dInfo;
	index++;
}

void Trace::print(string tag) {
	if (tag.length() == 0) { // 모든 태그의 Trace 출력
		cout << "모든 Trace 정보 출력 -----" << endl;
		for (int i = 0; i < index; i++) {
			DebugInfo a = info[i];
			cout << a.tag << ":\t" << a.comment << endl;
		}
	}
	else {
		cout << tag << "태그의 Trace 정보 출력 -----" << endl;
		for (int i = 0; i < index; i++) {
			DebugInfo a = info[i];
			if (a.tag == tag)
				cout << a.tag << ":\t" << a.comment << endl;
		}
	}
}

int Trace::index = 0; // static 멤버 함수는 반드시 초기화
DebugInfo Trace::info[1000]; // 최대 1000 개의 디버깅 정보를 담는다.

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
	int n = sumTo(1,5); // 1에서 5까지 더하기, n은 15
	Trace::put("main()", "n=" + to_string(n)); // Trace에 디버깅 정보 저장
	Trace::print("main()"); // "main()"태그의 디버깅 정보 모두 출력
	cout << endl;
	Trace::print(); // 모든 디버깅 정보 출력
}