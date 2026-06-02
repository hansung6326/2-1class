#include <iostream>
using namespace std;

class BaseArray {
	int capacity; // 동적 할당된 메모리 용량
	int* mem;
protected:
	BaseArray(int capacity = 50) {
		this->capacity = capacity; mem = new int[capacity];
	}
	~BaseArray() { delete[] mem; }
	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
public:
	int getCapacity() { return capacity; }
};

class MyQueue : public BaseArray {
	int head, tail;
	int size; // 현재 큐 안에 있는 데이터의 개수
public:
	MyQueue(int capacity = 100);
	void enqueue(int n);
	int dequeue();
	//int capacity();
	int length();
};

MyQueue::MyQueue(int capacity) : BaseArray(capacity) {
	head = 0; // 삽입할 위치는 head
	tail = -1;  // tail+1 위치에서 꺼내기
	size = 0; // 초기 개수는 0
}

void MyQueue::enqueue(int n) {
	if (size == getCapacity())
		return; // queue full error
	put(head, n);
	head++;
	head = head % getCapacity();
	size++;
}

int MyQueue::dequeue() {
	if (size == 0)
		return -1; // queue empty error
	size--;
	tail++;
	tail = tail % getCapacity();
	return get(tail);
}

int MyQueue::length() {
	return size;
}

int main() {
	MyQueue m;
	int n;
	cout << "큐에 저장할 5개의 정수 입력>>";
	for (int i = 0; i < 5; i++) {
		cin >> n; // 정수 입력
		m.enqueue(n); // 큐에 정수 저장
	}
	cout << "큐 용량:" << m.getCapacity() << ", 큐 크기:" << m.length() << endl;
	cout << "큐의 모든 정수를 순서대로 제거하고 출력...";
	while (m.length() != 0)
		cout << m.dequeue() << ' '; // 큐의 맨 앞 정수를 제거하여 출력
	cout << endl;
	cout << "큐 용량:" << m.getCapacity() << ", 큐 크기:" << m.length() << endl;
}