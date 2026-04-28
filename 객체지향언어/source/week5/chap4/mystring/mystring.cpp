#include <iostream>
#include <string>
using namespace std;

int main() {
	string text;
	cout << "문자열을 입력하세요 " << endl;
	getline(cin, text, '\n');

	for (int i = 0; i < text.length(); i++) {
		string first = text.substr(0, 1);
		string sub = text.substr(1, text.length() - 1);
		text = sub + first;
		cout << text << endl;
	}
}

/* int main() {
	string names[5];
	for (int i = 0; i < 5; i++) {
		cout << "이름 >> ";
		getline(cin, names[i], '\n');
	}

	for (int i = 0; i < 5; i++) {
		cout << names[i] << endl;
	}

	//사전에서 가장 뒤에 나오는 문자열 구하기
	string latter = names[0];
	for (int i = 0; i < 5; i++) {
		if (latter < names[i])
			latter = names[i];
	}
	cout << "사전에서 가장 뒤에 나오는 문자열은 " << latter << endl;
} */

/* int main() {
	cout << "이름 입력? ";
	string name;
	//cin >> name;
	getline(cin, name, '\n'); //빈칸을 포함하여 <Enter>키가 입력되기 전까지 문자열 저장
	cout << name;
} */

/* void main() {
	string str;
	string address("서울시 성북구");
	string copyAddr(address);

	cout << str << endl;
	cout << address << endl;
	cout << copyAddr << endl;

	str.append("hello");
	cout << str << endl;

	char text[] = "Love";
	string title(text);

	cout << title << endl;


} */