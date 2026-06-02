#include <iostream>
#include <string>
using namespace std;

#include "DebugInfo.h"
#include "Trace.h"

int Trace::index = 0; // static 멤버 함수는 반드시 초기화
DebugInfo Trace::info[1000]; // 최대 1000 개의 디버깅 정보를 담는다.

void Trace::put(string tag, string comment) {
	if (index == 1000) {
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