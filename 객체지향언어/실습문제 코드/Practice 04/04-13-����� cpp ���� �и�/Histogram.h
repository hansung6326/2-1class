#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <string>
using namespace std;

class Histogram {
	string text;
	int histo[26]; // 26개의 알파벳에 대해 각 글자당 개수 저장
public:
	Histogram();
	Histogram(string text); // 생성자에 히스토그램으로 분석할 문자열 전달
	void addc(char c); // 히스토그램에 문자 삽입
	void add(string text); // 히스토그램에 string 문자열 삽입
	void draw(); // 히스토그램의 화면 출력
	~Histogram() {}
};

#endif
