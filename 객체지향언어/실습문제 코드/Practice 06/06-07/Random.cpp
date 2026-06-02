#include <iostream>
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
	return ((double)rand()) / RAND_MAX;
}

int main() {
	Random::seed();
	cout << "1에서 100까지 랜덤한 정수 10개를 출력합니다." << endl << "-> ";
	for (int i = 0; i < 10; i++) 
		cout << Random::nextInt(1, 100) << ' ';
	cout << endl;

	cout << "알파벳을 랜덤하게 10개를 출력합니다." << endl << "-> ";
	for (int i = 0; i < 10; i++) 
		cout << Random::nextAlphabet() << ' ';
	cout << endl;

	cout << "랜덤한 실수를 10개를 출력합니다." << endl << "-> ";
	for (int i = 0; i < 5; i++) 
		cout << Random::nextDouble() << ' ';
	cout << endl;
	for (int i = 0; i < 5; i++) 
		cout << Random::nextDouble() << ' ';
	cout << endl;
}
