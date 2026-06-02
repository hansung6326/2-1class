#ifndef COLLECTOR_H
#define COLLECTOR_H

class Collector {
	int* p; // 데이터를 저장하는 동적 배열
	int size = 0; // 데이터 개수
public:
	Collector(int size, int values[]); // 생성자
	Collector(const Collector& src); // 복사 생성자
	~Collector(); // 소멸자
	void show(); // 데이터 개수와 value[]를 화면에 출력
	int getSize() { return size; }
	int get(int index) { return p[index]; }
};

#endif


