#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	map<string, int> voteMap;
	string name;
	bool stop = false;
	while (true) {
		cout << "이름 3개>>";
		for (int i = 0; i < 3; i++) {
			cin >> name;
			if (name == "그만") {
				stop = true;
				break;
			}
			if (voteMap.find(name) == voteMap.end())
				voteMap.insert(make_pair(name, 1));
			else {
				voteMap[name]++;
			}
		}
		if (stop)
			break;
	}
	
	map<string, int>::iterator it;
	map<string, int>::iterator bigIt = voteMap.begin();

	for (it = voteMap.begin(); it != voteMap.end(); it++) {
		cout << it->first << ":" << it->second << ", ";
		if (it->second > bigIt->second) {
			bigIt = it;
		}
	}
	cout << endl;
	cout << bigIt->first << "님이 회장으로 선출되었습니다." << endl;


}