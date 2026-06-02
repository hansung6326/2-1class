#include <iostream>
#include <string>
using namespace std;

class IdGenerator {
	int frontSize = 8;
	string front[8] = { "뛰어난", "사랑스러운", "까불까불", "희망찬",
						"멋있는", "향기로운", "씩씩한", "부드러운" };

	int backSize = 10;
	string back[10] = { "호랑이", "장미", "고양이", "한라산",
					"대한민국", "한강", "나팔꽃", "짜장면", 
					"짬뽕", "만두" };
public:
	IdGenerator();
	string next(); // 호출될 때마다 사용자ID를 생성하여 리턴
};

IdGenerator::IdGenerator() {
	srand((unsigned)time(0)); // 랜덤수 발생을 위한 초기화(seed 지정)
}

string IdGenerator::next() {
	int fIdx = rand() % frontSize; // [0,frontSize-1] 사이의 랜덤 정수 생성
	int bIdx = rand() % backSize; // [0,backSize-1] 사이의 랜덤 정수 생성
	return front[fIdx] + " " + back[bIdx]; // 사용자ID 생성 후 리턴
}

int main() {
	IdGenerator gen;
	while (true) {
		cout << "사용자 ID 생성(yes/no)>>";
		string res;
		cin >> res;
		if (res != "yes")
			break; // "yes"가 입력되면 프로그램 종료
		cout << gen.next() << endl; // 사용자 ID 생성
	}
}