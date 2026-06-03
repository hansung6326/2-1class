#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	int num;
	cout << "10개의 정수 입력>>";
	for (int i = 0; i < 10; i++) {
		cin >> num;
		v.push_back(num);
	}

	vector<int>::iterator it;
	int sel;
	while (true) {
		cout << "가장 큰 값:1, 평균:2, 삽입:3, 삭제:4, 증가:5, 종료:6>>";
		cin >> sel;
		int big = v[0];
		double sum = 0;
		switch (sel) {
		case 1:
			for (it = v.begin(); it != v.end(); it++) {
				if (big < *it)
					big = *it;
			}
			cout << "가장 큰 값 " << big << endl;
			break;
		case 2:
			for (it = v.begin(); it != v.end(); it++) {
				sum += *it;
			}
			cout << "평균 " << sum / v.size() << endl;
			break;
		case 3:
			cout << "삽입할 값>>";
			cin >> num;
			v.push_back(num);
			break;
		case 4:
			cout << "삭제할 값>>";
			cin >> num;
			for (it = v.begin(); it != v.end();) {
				if (*it == num)
					it = v.erase(it);
				else
					it++;
			}
			break;
		case 5:
			cout << "몇배로 증가>>";
			cin >> num;
			for (it = v.begin(); it != v.end(); it++) {
				*it *= num;
				cout << *it << ' ';
			}
			cout << endl;
			break;
		case 6:
			return 0;
		}
	}
	
	
}