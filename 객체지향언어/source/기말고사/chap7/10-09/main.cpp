#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	map<string, int> m;
	m.insert(make_pair("짜장면", 5000));
	m.insert(make_pair("짬뽕", 6000));
	m.insert(make_pair("볶음밥", 8000));
	m.insert(make_pair("탕수육", 25000));

	string menu;
	int num;
	while (true) {
		cout << "주문>>";
		cin >> menu;
		if (menu == "그만")
			break;
		cin >> num;
		if (m.find(menu) == m.end()) {
			cout << "없는 메뉴입니다." << endl;
		}
		else {
			cout << "가격은 " << m[menu] * num << "원입니다." << endl;
		}
			
	}
}