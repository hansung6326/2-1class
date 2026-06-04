#include <iostream>
using namespace std;

int main() {
	int ch;
	cout << "�Է��ϼ���>>";
	while ((ch = cin.get()) != EOF) { // Ű���忡�� ���� �б�
		if (ch == ';') // ���� ���ڰ� ';' �̸� �б� ����
			break;
		else
			cout.put(ch); // ���� ���� ���
	}
}