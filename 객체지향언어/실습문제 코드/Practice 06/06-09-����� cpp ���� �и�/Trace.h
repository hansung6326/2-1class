#ifndef TRACE_H
#define TRACE_H

#include <string>
using namespace std;

class DebugInfo;

class Trace {
	static int index;
	static DebugInfo info[1000]; // 최대 1000 개의 디버깅 정보를 담는다.
public:
	static void put(string funcName, string msg);
	static void print(string tag = "");
};

#endif
