#ifndef RANDOM_H
#define RANDOM_h

#include <cstdlib>
#include <ctime>
using namespace std;

class Random {
	Random() {} // private 속성의 생성자
public:
	// seed()는 다른 랜덤수를 발생시키기 위한 초기화(seed 설정) 함수
	static void seed() { srand((unsigned)time(0)); } // 씨드 설정
	static int nextInt(int min = 0, int max = 32767); // min과 max 사이의 랜덤 정수 리턴
	static char nextAlphabet(); // 랜덤하게 알파벳 문자 리턴
	static double nextDouble(); // 0보다 크거나 같고 1보다 적은 랜덤 실수 리턴 
};

#endif
