#include <iostream>
#include <cstring>
using namespace std;

int main() {
	cout << "에스프레소 3000원, 아메리카노 3500원, 카푸치노 4000원입니다." << endl;
	char c[50];
	int a, b = 0, money = 0;
	while (money <= 30000) {
		cout << "주문>>";
		cin >> c >> a;
		if (strcmp(c, "에스프레소") == 0) {
			b = 3000 * a;
			cout << b << "원입니다. 맛있게 드세요" << endl;
			money += b;
		}else if (strcmp(c, "카푸치노") == 0) {
			b = 4000 * a;
			cout << b << "원입니다. 맛있게 드세요" << endl;
			money += b;
		}else if (strcmp(c, "아메리카노") == 0) {
			b = 3500 * a;
			cout << b << "원입니다. 맛있게 드세요" << endl;
			money += b;
		}

	}
	cout << "오늘 " << money << "원을 판매하여 카페를 닫습니다." << endl;
}