#include <iostream>
#include <string>
using namespace std;

#include "CoffeeVendingMachine.h"

void CoffeeVendingMachine::fill() { // 3개의 통을 모두 채움
	for (int i = 0; i < 3; i++)
		tong[i].fill(10);
	show();
}

void CoffeeVendingMachine::getEspresso() { // 에스프레소를 선택한 경우, 커피 1, 물 1 소모
	if (tong[0].getSize() > 0 && tong[1].getSize() > 0) {
		tong[0].consume(1); // 커피 감소
		tong[1].consume(1); // 물 감소
		cout << "에스프레소 드세요" << endl;
	}
	else {
		cout << "재료가 부족합니다" << endl;
	}
}

void CoffeeVendingMachine::getAmericano() { // 아메리카노를 선택한 경우,  커피 1, 물 2 소모
	if (tong[0].getSize() > 0 && tong[1].getSize() > 1) {
		tong[0].consume(1); // 커피 감소
		tong[1].consume(2); // 물 감소
		cout << "아메리카노 드세요" << endl;
	}
	else {
		cout << "재료가 부족합니다" << endl;
	}
}

void CoffeeVendingMachine::getSugarCoffee() { // 설탕커피를 선택한 경우, 커피 1, 물 2 소모, 설탕 1 소모
	if (tong[0].getSize() > 0 && tong[1].getSize() > 1 && tong[2].getSize() > 0) {
		tong[0].consume(1); // 커피 감소
		tong[1].consume(2); // 물 감소
		tong[2].consume(1); // 설탕 감소
		cout << "설탕커피 드세요" << endl;
	}
	else {
		cout << "재료가 부족합니다" << endl;
	}
}

void CoffeeVendingMachine::show() {
	cout << "커피 " << tong[0].getSize() << ", ";
	cout << "물 " << tong[1].getSize() << ", ";
	cout << "설탕 " << tong[2].getSize() << endl;
}

void CoffeeVendingMachine::run() {
	cout << "***** 커피자판기를 작동합니다. *****" << endl;
	
	while (true) {
		cout << "메뉴를 눌러주세요(1:에스프레소, 2:아메리카노, 3:설탕커피, 4:잔량보기, 5:채우기)>> ";
		int menu;
		cin >> menu;
		if (checkInputError()) // 메뉴에 숫자 대신 문자를 입력한 경우를 발견하고 처리 
			continue;
		switch (menu) {
			case 1: getEspresso(); break;
			case 2: getAmericano(); break;
			case 3: getSugarCoffee(); break;
			case 4: show(); break;
			case 5: fill(); break;
			default: cout << "잘못 누르셨습니다." << endl;
		}
	}
}

bool CoffeeVendingMachine::checkInputError() {
	if (cin.fail()) { // 정수대신 문자열이 입력되어 오류가 발생하는 경우 대처. 부록 C의 예제 C-1참고
		cin.clear();
		cin.ignore(100, '\n');
		cout << "입력 오류" << endl;
		return true; // 오류 있음
	}
	else
		return false; // 오류 없음
}