#include <iostream>
#include <string>
#include <map>
using namespace std;

void printMap(map<string, int>& m) {
	map<string, int>::iterator it;
	for (it = m.begin(); it != m.end(); it++) {
		string name = it->first;
		int price = it->second;
		cout << name << ": " << price << "원" << endl;
	}
}

int main() {
	map<string, int> priceMap;
	priceMap["붕어빵"] = 2000;
	priceMap["잉어빵"] = 2500;
	priceMap.insert(make_pair("국화빵", 3000));
	printMap(priceMap);
	cout << endl;

	priceMap.erase("붕어빵");
	printMap(priceMap);
}