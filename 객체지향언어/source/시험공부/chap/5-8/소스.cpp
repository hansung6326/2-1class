#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Fitness {
	string gender;
	int men, women;
public:
	Fitness() {
		men = 0;
		women = 0;
	}
	Fitness& arrive(string gender, int count) {
		if (gender == "남")
			men += count;
		else if(gender == "여")
			women += count;
		else {
			cout << "잘못된 성별 입력" << endl;
			return *this;
		}
		return *this;
	}
	void count(string gender, int& count) {
		if (gender == "남")
			count = men;
		else if (gender == "여")
			count = women;
		else {
			cout << "잘못된 성별 입력" << endl;
			return;
		}
	}
	int& at(string gender) {
		if (gender == "남")
			return men;
		else if (gender == "여")
			return women;
		else {
			cout << "잘못된 성별 입력" << endl;
			exit(1);
		}
	}
};

int main() {
	Fitness altong;
	altong.arrive("남", 3).arrive("여", 6).arrive("남", 9);
	
	int m = 0, w = 0;
	altong.count("남", m);
	altong.count("여", w);
	cout << "남자 회원 " << m << "명, 여자 회원 " << w << "명" << endl;

	altong.at("남") = 100;
	m = altong.at("남");
	w = altong.at("여");
	cout << "남자 회원 " << m << "명, 여자 회원 " << w << "명" << endl;
}