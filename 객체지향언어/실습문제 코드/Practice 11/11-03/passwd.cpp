#include <iostream>
#include <string>
using namespace std;

int main() {
	string cmd;
	while (true) {
		cout << "�����Ϸ��� ��ȣ�� �Է��ϼ���>>";
		getline(cin,cmd); // ũ�� ���Ѿ��� ���� �Է�
		if (cmd =="see you later") {
			cout << "���α׷��� �����մϴ�....";
			return 0;
		}
	}
}