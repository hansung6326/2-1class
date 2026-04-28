#include <iostream>
using namespace std;

class GameBoard {
	int count1, count2;
public:
	GameBoard() {
		count1 = 0;
		count2 = 0;
	}
	void increase(int score = 10, string team = "양팀") {
		if (team == "양팀") {
			count1 += score;
			count2 += score;
			return;
		}

		if (team == "청군") {
			count1 += score;
		}
		else if (team == "백군") {
			count2 += score;
		}
		else {
			cout << "청군 백군을 입력하세요" << endl;
			return;
		}
	}
	
	void show(string team = "양팀") {
		if (team == "양팀") {
			cout << "청군: " << count1 << ", 백군: " << count2 << endl;
			return;
		}
		if (team == "청군") {
			cout << "청군: " << count1 << endl;
		}
		else if (team == "백군") {
			cout << "백군: " << count2 << endl;
		}
		else {
			cout << "청군 백군을 입력하세요" << endl;
			return;
		}
	}
};

int main() {
	GameBoard board;
	board.increase();
	board.increase(20);
	board.increase(30, "청군");
	board.increase(40, "백군");
	board.show();
	board.show("청군");
}