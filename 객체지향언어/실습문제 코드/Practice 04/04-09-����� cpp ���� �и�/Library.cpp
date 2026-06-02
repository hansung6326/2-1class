#include <iostream>
#include <string>
using namespace std;

#include "Book.h"
#include "Library.h"


Library::Library(string name, int size) {
	this->name = name;
	this->size = size;
	p = new Book[size]; // Book 객체 배열 동적 생성
	if (p == NULL) {
		cout << "동적 할당 실패" << endl;
		exit(0);
	}
}

Library::~Library() {
	if (p != NULL)
		delete[] p;
}

void Library::add(string title, int price) {
	if (next >= size) {
		cout << "도서관이 꽉 차서 " << title << "은 입고 불가능합니다." << endl;
		return; // 꽉찬상태
	}

	p[next].set(title, price); // Book 객체에 책이름과 가격 저장
	next++; // 다음 입고될 책의 정보를 저장할 위치
}

void Library::show() {
	cout << name << "에 입고된 책은 다음 " << next << "권입니다." << endl;
	for (int i = 0; i < next; i++) {
		cout << "[";
		cout << p[i].getTitle() << "]    ";
	}
	cout << endl;
}

Book* Library::mostExpensive() {
	if (next == 0) {
		return NULL;
	}
	int mostIndex = 0;
	for (int i = 0; i < next; i++) {
		if (p[i].getPrice() > p[mostIndex].getPrice()) {
			mostIndex = i;
		}
	}
	return &p[mostIndex]; // Book 객체 리턴
}