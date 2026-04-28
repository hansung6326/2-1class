#include <iostream>
using namespace std;

class Player {
    string name;
public:
    Player() {}
    void setName(string name) { this->name = name; }
    string getName() { return name; }
};

class Gamemanager {
    int n;
    Player* players;
public:
    Gamemanager() : n(0), players(nullptr) {}

    ~Gamemanager() {
        delete[] players;
    }

    void run();
};

void Gamemanager::run() {
    cout << "끝말잇기 게임!" << endl;
    cout << "인원 수: ";
    cin >> n;

    players = new Player[n];

    for (int i = 0; i < n; i++) {
        string name;
        cout << "이름: ";
        cin >> name;
        players[i].setName(name);
    }

    cout << "첫 단어: 아버지" << endl;
    string lastWord = "아버지";

    int index = 0;

    while (true) {
        cout << players[index].getName() << ">>";
        string word;
        cin >> word;

        // 한글 2글자 기준 (UTF-8: 1글자 ≈ 3바이트 → 2글자 = 6바이트)
        if (word.length() < 3 || lastWord.length() < 3) {
            cout << "단어가 너무 짧습니다!" << endl;
            continue;
        }

        string first = word.substr(0, 3);
        string last = lastWord.substr(lastWord.length() - 3, 3);

        if (first == last) {
            index = (index + 1) % n;
            lastWord = word;
        }
        else {
            cout << players[index].getName() << "이(가) 졌습니다." << endl;
            break;
        }
    }
}

int main() {
    Gamemanager* p = new Gamemanager();
    p->run();
    delete p;
}