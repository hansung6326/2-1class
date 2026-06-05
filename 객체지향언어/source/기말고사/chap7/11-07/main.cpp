#include <iostream>
#include <string>
using namespace std;

class Phone {
	string name, telnum, address;
public:
	Phone(string name = "", string telnum = "", string address = "") {
		this->name = name;
		this->telnum = telnum;
		this->address = address;
	}
	friend istream& operator >>(istream& ist, Phone& p);
	friend ostream& operator <<(ostream& ost, Phone p);
};

istream& operator >>(istream& ist, Phone& p) {
	cout << "이름:";
	getline(ist, p.name);
	cout << "전화번호:";
	getline(ist, p.telnum);
	cout << "주소:";
	getline(ist, p.address);
	return ist;
}

ostream& operator <<(ostream& ost, Phone p) {
	ost << "(" << p.name << "," << p.telnum << "," << p.address << ")" << endl;
	return ost;
}

int main() {
	Phone queen, prince;
	cin >> queen >> prince;
	cout << queen << endl << prince << endl;

}