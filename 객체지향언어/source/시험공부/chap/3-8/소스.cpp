#include <iostream>
using namespace std;

int main() {
	Calculator jane;
	jane.loop();
	cout << "연산 결과는 " << jane.getValue() << endl;
}