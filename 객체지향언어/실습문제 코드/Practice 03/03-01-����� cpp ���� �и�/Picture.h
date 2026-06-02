#ifndef PICTURE_H
#define PICTURE_H

#include <string>
using namespace std;

class Picture {
	int width;
	int height;
	string place;
public:
	Picture();
	Picture(int width, int height, string place);
	int getWidth() { return width; }
	int getHeight() { return height; }
	string getPlace() { return place; }
};

#endif
