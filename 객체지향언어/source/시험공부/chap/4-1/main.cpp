#include <iostream>
using namespace std;

int main() {
	double* tem;
	tem = new double[5];
	double sum = 0;
	cout << "온도 5개 입력>> ";
	for (int i = 0; i < 5; i++)
		cin >> tem[i];
	for (int i = 0; i < 5; i++)
		sum += tem[i];
	cout << "평균은 " << sum / 5 << endl;
	delete[] tem;
}