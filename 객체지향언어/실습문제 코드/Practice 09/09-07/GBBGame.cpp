#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Player {
protected:
	string name; // 선수 이름
	string bet; // 선수가 최근 낸 것(가위, 바위, 보 중에서)
	const string shape[3] = { "가위", "바위", "보" };
public:
	Player(string name) { this->name = name; }
	string getName() { return name; }
	string getBet() { return bet; }
	virtual void turn() = 0; // 선수가 자신의 차례일 때 가위, 바위, 보 중 하나를 bet에 저장
};

class AI : public Player {
public:
	AI(string name) : Player(name) {
		srand((unsigned)time(0));
	}
	void turn() { // 기계는 가위, 바위, 보 중 랜덤하게 한 개 발생
		bet = shape[rand() % 3]; // rand() % 3은 0,1,2 중에서 bet에 저장
	}
};

class Human : public Player {
public:
	Human(string name) : Player(name) {}
	void turn(); // 사용자로부터 입력받아 위, 바위, 보 중 한 개 bet에 저장
};

void Human::turn() { // 사용자로부터입력받아 위, 바위, 보 중 랜덤하게 한 개 리턴
	while (true) {
		cout << getName() << "님, 가위 바위 보!>>";
		string user;
		cin >> user; // 사용자가 낸 것 읽기
		for (int i = 0; i < 3; i++) {
			if (user == shape[i]) {
				this->bet = user; // 멤버 변수 bet에 저장
				return;
			}
		}
		// 가위, 바위, 보 모두 아니라면 다시 입력
	}
}

int main() {
	Player* players[2];
	players[0] = new Human("황수희");
	players[1] = new AI("AI제인");

	// 두 선수의 가위 바위 보 내기
	for (int i = 0; i < 2; i++) players[i]->turn();
	for (int i = 0; i < 2; i++) // 선수들이 낸 것 출력
		cout << players[i]->getName() + " " + players[i]->getBet() << ", ";
	cout << endl;

	if (players[0]->getBet() == players[1]->getBet()) // 낸 것이 같으면 AI 승리
		cout << players[0]->getName() + " 승리!";
	else // 다르면 사람 승리
		cout << players[1]->getName() + " 승리!";

	for (int i = 0; i < 2; i++) delete players[i];
}