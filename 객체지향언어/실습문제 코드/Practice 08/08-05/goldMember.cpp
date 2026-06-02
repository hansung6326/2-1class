#include <iostream>
using namespace std;

class Member {
protected:
	string name; // ȸ�� ��
	int point = 0; // �ʱ� ����Ʈ 0
	int ratio; // ����Ʈ ������. ����: %
public:
	Member(string name, int ratio = 1);
	void earn(int pay); // pay �ݾ��� ����� ��� ����Ʈ ����
	int getPoint(); // ���� ����Ʈ ����
	void show(); // �̸��� ����Ʈ ���
};

Member::Member(string name, int ratio) {
	this->name = name; this->ratio = ratio;
}

void Member::earn(int pay) { // pay ��ŭ ������ ��� ����Ʈ ����
	point += pay * ratio / 100; // ratio ������ ����Ʈ ����
}

int Member::getPoint() {
	return point;
}

void Member::show() { 
	cout << name << "�� ����Ʈ " << point << endl; 
}

class GoldMember : public Member {
public:
	GoldMember(string name) : Member(name, 3) {}
	void earn(int pay) { // pay ��ŭ ������ ��� ����Ʈ ����
		int goldRatio = 0;
		if(pay < 100000) goldRatio = ratio;
		if(pay >= 100000 && pay < 200000) goldRatio = 4; // goldRatio�� 4
		else if(pay >= 200000) goldRatio = 5; // goldRatio�� 5
		point += pay * goldRatio / 100; // ratio ������ ����Ʈ ����
	}
};


int main() {
	Member a("Ȳ����");
	GoldMember b("���繮"); 
	
	for (int i = 0; i < 5; i++) {
		cout << (i + 1) << " �̸��� �����>>";
		string name; int pay;
		cin >> name >> pay;
		if (name == "Ȳ����") a.earn(pay);
		else if (name == "���繮") b.earn(pay);
		else i--; // ���� ȸ���̹Ƿ� �ٽ� �Է�
	}
	a.show(); b.show();
}