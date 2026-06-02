#ifndef CONTAINER_H
#define CONTAINER_H

class Container {
	int* p; // 정수 배열에 대한 포인터
	int size; // 정수 배열의 크기
public:
	Container(int size); //  생성자
	~Container(); // 소멸자
	void read(); // 배열의 크기만큼 정수를 키보드로부터 읽어들이기
	void write(); // 배열에 저장된 전체 정수 출력
	void rotate(); // 배열의 원소들 회전
	double avg(); // 평균 출력
};

#endif
