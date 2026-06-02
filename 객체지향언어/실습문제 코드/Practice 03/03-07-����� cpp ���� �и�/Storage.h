#ifndef STORAGE_H
#define STORAGE_H

class Storage {
	double data[10] = { 0 };
	int next = 0;
public:
	Storage();
	void put(double n);
	double getAvg();
	void dump();
};

#endif
