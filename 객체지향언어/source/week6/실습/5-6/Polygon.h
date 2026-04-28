#ifndef POLYGON_H //POLYGON_H가 정의되어 있지 않다면
#define POLYGON_H //POLYGON_H를 정의함(중복 포함 방지)
class Polygon { //Polygon 클래스 선언
	int size = 0; //다각형 점의 개수를 저장하는 멤버 변수
	int* xList, * yList; //x좌표와 y좌표 배열을 가리킬 포인터 변수 선언
public: //아래 멤버들을 public으로 접근 지정
	Polygon(int size); //매개변수가 있는 생성자 선언, 동적 배열 할당에 사용
	~Polygon();//소멸자 선언, 객체 소멸 시 동적 메모리 해제
	void read();//사용자로부터 좌표 값을 입력받는 함수 선언
	bool get(int n, int& x, int& y);//n번째 점의 좌표를 참조 매개변수로 반환하는 함수 선언
};
#endif // 조건부 컴파일 종료