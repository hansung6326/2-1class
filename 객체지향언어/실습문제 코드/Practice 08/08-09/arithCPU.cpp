#include <iostream>
using namespace std;

class PrimitiveCPU {
	int acc = 0; // CPU 내 저장 공간
protected:
	PrimitiveCPU(int val) { acc = val; } // 생성자
	void add(int b) { acc += b; } // acc에 b를 더하는 연산
	void load(int b) { acc = b; } // acc에 b를 저장하는 연산
	int read() { return acc; } // acc 값을 알려주는 연산
	void print() { cout << "acc=" << acc << endl; } // acc 값을 출력하는 연산
};

class ArithCPU : public PrimitiveCPU {
protected:
	void sub(int b); // 빼기 연산
	void mul(int b); // 곱하기 연산
	void div(int b); // 나누기 연산
	void execute(string cmd, int operand = -1); // 명령 cmd 처리
public:
	ArithCPU(int val); // 생성자
	void run(); // 사용자로부터 명령을 읽고 해석하여 
				// execute()를 호출하여 명령을 실행시키는 전체적인 기능
};

ArithCPU::ArithCPU(int val)
	: PrimitiveCPU(val)
{}

void ArithCPU::sub(int b) {
	add(-b);
}

void ArithCPU::mul(int b) {
	int tmp = read(); // 현재 acc 값 알아내기
	for(int i=0; i<b-1; i++)
		add(tmp); // acc += tmp
}

void ArithCPU::div(int b) {
	int count = 0;
	while (true) {
		add(-b); // acc -= b
		if (read() < 0)
			break;
		count++;
	}
	load(count);
}

void ArithCPU::run() {
	cout << "실행 시작합니다. 명령을 입력하세요..." << endl;
	while (true) {
		cout << ">>";
		string cmd;
		int operand;
		cin >> cmd;
		if (cmd == "stop")
			break;
		else if(cmd == "prt") 
			execute(cmd);
		else {
			cin >> operand;
			execute(cmd, operand);
		} 
	}
	cout << "실행을 종료합니다." << endl;
}


void ArithCPU::execute(string cmd, int operand) { // -1은 prt 명령을 위한 dummy 값
	if (cmd == "add") {
		add(operand);
	}
	else if (cmd == "sub") {
		sub(operand);
	}
	else if (cmd == "mul") {
		mul(operand);
	}
	else if (cmd == "div") {
		div(operand);
	}
	else if (cmd == "load") {
		load(operand);
	}
	else if (cmd == "prt") {
		print();
	}
	else {
		cout << "없는 명령입니다." << endl;
	}
}

int main() {
	ArithCPU myCPU(0);
	myCPU.run();
}