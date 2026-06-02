#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

class Nation {
	string nation; // 나라 이름
	string capital; // 수도
public:
	Nation(string nation, string capital) {
		this->nation = nation;
		this->capital = capital;
	}
	string getCapital() { return capital; }
	string getNation() { return nation; }
	void show() {
		cout << '(' << nation << ',' << capital << ')';
	}
};

class NationGame {
	vector<Nation> v;
	void input();
	void list();
	void quiz();
	bool exist(string nation);
public:
	NationGame();
	void run();
};

NationGame::NationGame() {
	// 9개의 Nation 객체 생성
	Nation n[] = { Nation("미국", "와싱턴"), Nation("영국", "런던"), Nation("프랑스", "파리"),
		Nation("중국", "베이찡"), Nation("일본", "도쿄"), Nation("러시아", "모스크바"),
		Nation("브라질", "브라질리아"), Nation("독일", "베를린"), Nation("멕시코", "멕시코시티") };

	for (int i = 0; i < 9; i++)
		v.push_back(n[i]); // 벡터에 9개의 Nation 객체 저장

	srand((unsigned)time(0)); // 시작할 때마다, 다른 랜덤수를 발생시키기 위한 seed 설정
}

void NationGame::run() {
	cout << "***** 나라의 수도 맞추기 게임을 시작합니다. *****" << endl;
	while (true) {
		int cmd;
		cout << "정보 입력: 1, 퀴즈: 2, 종료: 3>>";
		cin >> cmd;
		switch (cmd) {
		case 1: input(); break;
		case 2: quiz(); break;
		case 3: return;
		}
	}
}
void NationGame::quiz() {
	while (true) {
		int index = rand() % v.size(); // 0에서 벡터 크기 내 랜덤 정수가 n에 저장
		cout << v[index].getNation() << "의 수도는?";
		string capital;
		cin >> capital;
		if (capital == "exit")
			return; // quiz 그만

		if (v[index].getCapital() == capital)
			cout << "Correct !!" << endl;
		else
			cout << "NO !!" << endl;
	}
}

void NationGame::input() {
	string nation, capital;
	cout << "현재 " << v.size() << "개의 나라가 입력되어 있습니다." << endl;
	cout << "나라와 수도를 입력하세요(no no 이면 입력끝)" << endl;
	while (true) {
		cout << v.size() + 1 << ">>";
		cin >> nation >> capital;
		if (nation == "no" && capital == "no")
			break;
		if (exist(nation)) {
			cout << "already exists !!" << endl;
			continue;
		}
		Nation n(nation, capital);
		v.push_back(n);
	}
	// list();
	return;
}

bool NationGame::exist(string nation) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i].getNation() == nation)
			return true;
	}

	return false;
}

void NationGame::list() { // 모든 원소 출력
	for (int i = 0; i < v.size(); i++) {
		v[i].show();
		cout << endl;
	}
}

int main() {
	NationGame game;
	game.run();
}