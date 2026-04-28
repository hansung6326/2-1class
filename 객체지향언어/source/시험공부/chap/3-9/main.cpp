#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Coffee {
public:
	int calculate(string s, int ea);
};

int Coffee::calculate(string s, int ea) {
	int price = 0;
	if (s == "에스프레소")
		price = 3000 * ea;
	else if (s == "아메리카노")
		price = 3500 * ea;
	else if (s == "카푸치노")
		price = 4000 * ea;
	else {
		cout << "없는 메뉴입니다." << endl;
		return 0;
	}

	cout << price << "원입니다." << endl;

	return price;
}

int main() {
	cout << "에스프레소 3000원, 아메리카노 3500원, 카푸치노 4000원입니다." << endl;
	string s;
	int a;
	int totalMoney = 0;
	Coffee manager;
	while (totalMoney <= 30000) {
		cout << "주문>>";
		cin >> s >> a;
		
		totalMoney += manager.calculate(s, a);
	}
	cout << "오늘 " << totalMoney << "원을 판매하여 카페를 닫습니다." << endl;
}