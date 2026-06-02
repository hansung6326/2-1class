#include <iostream>
#include <string>
#include <map>
using namespace std;

class Content {
public:
	string passwd, hint; // 암호와 힌트 모두 빈칸 없는 문자열
	Content(string passwd="", string hint="") {
		this->passwd = passwd;
		this->hint = hint;
	}
};

class PasswordManager {
	string program;
	map<string, Content> passwdMap; // 이름과 암호를 저장하는 map
	void add();
	void search();
	bool checkInputError();
public:
	PasswordManager(string);
	void run();
};

PasswordManager::PasswordManager(string program) {
	this->program = program;
}

void PasswordManager::add() {
	string name, passwd, hint;
	cout << "이름, 암호, 힌트>>";
	cin >> name >> passwd >> hint;
	passwdMap[name] = Content(passwd, hint);
}

void PasswordManager::search() {
	string name;
	string inputPassword;
	Content storedContent;
	cout << "이름?";
	cin >> name;

	// 이름이 있는 지 확인
	if (passwdMap.find(name) == passwdMap.end()) { // name이 map에 없음
		cout << name << "은 없는 이름입니다." << endl;
		return;
	}

	// name이 map에 있는 경우
	// 실패한 경우 힌트 출력
	cout << "암호?";
	cin >> inputPassword;
	storedContent = passwdMap[name];
	if (inputPassword == storedContent.passwd) { // 암호를 맞힌 경우
		cout << "통과!!" << endl;
	}
	else { // 실패한 경우
		cout << "실패~~. 힌트는 " << storedContent.hint << endl;
	}
}

bool PasswordManager::checkInputError() {
	if (cin.fail()) { // 정수대신 문자열이 입력되어 오류가 발생하는 경우. 부록 C의 예제 C-1참고
		cin.clear();
		cin.ignore(100, '\n');
		cout << "입력 오류" << endl;
		return true; // 오류 있음
	}
	else
		return false; // 오류 없음
}

void PasswordManager::run() {
	int menu;

	cout << "***** 암호관리 프로그램 " << program << "를 시작합니다 *****" << endl;
	while (true) {
		cout << "삽입:1, 검사:2, 종료:3>>";
		cin >> menu;

		// 단순하게 작성하려는 경우 다음 2 라인은 호출하지 않아도 됨
		if (checkInputError()) // 메뉴(menu)를 사용자가 숫자를 입력하지 않는 경우, 오류 발생
			continue;
		switch (menu) {
		case 1: add(); break;
		case 2: search(); break;
		case 3: cout << "프로그램을 종료합니다..."; return;
		}
	}
}

int main() {
	PasswordManager mm("Who are you?");
	mm.run();
}