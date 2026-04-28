#ifndef FITNESS_H //FITNESS_H가 정의되어 있지 않다면
#define FITNESS_H //FITNESS_H를 정의함(중복 포함 방지)
#include <string> // 문자열 처리를 위한 표준 헤더 파일
class Fitness { // Fitness 클래스 선언
	int men = 0;//남자 회원 수를 저장하고 0으로 초기화하는 멤버 변수
	int women = 0;// 여자 회원 수를 저장하고 0으로 초기화하는 멤버 변수
public: // 아래 멤버들을 public으로 접근 지정
	// 자신을 참조로 반환하여 연쇄 호출이 가능한 arrive 함수 선언
	Fitness& arrive(std::string gender, int arriveCount);
	// 특정 성별의 회원 수를 참조 매개변수로 전달하는 함수 선언
	void count(std::string gender, int& memberCount);
	// 특정 성별 멤버 변수의 참조를 직접 반환하여 수정 가능한 함수 선언
	int& at(std::string gender);
};
#endif //조건부 컴파일 종료