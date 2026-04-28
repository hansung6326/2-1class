#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	srand(time(NULL));

	string yn = "yes";
	string front[4] = { "뛰어난", "사랑스러운", "까불까불", "씩씩한" };
	string back[4] = { "호랑이", "장미", "고양이", "나팔꽃" };

	while (yn == "yes") {
		cout << "사용자 ID 생성(yes/no) >> ";
		cin >> yn;
		if (yn == "no")
			break;

		int index1 = rand() % 4;
		int index2 = rand() % 4;

		cout << front[index1] << " " << back[index2] << endl;
	}
	return 0;
}