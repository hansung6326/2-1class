#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1;  }
	Circle(int r) { radius = r;  }
	~Circle() {  }
	void setRadius(int r) { radius = r; }
	double getArea();
};

double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	int n;
	cout << "생성하고자 하는 원의 개수? ";
	cin >> n;

	Circle* pArray = new Circle[n];
	if (!pArray) {
		cout << "메모리 부족";
		return 0;
	}

	for (int i = 0; i < n; i++) {
		cout << "원 " << i + 1 << "의 반지름? ";
		int r;
		cin >> r;
		pArray[i].setRadius(r);
	}
		
	for (int i = 0; i < n; i++) {
		cout << pArray[i].getArea() << " ";
	}
	cout << endl;

	int count = 0;
	for (int i = 0; i < n; i++) {
		double area = pArray[i].getArea();
		if (area >= 100 && area <= 200)
			count++;
	}
	cout << "면적이 100에서 200사이인 원의 개수는 " << count << endl;

	delete[] pArray;

}