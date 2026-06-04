#include <iostream>
#include <cctype>
#include <iomanip>
using namespace std;

int main() {
	for (int i = 0; i < 4; i++) {
		cout << setw(10) << left << "dec";
		cout << setw(10) << left << "hexa";
		cout << setw(10) << left << "char";
	}
	cout << endl;
	for (int i = 0; i < 4; i++) {
		cout << setw(10) << left << "___";
		cout << setw(10) << left << "____";
		cout << setw(10) << left << "____";
	}
	cout << endl;
	
	for (int i = 0; i < 128; i++) {
		if (i != 0 &&(i % 4 == 0))
			cout << endl;
		cout << setw(10) << left << dec << i;
		cout << setw(10) << left << hex << i;
		if (isprint(i))
			cout << setw(10) << left << (char)i;
		else
			cout << setw(10) << left << '.';
	}
	cout << endl;
}