### Week10 1day report

---

---



#### 데이터 형

* 데이터 형 (= 자료형)
  * 가능한 값과 연산의 유형
  * 실 세계 모델링 능력 -> 데이터 조작의 편의성 좌우
* 기본 데이터 형
  * 정수, 실수, 문자, 불린...
* 복합 데이터 형 
  * 배열, 포인터, 레코드

---



#### 기본 데이터 형

* 정수형
  * signed, unsigned
  * short, long
  * overflow
  * Java
    * short: 16bit
    * integer: 32bit
    * long: 64bit
  * C: sizeof(int), sizeof(short), sizeof(long)
* 부동 소수점 실수형
  * IEEE 표준
    * N = (e, m)
    * 32bit, 64bit
  * float, double
* 나열/열거 형
  * 프로그래머가 정의
  * readability 향상
  * C: 정수형과 열거형을 혼합하여 사용할 수 있음

```
typedef enum {sun, mon, tue, wed, thur, fri, sat} day;
day date1
date1 = -1(O)  //enum에서 벗어난 의미없는 값이 나옴
date1 = sat + 1(O) //enum에서 벗어난 의미없는 값이 나옴
```

* 문자 형
  * ASCII code: 7bit
  * Unicode
    * 국제화
    * 2 byte(16bit)
    * English, Chinese, Japanese, Arabics,...
    * Java

* C 언어에서의 문자 형: 정수형의 부분 집합

```
char c;
int i;
c = 'A' + 2; //'C'
i = 'K';
c = i + 1;
printf("i = %c %d\n", i, i);
printf("c = %c %d\n", c, c);
```

* 불린 형
  * true, false
  * C 언어는 불린 형이 없음
    * 0 = false
    * 0 이외의 모든 값 = true

---



#### 자료형 변환

* i: 정수, x: 실수 (i = x % 3);
* 컴파일러의 형/타입 검사
  * 형 불일치 에러 // 에러가 나옴
  * 암묵적 형 변환: x -> integer ?

* 확장 변환

  * 데이터 값의 손실 없음
  * int -> float

* 축소 변환

  * 데이터 값의 손실 가능
  * float -> int, double -> float

* 프로그래밍 언어에서의 형 변환

  * cast 함수 : C, Java, Pascal // (int)x

  * 묵시적 자료 변환
    * integer + real -> real + real
    * 인터프리ㅇ터 언어 : 사용하기 쉬움, 융통성
    * 에러 가능성

---



#### 배열

* 동일한 형의 데엍 원소의 집합
  * 원소 접근 = 배열 이름 + 인덱스
* 배열 선언
  * 원소의 형
  * 인덱스 형 - 묵시적
  * 차원
  * 배열 인덱스의 시작/끝 - 묵시적
  * 배열의 초기값 (선택적)
* C, FORTRAN
  * 인덱스: 정수
  * 인덱스 범위를 명시하지 못함
* 유용한 배열의 사용 in C, C++
  * 배열 원소는 어느 유형이나 가능
  * EX : 구조체의 배열, 포인터의 배열, 객체의 배열
* 배열 초기화
  * FORTRAN 77 : DATA, 열 우선
* C : 행 우선
  * 초기 데이터 값이 배열의 크기 결정 : int list[] = {1, 2, 3, 4};
  * 행 우선 초기화 : int two[] [2] = {1, 2, 3, 4};
* C 언어에서의 문자열
  * 문자 배열
  * 마지막 원소 : '\0'
  * Example : char name[] = "computer";
  * name = &name[0];
* C 언어에서의 포인터 배열
  * 문자열을 가리키는 포인터 배열
  * char *name[] = {"Kim", "Lee", "Park", "Choi"};

---



#### 문자열

* 연속적 문자로 구성되는 데이터
* 특징
  * 기본 데이터 형 ? Character array ?
  * String 조작 명령 / 함수
* 선언
  * C, Pascal, Ada : 문자 배열
* 연산
  * A = B
  * C: strcpy(target, source)
* 접속
  * Pascal -> A:= A + B
  * Ada -> A := A & B
  * C : strcat(A, B)
* 비교
  * Pascal ->  =, < , >
  * C : strcmp(str1, str2)

---



#### 레코드

* 다른 유형의 데이터 원소의 집합
* 필드
  * 데이터 요소
  * 이름으로 접근
* COBOL
* 선언
  * record in C : struct
* 연산
  * 필드 선택 연산자 :   .

---



#### 포인터

* 다른 데이터를 가리키는 뎅터
* 유용성
  * 동적 데이터 구조: tree, linked list
  * 실행 전에 데이터 크기를 알 수 없는 경우
* 포인터 형을 지원하는 PL
  * 값은 다른 데이터의 주소 또는 NULL
  * 동적 할당
  * 역참조: 가리키는 것 (ip -> *ip)
* cast 연산
  * 기억장소를 할당하여 포인터에 대입(배정)할 때
* 배열 이름 = 포인터 상수 = 주소 값(배ㅕㅇㄹ의 시작 주소)
* 레코드 자신을 참조하는 레코드
  * tree, linked list...
  * heap
    * 동적 메모리 할당을 위한 기억장소 공간
    * 변수의 lifetime은 블록의 범위를 넘을 수 있음: ~ free(x)   ***
* 포인터 변수의 문제점
  * 허상 참조
    * 의미 없는 변수를 가리키는 포인터
    * free(), dispose()된 변수를 가리키는 포인터
  * 쓰레기
    * 가리키는 포인터가 없는 데이터
    * 데이터를 사용하지 못함: 접근 방법이 없으므로
    * free(), dispose()
* Java & Pointer
  * Java에는 포인터가 없음
  * 묵시적 포인터: object, array
  * 속성 변수
    * 변수의 값을 저장
    * integer, real, character, boolean
  * 참조 변수
    * 변수의 주소 값을 저장
    * object, string, array

---



#### 자료형 일치/ 호환성

* 이름 동치 //많은 프로그래밍 언어는 이름 동치를 사용
  * 데이터 타입의 이름이 같을 때
  * x := z(X)
* 구조적 동치
  * 데이터 타입의 구송 요소가 같을 때
  * x := z(O)
* 구조적 동치의 문제
  * 정의의 어려움: 이름 & 순서
* 프로그램에서 논리적 오류/에러를 찾는 것이 어려움