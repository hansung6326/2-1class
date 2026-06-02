#ifndef IDGENERATOR_H
#define IDGENERATOR_H

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

#endif