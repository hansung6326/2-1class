#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
	string title; // 책 제목
	int price; // 책 가격
public:
	Book() { title = ""; price = 0; }
	void set(string title, int price) { this->title = title; this->price = price; }
	string getTitle() { return title; }
	int getPrice() { return price; }
};

#endif