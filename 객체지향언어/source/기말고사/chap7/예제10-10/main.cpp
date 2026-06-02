#include <iostream>
#include <string>
#include <map>
using namespace std;

class Item {
public:
	int price;
	int count;
	Item(int price = 0, int count = 0) {
		this->price = price;
		this->count = count;
	}
};

int main() {
	map<string, Item> stock;
	string name;
	int price = 0, count = 0, removedCount = 0;

	while (true) {
		cout << "상품 입고:1, 검색:2, 삭제:3, 종료:4>>";
		int menu;
		cin >> menu;
		switch (menu) {
		case 1:
			cout << "상품명, 가격, 개수 입력>>";
			cin >> name >> price >> count;
			stock.insert(make_pair(name, Item(price, count)));
			break;
		case 2:
			cout << "상품명 입력>>";
			cin >> name;
			if (stock.find(name) == stock.end())
				cout << name << " 없음" << endl;
			else {
				Item item = stock[name];
				cout << "가격 " << item.price << ", 재고 " << item.count << "개" << endl;
			}
			break;
		case 3:
			cout << "상품명 입력>>";
			cin >> name;
			removedCount = stock.erase(name);
			if (removedCount == 0)
				cout << name << " 없음" << endl;
			else
				cout << name << " 삭제 완료" << endl;
			break;
		case 4:
			cout << "종료합니다..." << endl;
			return 0;
		}

	}
}