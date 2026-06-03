#include <iostream>
#include <vector>
using namespace std;

void biggest(vector<int>& v) {
	int big = v[0];
	for (size_t i = 0; i < v.size(); i++) {
		if (big < v[i])
			big = v[i];
	}
	cout << "가장 큰 수 " << big << endl;
}

void average(vector<int>& v) {
	int sum = 0;
	for (size_t i = 0; i < v.size(); i++) {
		sum += v[i];
	}
	cout << "평균 " << ((double)sum) / v.size() << endl;
}

void add(vector<int>& v, int n) {
	v.push_back(n);
}

void increase(vector<int>& v, int n) {
	for (size_t i = 0; i < v.size(); i++) {
		v[i] *= n;
		cout << v[i] << ' ';
	}
	cout << endl;
}

void purge(vector<int>& v, int n) {
	vector<int>::iterator it;

	// 반복문 내부에서 erase 사용 시 안전하게 반복자를 업데이트해야 합니다.
	for (it = v.begin(); it != v.end(); ) {
		if (*it == n) {
			it = v.erase(it);
		}
		else {
			it++;
		}
	}

	for (it = v.begin(); it != v.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl;
}

int main() {
	vector<int> v;

	cout << "10개의 정수 입력>>";
	for (int i = 0; i < 10; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}

	while (true) {
		int n;
		cout << "가장큰수:1, 평균:2, 추가:3, 삭제:4, 곱하기:5, 종료:6>>";
		int menu;
		cin >> menu;
		switch (menu) {
		case 1:
			biggest(v);
			break;
		case 2:
			average(v);
			break;
		case 3:
			cout << "추가할 수>>";
			cin >> n;
			add(v, n);
			break;
		case 4:
			cout << "삭제할 수>>";
			cin >> n;
			purge(v, n);
			break;
		case 5:
			cout << "곱할 정수>>";
			cin >> n;
			increase(v, n);
			break;
		case 6:
			return 0;
		}
	}
}