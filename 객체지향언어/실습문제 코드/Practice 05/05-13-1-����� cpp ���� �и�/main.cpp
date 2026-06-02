#include <iostream>
using namespace std;

#include "Collector.h"

double calcAvg(Collector s) {
	int sum = 0;
	for (int i = 0; i < s.getSize(); i++)
		sum += s.get(i);
	return ((double)sum) / s.getSize();
}

int main() {
	int temp[] = { 69, 70, 71, 72, 74 };
	Collector weight(4, temp);
	double avg = calcAvg(weight);
	weight.show();
	cout << "Æò±ÕÀº " << avg << endl;
}