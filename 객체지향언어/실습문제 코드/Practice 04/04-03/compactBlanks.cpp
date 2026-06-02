#include <iostream>
#include <string>
using namespace std;

int main() {
	string line; // �Է¹޾� ������ ��Ʈ�� ��ü
	string dest; // �����ϴ� ���ڿ��� ������ ��Ʈ�� ��ü

	cout << "�ؽ�Ʈ �Է�>>";
	getline(cin, line, '\n'); // <Enter> Ű�� �Էµ� ������ ���ڸ� �а� �� �ٿ� �ؼ�. 
						// <Enter> Ű�������ϰ� �� ���� �Է�
	int index = 0;
	while (true) {
		if (index >= line.size()) // �ؽ�Ʈ ���̺��� ũ�� ����
			break;

		if (line[index] == ' ') { // ' ' ���� �̸�
			dest.append(1, line[index]); // ' ' ���� ����
			index++; // ���� ���ڷ� �̵�

			while (line[index] == ' ') // ���̾� ������ ' ' ���� ��� ���� 
				index++; 
		}
		else { // ' ' ���ڰ� �ƴϸ�
			dest.append(1, line[index]); // ���� ����
			index++; // ���� ���ڷ� �̵�
		}
	}
	cout << dest;
}