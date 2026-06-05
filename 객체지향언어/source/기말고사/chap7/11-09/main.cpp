#include <iostream>
#include <string>
using namespace std;

istream& promptName(istream& ist) {
	cout << "이름 입력>>";
	return ist;
}
istream& promptAge(istream& ist) {
	cout << "나이 입력>>";
	return ist;
}

int main() {
	string name;
	int age;
	cin >> promptName >> name;
	cin >> promptAge >> age;
	cout << "이름은 " << name << ", 나이는 " << age << endl;
}