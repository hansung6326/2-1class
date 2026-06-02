#include <iostream>
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

class Library {
	string name; // 도서관 이름
	Book* p; // 동적 할당받을 Book [] 배열에 대한 포인터
	int size; // 동적 할당받은 Book [] 배열의 크기
	int next=0; // p[] 배열에 다음 삽입될 위치
public:
	Library(string name, int size); // 생성자
	~Library(); // 소멸자
	void add(string name, int price); // 책 한권 입고하여 정보 저장
	void show(); // 도서관에 들어 있는 모든 책 출력
	Book* mostExpensive(); // 가장 비싼 Book 객체에 대한 포인터 리턴. 책이 없으면 NULL 리턴
};

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
	if(p != NULL)
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

int main() {
	Library *lib = new Library("한국도서관", 2);
	lib->add("명품 C++", 30000);
	lib->add("라즈베리파이", 34000);
	lib->add("HTML5", 33000);
	lib->show();
	Book* b = lib->mostExpensive();
	cout << "가장 비싼 책:" << b->getTitle() << "," << b->getPrice() << endl;
	delete lib;
}
