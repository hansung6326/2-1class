#include <iostream>
using namespace std;

#include "Book.h"
#include "Library.h"

int main() {
	Library* lib = new Library("한국도서관", 10);
	lib->add("명품 C++", 30000);
	lib->add("라즈베리파이", 34000);
	lib->add("HTML5", 33000);
	lib->show();
	Book* b = lib->mostExpensive();
	cout << "가장 비싼 책:" << b->getTitle() << "," << b->getPrice() << endl;
	delete lib;
}
