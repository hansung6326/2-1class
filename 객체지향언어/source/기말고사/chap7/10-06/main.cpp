#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
	srand((unsigned)time(NULL));
	vector<string> first;
	vector<string> middle;
	vector<string> last;

	bool isSame = false;
	string name;
	cout << "성으로 사용될 글자들 입력>>";
	getline(cin, name);
	string tmp = "";
	for (int i = 0; i <= name.size(); i++) {
		if (name[i] == ' ' || i == name.size()) {
			if (tmp != "") {
				isSame = false;
				for (int j = 0; j < first.size(); j++) {
					if (tmp == first[j]) {
						isSame = true;
						break;
					}
				}
				if(!isSame)
					first.push_back(tmp);
			}
			tmp = "";
		}
		else {
			tmp += name[i];
		}
	}

	cout << "중간 이름으로 사용될 글자들 입력>>";
	getline(cin, name);
	tmp = "";
	for (int i = 0; i <= name.size(); i++) {
		if (name[i] == ' ' || i == name.size()) {
			if (tmp != "") {
				isSame = false;
				for (int j = 0; j < middle.size(); j++) {
					if (tmp == middle[j]) {
						isSame = true;
						break;
					}
				}
				if (!isSame)
					middle.push_back(tmp);
			}
			tmp = "";
		}
		else {
			tmp += name[i];
		}
	}

	cout << "끝 이름으로 사용될 글자들 입력>>";
	getline(cin, name);
	tmp = "";
	for (int i = 0; i <= name.size(); i++) {
		if (name[i] == ' ' || i == name.size()) {
			if (tmp != "") {
				isSame = false;
				for (int j = 0; j < last.size(); j++) {
					if (tmp == last[j]) {
						isSame = true;
						break;
					}
				}
				if (!isSame)
					last.push_back(tmp);
			}
			tmp = "";
		}
		else {
			tmp += name[i];
		}
	}

	int count;
	string newName;
	while (true) {
		cout << "생성할 이름 수>>";
		cin >> count;
		if (count <= 0)
			break;
		if (count > first.size() * middle.size() * last.size()) {
			cout << "최대 생성 가능한 이름 개수는 " << first.size() * middle.size() * last.size() << endl;
			continue;
		}
		vector<string> fullName;
		for (int i = 0; i < count; i++) {
			do {
				newName = first[rand() % first.size()] + middle[rand() % middle.size()] + last[rand() % last.size()];
				isSame = false;
				for (int j = 0; j < fullName.size(); j++) {
					if (newName == fullName[j]) {
						isSame = true;
						break;
					}
				}
			} while (isSame);
			fullName.push_back(newName);
			cout << newName << ' ';
		}
		cout << endl;
	}

}