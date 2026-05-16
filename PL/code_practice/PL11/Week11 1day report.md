### Week11 1day report

---

---



#### 서브 프로그램의 기초

* sub-program을 사용하는 이유
  * 프로그램 크기를 줄이기
  * 모듈화 프로그래밍 원리에 부합
  * Readability
  * 유지 보수 및 디버깅의 용이성
* sub-program의 다른 이름
  * Function
  * Procedure
  * Subroutine

* sub-program의 요소
  * 이름
  * 매개변수(인자) 리스트(parameter/argument list)
  * 몸체(body)
  * 참조 환경
* sub-program 호출(call)
  * 이름
  * 매개변수의 개수와 유형
  * 리턴 값의 개수와 유형
  * sub-program에서 수행되는 기능 : what not how -> 추상화
* 재귀 함수
  * 함수 자체를 이용하여 function을 구현
  * 이해가 쉬움
  * 단순
* 블록 구조
  * Algol
  * 블록 = 선언부 + 실행부
* 블록 특징
  * 지역 변수 선언
    * 블록 외부에서 접근 불가
    * 정보 은닉
  * 블록의 실행이 시작할 때 지역 변수에 대한 메모리 할당 -> 블록이 끝날 때 메모리 반환
  * 이름 있는 블록만 호출 가능
    * 블록 안에 있는 sub-program은 블록 외부에서 호출될 수 없음
    * 내부 블록은 외부 블록으로부터 감춰짐
* Pascal
  * 중첩 블록 허용
* C
  * 이름 없는 블록
  * 이름 있는 블록 = 함수
  * 이름 있는 중첩 블록은 없음
* PL/I, Ada/ C++...
* 정적 영역 규칙

---



#### 형식인자/실인자

* 실인자
  * sub-program에 전달되는 실제 값을 가지는 매개변수
  * result := gcd(a, b);
* 형식인자
  * 함수 선언에 표기된 매개 변수
  * function gcd(m, n:integer):integer;
* 형식 매개변수와 실 매개변수 간의 대응 = 위치에 의한 대응
* 기본값
  * C++, Ada
  * 실 매개변수의 갯수가 형식 매개변수의 갯수보다 적을 수 있음

---



#### 매개변수 전달 방법

* 값에 의한 호출
  * 실 매개변수의 값(r-value) -> 형식 매개변수
  * 실 매개변수와 형식 매개변수는 서로 다른 메모리 공간을 차지함
* 값과 결과에 의한 호출 (값과 결과 전달)
  * 값 전달 + 형식 매개변수의 값을 실 매개변수에 돌려줌
* 참조에 의한 호출
  * 실 매개변수의 주소(l-value) -> 형식 매개변수
  * 실 매개변수와 형식 매개변수는 서로 같은 메모리 공간을 차지함
* 이름에 의한 호출
  * 매개변수가 사용될 때마다, 필요한 실 매개변수의 l-value 또는 r-value가 계산되고 사용됨 
* Java에서의 매개변수 전달
  * 값 전달
    * 속성 변수
    * integer, real, character, boolean
  * 참조 전달
    * 참조 변수
    * object, string, array
* 형식 매개변수의 명시
  * 함수 원형 표시 = 함수 선언
  * 컴파일러에게 정보 제공
  * 함수 원형
    * Sub-program 이름
    * 매개변수 유형
    * 반환 값의 유형

---



#### 복잡한 데이터 전달 방법

* 배열 전달
  * 값 전달: copy cost
  * 참조 전달: 변경된 값을 반환하기에 적합
* 레코드 전달(struct in C)
  * 참조 전달을 많이 사용
* sub-program passing
  * Pascal, C, C++..
  * sub-program name + parameters
* 함수 중복
  * 같은 함수 이름 + 다른 매개변수 리스트
* Java
  * java method: class 내에서만 존재