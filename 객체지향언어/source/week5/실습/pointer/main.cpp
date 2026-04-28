#include <iostream>
using namespace std;

class Circle { //���� 4-8
	int radius;
public:
	Circle() { radius = 1; } // this->radius = 1; ������ �����Ϸ��� ���ؼ� this-> ������
	Circle(int radius) { this->radius = radius; } //this->radius�� Circle�� ������� radius, radius�� �ŰԺ���
	double getArea(){ return 3.14 * radius * radius; }
	void setRadius(int r) { radius = r; }
};

class CircleManager { 
	int n;
	Circle* p;
	void input();
	void show();
	void decide();
public:
	void run();
};

void CircleManager::decide() {
	cout << "������ 100���� 200������ �� " << endl;
	for (int i = 0; i < n; i++) {
		double d = p[i].getArea();
		if (d >= 100 && d <= 200)
			cout << d << "\t";
	}
	cout << endl;
}

void CircleManager::show() {
	for (int i = 0; i < n; i++) {
		cout << p[i].getArea() << "\t";
	}
	cout << endl;
}

void CircleManager::input() {
	cout << "�����ϰ��� �ϴ� ���� ����? ";
	cin >> n;
	p = new Circle[n];
	if (p == NULL) {
		exit(0);
	}

	for (int i = 0; i < n; i++) {
		cout << "��" << (i + 1) << ": ";
		int radius;
		cin >> radius;
		p[i].setRadius(radius);
	}
}

void CircleManager::run() {
	input();
	show();
	decide();
}

int main() { //���� 4-8
	CircleManager* pMan = new CircleManager();
	pMan->run();
	delete pMan;
}

//class Circle {
//	int radius;
//public:
//	Circle() { radius = 1; }
//	Circle(int r) { radius = r; }
//	double getArea(){ return 3.14 * radius * radius; }
//};
//
//void print(Circle* p) {
//	cout << p->getArea() << endl;
//}

//int main() { //���� �޸� �Ҵ�
//	int n;
//	int* p;
//	cout << "� �Է�>> ";
//	cin >> n;
//	p = new int[n];
//	if (p == NULL) {
//		cout << "�Ҵ� ����";
//		return 0; //exit(0);
//	}
//	for (int i = 0; i < n; i++) {
//		cout << (i + 1) << "��° ����: ";
//		cin >> p[i];
//	}
//
//	int sum = 0;
//	for (int i = 0; i < n; i++) {
//		sum += p[i];
//	}
//
//	cout << sum / n;
//
//	delete[] p;
//
//}

//int main() { //��ü �迭
//	Circle circleArray[3] = {Circle(3), Circle(5), Circle() };
//	for (int i = 0; i < 3; i++) {
//		cout << circleArray[i].getArea() << "\n";
//	}
//
//	Circle* p = circleArray; // = &circleArray[0], �����ʹ� �ּ�, �ּҴ� ����, p���� �������� ����ִ�
//	for (int i = 0; i < 3; i++) {
//		cout << p->getArea() << "\n";
//		p++;
//	}
//
//}

//int main() {
//	Circle donut, pizza(30);
//	Circle* p;
//	p = &donut;
//	cout << donut.getArea() << ", " << p->getArea() << endl;
//	cout << (*p).getArea() << ", " << (&donut)->getArea() << endl;
//	print(p);
//	print(&pizza);
//}