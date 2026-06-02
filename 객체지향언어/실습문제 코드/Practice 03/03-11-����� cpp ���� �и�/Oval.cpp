#include <iostream>
using namespace std;

#include "Oval.h"

Oval::~Oval() {
	cout << "Oval ¼Ò¸ê: " << getWidth() << "x" << getHeight() << endl;
}

void Oval::set(int w, int h) {
	width = w; height = h;
}

double Oval::area() {
	return 3.14 * ((double)width) / 2 * ((double)height) / 2;
}

void Oval::show() {
	cout << "Oval: " << "width=" << width << ", height=" << height << endl;
}
