#include <iostream>
using namespace std;

class Member {
protected:
	string name;
	int point = 0;
	int ratio;
public:
	Member(string name, int ratio = 1) {
		this->name = name;
		this->ratio = ratio;
	}
	void earn(int pay) {
		point = getPoint() + pay * ratio / 100;
	}
	int getPoint() {
		return point;
	}
	void show() {
		cout << name << "의 포인트 " << point << endl;
	}
};

class GoldMember : public Member {
public:
	GoldMember(string name) : Member(name, 3) {

	}
	void earn(int pay) {
		int goldRatio = 0;
		if (pay < 100000)
			goldRatio = ratio;
		if (pay >= 100000 && pay < 200000)
			goldRatio = 4;
		else if (pay >= 200000)
			goldRatio = 5;
		point = getPoint() + pay * goldRatio / 100;
	}
};

int main() {
	Member a("황기태");
	GoldMember b("제인");
	for (int i = 0; i < 5; i++) {
		cout << (i + 1) << " 이름과 지출액>>";
		string name;
		int pay;
		cin >> name >> pay;
		if (name == "황기태")
			a.earn(pay);
		else if (name == "제인")
			b.earn(pay);
		else
			i--;
	}
	a.show();
	b.show();
}
