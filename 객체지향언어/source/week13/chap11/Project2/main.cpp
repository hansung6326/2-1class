#include <iostream>
#include <string>
using namespace std;

ostream& fivestar(ostream& out) {
	out << "*****";
	return out;
}

ostream& beep(ostream& out) {
	out << '\a';
	return out;
}

istream& question(istream& in) {
	cout << "질문을 입력하세요 ";
	return in;
}

int main() {
	string answer;
	cin >> question >> answer;
	if (answer == "가나다")
		cout << "정답입니다" << endl;
	else
		cout << "틀렸습니다" << endl;
	cout << fivestar << beep << endl;
	
}