#include <iostream>//입출력 기능을 위한 표준 헤더 파일
#include <string>//문자열 string을 사용하기 위해 포함
using namespace std; //std 이름공간에 선언된 모든 이름에 std를 생략함
//선언부
class Memo { //Memo 클래스 선언
	// 접근지정자가 private인 날짜와 내용을 저장하는 멤버 변수 선언
	string date, content; //날짜와 내용을 저장하는 문자열 변수
public: // public: 아래 모든 멤버를 public으로 접근 지정
	//매개변수가 있는 생성자를 선언, 날짜와 내용을 전달 받아 객체 초기화시킨다
	Memo(string dateInput, string contentInput);
	void show(); //메모의 날짜와 내용을 화면에 출력하는 함수 선언
	string getDate(); //저장된 날짜를 반환하는 함수 선언
	string getContent(); //저장된 내용을 반환하는 함수 선언
	//다른 Memo 객체와 날짜가 같은지 비교하는 함수 선언
	bool isSameDate(Memo b);
};
//구현부
Memo::Memo(string dateInput, string contentInput) { //매개변수가 있는 생성자 정의
	date = dateInput;//매개변수 dateInput 의 값을 date에 초기화
	content = contentInput; //매개변수 contentInput 의 값을 content에 초기화
}
void Memo::show() { //메모의 날짜와 내용을 출력하는 함수 정의
	//날짜와 쉼표 내용을 출력하고 한 줄 띄움
	cout << date << ", " << content << endl;
}
bool Memo::isSameDate(Memo b) { //날짜를 비교하는 함수 정의
	if (date == b.date) return true; //전달받은 객체 b의 날짜와 같으면 true를 반환
	else return false; //날짜가 다르면 false를 반환한다
}
string Memo::getDate() { //날짜를 반환하는 함수 정의
	return date; //멤버 변수 date 값을 반환함
}
string Memo::getContent() { //내용을 반환하는 함수 정의
	return content; //멤버 변수 content 값을 반환함
}
int main() {
	// 매개변수 생성자를 호출하여 각각의 Memo 객체 생성
	//날짜와 내용을 저장하는 객체 a 생성("1:20", "동계 프로그래밍 캠프")
	Memo a("1:20", "동계 프로그래밍 캠프");
	//날짜와 내용을 저장하는 객체 b 생성("2:20", "김경미 독일 송별회")
	Memo b("2:20", "김경미 독일 송별회");
	//날짜와 내용을 저장하는 객체 c 생성("2:21", "박채원 졸업식. 대학원 간대")
	Memo c("2:21", "박채원 졸업식. 대학원 간대");
	a.show(); //a 객체의 메모 정보 출력
	//a와 b의 날짜가 같으면 메시지 출력
	if (a.isSameDate(b)) cout << "같은 날입니다." << endl;
	//날짜가 다르면 메시지 출력 후 한 줄 띄움
	else cout << "다른 날입니다." << endl;
	// b 객체의 getDate()와 getContent() 함수를 호출하여 정보 출력
	cout << b.getDate() << "에 " << b.getContent() << endl;
}