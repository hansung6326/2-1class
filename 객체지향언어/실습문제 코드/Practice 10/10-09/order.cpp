#include <iostream>
#include <map>
using namespace std;

void init(map<string, int>& menuMap) {
	menuMap["짜장면"] = 5000;
	menuMap["짬뽕"] = 6000;
	menuMap["볶음밥"] = 8000;
	menuMap["탕수육"] = 25000;
}

int main() {
	map<string, int> menuMap;
	init(menuMap);

	while (true) {
		cout << "주문>>";
		string menu;
		int amount;
		cin >> menu;
		if (menu == "그만")
			return 0;

		cin >> amount;
		if (menuMap.find(menu) == menuMap.end()) // 없는 메뉴
			cout << "없는 메뉴입니다." << endl;
		else
			cout << "가격은 " << menuMap[menu] * amount << "원입니다." << endl;
	}
}