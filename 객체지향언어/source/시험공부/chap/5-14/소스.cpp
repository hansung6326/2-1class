#include <iostream>
#include <string>
using namespace std;

class Contest {
	string* teams;
	int* scores;
	int size;
public:
	Contest(int size) {
		this->size = size;
		teams = new string[size];
		scores = new int[size];
	}
	Contest(const Contest& src) {
		size = src.size;
		teams = new string[size];
		scores = new int[size];
		for (int i = 0; i < size; i++) {
			teams[i] = src.teams[i];
			scores[i] = src.scores[i];
		}
	}
	~Contest() {
		delete[] teams;
		delete[] scores;
	}
	void read() {
		cout << "6개 입력>>";
		for (int i = 0; i < size; i++) {
			cin >> teams[i] >> scores[i];
		}
	}
	int getSize() {
		return size;
	}
	int getScore(int index) {
		return scores[index];
	}
	string getTeam(int index) {
		return teams[index];
	}
};

string decideGoldAward(Contest codingTest) {
	int index = 0;
	int max = codingTest.getScore(index);
	for (int i = 1; i < codingTest.getSize(); i++) {
		if (codingTest.getScore(i) > max) {
			max = codingTest.getScore(i);
			index = i;
		}
	}
	return codingTest.getTeam(index);
}

int main() {
	Contest codingTest(6);
	codingTest.read();
	string team = decideGoldAward(codingTest);
	cout << "금상은 " << team << " 팀입니다." << endl;
}