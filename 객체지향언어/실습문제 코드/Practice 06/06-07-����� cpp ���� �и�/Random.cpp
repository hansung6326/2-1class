#include <iostream>
#include <cstdlib>
using namespace std;

#include "Random.h"

int Random::nextInt(int min, int max) {
	int range = max - min;
	if (range < 0)
		return -1; // 오류
	int n = rand(); // 0에서 RAND_MAX(32767) 사이의 랜덤한 정수 발생
	n = (n % (range + 1)) + min;
	return n;
}

char Random::nextAlphabet() {
	int n = nextInt(0, 25); // 알파벳 26글자
	int s = nextInt() % 2; // 대소문자 결정
	if (s == 0) // 대문자
		return 'A' + n;
	else // 소문자
		return 'a' + n;
}

double Random::nextDouble() {
	return ((double)rand())/RAND_MAX;
}