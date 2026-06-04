#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char str[80], bigStr[80] = "";
	int no = 1, bigNo = 1;


	cout << "최대 79글자까지 입력 가능합니다." << endl;
	while (true) {
		cout << no << ":\t";
		cin.getline(str, 80);
		if (cin.eof())
			break;
		if (cin.gcount() > strlen(bigStr) + 1) {
			strcpy(bigStr, str);
			bigNo = no;
		}
		no++;
	}
	cout << "가장 긴 문장은 라인 " << bigNo << ":" << bigStr << endl;
}