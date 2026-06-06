#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin("c:\\temp\\test.txt");
	if(!fin) {
		cout << "���� ����" << endl;
		cout << "��θ��� ������ ������ �ִ��� Ȯ���ϼ���" << endl;
		return 0;
	}
	int ch;
	while((ch=fin.get()) != EOF) {
		cout.put(ch);
	}

	fin.close();
}