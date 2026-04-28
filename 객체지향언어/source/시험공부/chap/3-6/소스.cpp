#include <iostream>
#include <string>
using namespace std;

class Memo {
	string date, content;
public:
	Memo(string date, string content) {
		this->date = date;
		this->content = content;
	}
	void show() {
		cout << date << ", " << content << endl;
	}
	bool isSameDate(Memo b) {
		if (date == b.date)
			return true;
		return false;
	}
	string getDate() {
		return date;
	}
	string getContent() {
		return content;
	}
};

int main() {
	Memo a("1:20", "동계 프로그래밍 캠프");
	Memo b("2:20", "김경미 독일 송별회");
	Memo c("2:21", "박채원 졸업식. 대학원 간대");
	a.show();
	if (a.isSameDate(b)) cout << "같은 날입니다." << endl;
	else cout << "다른 날입니다." << endl;
	cout << b.getDate() << "에 " << b.getContent() << endl;
}