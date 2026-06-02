#include <iostream>
using namespace std;

istream& promptName(istream& ins) {
	cout << "이름 입력>>";
	return ins;
}

istream& promptAge(istream& ins) {
	cout << "나이 입력>>";
	return ins;
}

int main() {
	string name;
	int age;
	cin >> promptName >> name;
	cin >> promptAge >> age;
	cout << "이름은 " << name << ", 나이는 " << age << endl;
}