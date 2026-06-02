#ifndef OVAL_H
#define OVAL_H

class Oval {
	int width, height;
public:
	Oval() { width = height = 1; }
	Oval(int w, int h) { width = w; height = h; }
	~Oval(); // ¼Ò¸êÀÚ
	int getWidth() { return width; }
	int getHeight() { return height; }
	void set(int w, int h);
	double area();
	void show();
};

#endif