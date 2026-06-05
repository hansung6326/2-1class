#include <iostream>
#include <string>
using namespace std;

istream& prompt(istream& ist) {
	cout << "암호>>";
	return ist;
}

int main() {
	string password;
	while (true) {
		cin >> prompt >> password;
		if (password == "C++") {
			cout << "login success!!" << endl;
			break;
		}
		cout << "login fail. try again!!" << endl;
	}
}