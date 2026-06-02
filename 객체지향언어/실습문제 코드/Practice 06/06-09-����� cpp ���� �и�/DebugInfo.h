#ifndef DEBUGINFO_H
#define DEBUGINFO_H

#include <string>
using namespace std;

class DebugInfo { // 하나의 디버깅 정보 저장
public:
	string tag; // 개발자 스스로 디버깅 정보를 구분하기위한 태그
	string comment; // 개발자가 기록하는 디버깅 정보
}; 

#endif
