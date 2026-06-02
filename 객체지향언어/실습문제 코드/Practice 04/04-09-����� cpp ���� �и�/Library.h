#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
using namespace std;

class Book; // 혹은 #include "Book.h"

class Library {
	string name; // 도서관 이름
	Book* p; // 동적 할당받을 Book [] 배열에 대한 포인터
	int size; // 동적 할당받은 Book [] 배열의 크기
	int next = 0; // p[] 배열에 다음 삽입될 위치
public:
	Library(string name, int size); // 생성자
	~Library(); // 소멸자
	void add(string name, int price); // 책 한권 입고하여 정보 저장
	void show(); // 도서관에 들어 있는 모든 책 출력
	Book* mostExpensive(); // 가장 비싼 Book 객체에 대한 포인터 리턴. 책이 없으면 NULL 리턴
};

#endif