#ifndef VECTOR_H
#define VECTOR_H

class Vector {
	int* mem; // 생성자에서 배열 할당. 할당받은 배열의 주소 저장
	int size; // 생성자에서 할당받은 배열의 크기
public:
	Vector(int size, int val); // mem에 size 크기의 동적 배열을 할당하고 val로 초기화
	Vector(); // mem에 5 크기의 동적 배열을 할당하고 0으로 초기화
	~Vector();
	void show(); // 동적 배열 mem을 모두 출력
	void show(int n); // 동적 배열 mem에서 앞 부분 n 개만 출력
}; 

#endif
