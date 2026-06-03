#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;

	while (true) {
		int num;
		bool isSame = false;
		cout << "정수를 입력하세요. 0이면 종료>>";
		cin >> num;
		if (num == 0)
			break;
		for (int i = 0; i < v.size(); i++) {
			if (num == v[i]) {
				cout << "이미 있음" << endl;
				isSame = true;
				break;
			}
		}
		if (isSame)
			continue;
		v.push_back(num);
		int big = v[0];
		cout << "[" << v[0];
		for (int i = 1; i < v.size(); i++) {
			cout << " " << v[i];
			if (v[i] > big)
				big = v[i];
		}
		cout << "], 가장 큰 수 " << big << endl;
	}
}