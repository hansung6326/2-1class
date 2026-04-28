#include <iostream>
using namespace std;

class Calculator {
	int value;

public:
	void loop();
};

int main() {
	Calculator jane;
	jane.loop();
	cout << "연산 결과는 " << jane.getValue() < endl;
}