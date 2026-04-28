#include <iostream>
using namespace std;

class Container {
	int* p;
	int size;
public:
	Container(int size);
	~Container();
	void read();
	void write();
	void rotate();
	double avg();
};
Container::Container(int size) {
	this->size = size;
	p = new int[size];
}
Container::~Container() {
	delete[] p;
}
void Container::read() {
	cout << "정수 10개 입력>>";
	for (int i = 0; i < size; i++) {
		cin >> p[i];
	}
}
void Container::write() {
	for (int i = 0; i < size; i++) {
		cout << p[i] << " ";
	}
	cout << endl;
}
void Container::rotate() {
	int last = p[size - 1];
	for (int i = size - 1; i > 0; i++) {
		p[i] = p[i - 1];
	}
	p[0] = last;
}
double Container::avg() {
	double sum = 0;
	for (int i = 0; i < size; i++)
		sum += p[i];
	return sum / size;
}

int main() {
	Container c(10);
	c.read();
	c.write();
	c.rotate();
	c.write();
	cout << "평균은 " << c.avg() << endl;

	return 0;

}