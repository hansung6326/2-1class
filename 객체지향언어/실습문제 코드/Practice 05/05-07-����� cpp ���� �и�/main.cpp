#include <iostream>
using namespace std;

#include "Power.h"

int main() {
	Power a(1, 2), b(10, 20), c(100, 200);
	c.add(a).add(b).add(Power(1000, 2000));
	c.show();
}