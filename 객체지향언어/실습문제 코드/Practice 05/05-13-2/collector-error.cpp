/* 이 프로그램이 실행 오류가 발생하고 비정상 종료하는 이유는
소멸자에 문제가 있는 것이 아니라, 클래스에 복사 생성자가 작성되어 있지 않기 때문이다.
복사 생성자가 만들어져 있지 않을 때 컴파일러는 디폴트 복사 생성자를 
만들어 클래스에 삽입한다. 컴파일러에 의해 자동 생성되는 디폴트 복사 생성자는 
멤버 변수들을 1:1로 복사하는 단순한 코드로 구성된다.
그러므로 여기서 컴파일러에 의해 묵시적으로 만들어지는 Collector 클래스의 
디폴트 복사 생성자는 다음과 같다.

Collector::Collector(const Collector& src) {
	size = src.size;
	p = src.p
}

이 문제에서는 디폴트 복사 생성자가 문제를 일으키는 원인이다.
이제 구체적으로 설명하면, main()함수에서 calcAvg(weight);를 호출하면,
calcAvg(Collector s)가 실행될 때 매개변수인 객체 s가 생성되는데,
이때 Collector의 복사 생성자를 호출하여 원본 weight를 복사하여 s가 생성한다.
그런데 현재 디폴트 복사 생성자는 weight의 size를 s의 size에, 
weight의 p를 s의 p에 단순 복사하므로 s는 weight의 p를 공유하게 된다.
calcAvg() 함수가 리턴하면 객체 s가 사라지는데 이때 객체 s의 소멸자가 호출되고
소멸자는 객체 s의 p에 할당된 동적 메모리를 반환해버린다.
여기까지는 문제가 드러나지 않지만,
이제 main() 함수가 종료하면 weight가 소멸되고 weight 객체의 소멸자가 실행될 때
자신이 할당받은 메모리를 반환하게 되면, 이미 s가 반환한 것으로 또 반환하게 되므로
시스템은 남의 메모리를 침범한 것으로 판단하여 실행 오류를 발생시키게 된다.
이 문제의 해결책은 Collector의 복사생성자를 제대로 작성하는 것이다.
문항 (3)에서 문제의 해결책을 확인해보라.
*/

#include <iostream>
using namespace std;

class Collector {
	int* p; // 데이터를 저장하는 동적 배열
	int size = 0; // 데이터 개수
public:
	Collector(int size, int values[]); // 생성자
	~Collector() { // 소멸자
		delete[] p; // 동적 할당받은 메모리 반환
	}
	void show(); // 데이터 개수와 value[]를 화면에 출력
	int getSize() { return size; }
	int get(int index) { return p[index]; }
};

Collector::Collector(int size, int values[]) {
	this->size = size;
	p = new int[size];
	for (int i = 0; i < size; i++)
		p[i] = values[i];
}

void Collector::show() {
	cout << "데이터 수 " << size << ": ";
	for (int i = 0; i < size; i++)
		cout << p[i] << ' ';
	cout << endl;
}

double calcAvg(Collector s) {
	int sum = 0;
	for (int i = 0; i < s.getSize(); i++)
		sum += s.get(i);
	return ((double)sum) / s.getSize();
}

int main() {
	int temp[] = { 69, 70, 71, 72, 74 };
	Collector weight(4, temp);
	double avg = calcAvg(weight);
	weight.show();
	cout << "평균은 " << avg << endl;
}