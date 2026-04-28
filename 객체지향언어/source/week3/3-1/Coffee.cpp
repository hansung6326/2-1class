#include <iostream> //입출력 기능을 위한 표준 헤더 파일
using namespace std; //std 이름공간에 선언된 모든 이름에 std를 생략함
//선언부
class Coffee { // Coffee 클래스 선언
// 접근지정자가 private인 커피, 설탕, 우유, 물을 저장하는 멤버 변수 선언
int coffee, sugar, milk, water; //coffee, sugar, milk, water의 양
public: // public: 아래 모든 멤버를 public으로 접근 지정
Coffee(); //기본 생성자를 선언한다, 매개변수 없이 객체 생성 시 호출
//매개변수가 있는 생성자를 선언, 특정 값을 전달받아서 객체를 초기화시킴
Coffee(int coffeeAmount, int sugarAmount, int milkAmount, int waterAmount);
void show(); //커피, 설탕, 우유, 물을 사용한 만큼 *을 출력하는 함수 선언
};
//구현부
Coffee::Coffee() { //기본 생성자 정의(커피 10, 설탕 0, 우유 0, 물 0)
coffee = 10; //커피를 10으로 초기화
sugar = milk = water = 0;//설탕,우유, 물을 0으로 초기화
}
//매개변수가 있는 생성자 정의
Coffee::Coffee(int coffeeAmount, int sugarAmount, int milkAmount, int waterAmount) {
coffee = coffeeAmount; //매개변수 coffeeAmount의 값을 coffee에 초기화
sugar = sugarAmount;//매개변수 sugarAmount의 값을 sugar에 초기화
milk = milkAmount;//매개변수 milkAmount의 값을 milk에 초기화
water = waterAmount;//매개변수 waterAmount의 값을 water에 초기화
}
//커피, 설탕, 우유, 물을 얼마나 사용했는지 출력하는 함수를 정의
void Coffee::show() { //커피 사용량 출력
cout << "coffee ";
for (int i = 0; i < coffee; i++) { //coffee의 수만큼 *을 반복 출력함
cout << "*";
}
cout << endl; //한 줄 띄움
cout << "sugar ";//설탕 사용량 출력
for (int i = 0; i < sugar; i++) {//sugar의 수만큼 *을 반복 출력함
cout << "*";
}
cout << endl;
cout << "milk ";//우유 사용량 출력
for (int i = 0; i < milk; i++) {//milk의 수만큼 *을 반복 출력함
cout << "*";
}
cout << endl;
cout << "water ";//물 사용량 출력
for (int i = 0; i < water; i++) {//water의 수만큼 *을 반복 출력함
cout << "*";
}
cout << endl;
}
int main() {
// 기본 생성자 호출하여 expresso 객체 생성(커피 10, 설탕 0, 우유 0, 물 0)
Coffee espresso;
//매개변수 생성자를 호출하여 americano 객체 생성(커피 5, 설탕 0, 우유 0, 물 10)
Coffee americano(5, 0, 0, 10);
//매개변수 생성자를 호출하여 cappucchino 객체 생성(커피 5, 설탕 1, 우유 5, 물 2)
Coffee cappucchino(5, 1, 5, 2);
// 매개변수 생성자를 호출하여 mySweet 객체 생성(커피 3, 설탕 7, 우유 5, 물 5)
Coffee mySweet(3, 7, 5, 5);
espresso.show(); //espresso 객체의 재료 사용량 출력
cout << endl;
mySweet.show();//mySweet 객체의 재료 사용량 출력
}