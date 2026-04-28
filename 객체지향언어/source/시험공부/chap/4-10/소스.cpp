#include <iostream>
#include <string>
using namespace std;

class Movie {
	string title; int score;
public:
	Movie() {
		title = "";
		score = 0;
	}
	string getTitle() {
		return title;
	}
	int getScore() {
		return score;
	}
	void set(string title, int score) {
		this->title = title;
		this->score = score;
	}
};

class Recommender {
	string name;
	int size;
	Movie* movies;
public:
	Recommender(string name, int size) {
		this->name = name;
		this->size = size;
		movies = new Movie[size];
		cout << name << " 객체가 생성되었습니다." << endl;
	}
	~Recommender() {
		delete[] movies;
		cout << name << " 객체가 소멸되었습니다." << endl;
	}
	void read() {
		string line;
		for (int i = 0; i < size; i++) {
			cout << "영화" << i + 1 << ">>";
			
			string title;
			int score;
			getline(cin, title, ',');
			cin >> score;
			string temp;
			getline(cin, temp, '\n');

			movies[i].set(title, score);
		}
	}
	void list() {
		for (int i = 0; i < size; i++) {
			cout << "[" << movies[i].getTitle() << "," << movies[i].getScore() << "]\t";
		}
		cout << endl;
	}
	Movie recommend() {
		int maxIdx = 0;
		for (int i = 1; i < size; i++) {
			if (movies[i].getScore() > movies[maxIdx].getScore())
				maxIdx = i;
		}
		return movies[maxIdx];
	}
};

int main() {
	Recommender* mr = new Recommender("베스트 영화 추천", 3);
	mr->read();
	mr->list();
	Movie m = mr->recommend();
	cout << "추천 영화: " << m.getTitle() << endl;
	delete mr;
}