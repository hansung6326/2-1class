#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "IdGenerator.h"

IdGenerator::IdGenerator() {
	srand((unsigned)time(0)); // 랜덤수 발생을 위한 초기화(seed 지정)
}

string IdGenerator::next() {
	int fIdx = rand() % frontSize; // [0,frontSize-1] 사이의 랜덤 정수 생성
	int bIdx = rand() % backSize; // [0,backSize-1] 사이의 랜덤 정수 생성
	return front[fIdx] + " " + back[bIdx]; // 사용자ID 생성 후 리턴
}
