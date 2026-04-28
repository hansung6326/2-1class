#include "Fitness.h" //Fitness 클래스 선언 헤더 포함
#include <iostream> //입출력 기능을 위한 표준 헤더 파일
#include <string> //문자열 처리를 위한 표준 헤더 파일
#include <cstdlib> // exit() 함수 사용을 위한 헤더 파일
using namespace std; //std 이름공간에 선언된 모든 이름에 std를 생략함
// 회원이 도착했을 때 성별에 맞게 인원수를 누적하는 함수 정의
Fitness& Fitness::arrive(string gender, int arriveCount) {
	if (gender == "남") //성별이 "남"인 경우
		men += arriveCount; // men 멤버 변수에 인원수 누적
	else if (gender == "여") // 성별이 "여"인 경우
		women += arriveCount; // women 멤버 변수에 인원수 누적
	else { // 잘못된 성별 입력시 에러 메시지 출력
		cout << "ERROR! arrive()에 잘못된 성별을 입력했습니다 (" << gender << ") "
			<< endl;
	}
	return *this; //현재 객체 자신의 참조를 반환
}
//특정 성별의 인원수를 참조 매개변수에 복사해주는 함수 정의
void Fitness::count(string gender, int& memberCount) {
	if (gender == "남") // 성별이 "남"인 경우
		memberCount = men; // memberCount에 men 값을 저장
	else if (gender == "여") // 성별이 "여"인 경우
		memberCount = women; //memberCount에 women 값을 저장
	else { // 잘못된 성별 입력 시 에러 메시지 출력 후 인원수를 0으로 초기화
		cout << "ERROR! count()에 잘못된 성별을 입력했습니다 (" << gender << ")"
			<< endl;
		memberCount = 0;
	}
}
// 특정 성별 멤버 변수의 참조를 반환하는 함수 정의
int& Fitness::at(string gender) {
	if (gender == "남") // 성별이 "남"인 경우
		return men; // men 변수 자체의 참조를 반환
	else if (gender == "여") //성별이 "여"인 경우
		return women;//women 변수 자체의 참조를 반환
	else {//잘못된 성별 입력 시 참조 반환이 불가능하므로 에러 메시지 출력 후 종료
		cout << "ERROR! at()에 잘못된 성별을 입력했습니다 (" << gender << ")" <<
			endl;
		exit(1); //프로그램 비정상 종료
	}
}
