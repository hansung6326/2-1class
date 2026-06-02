#include <iostream>
using namespace std;

#include "Power.h"

Power::Power(int kick, int punch) {
	this->kick = kick; this->punch = punch;
}

Power& Power::add(Power p) {
	kick += p.kick;
	punch += p.punch;
	return *this;
}

void Power::show() {
	cout << "kick=" << kick << ", punch=" << punch << endl;
}