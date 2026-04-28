## Week5 1day report

---

---



### 컴파일 - gcc

* 목적 파일 만들기
  * gcc -c hello.c  -> hello.o

* 원하는 이름으로 실행 파일 만들기
  * gcc -o hello hello.c -> hello
  * ./hello

* 디버그 가능하고 원하는 이름으로 실행 파일 만들기
  * gcc -g -o hello hello.c -> hello

---



### 디버깅 - gdb

* run(r) : 디버깅 시작
* list(l) : 프로그램 코드 보여주기
* break(b) : 중단점 설정
* clear : 중단점 해제
* next(n) : 다음 명령 실행, 함수도 한번에 실행
* step(s) : 다음 명령 실행, 함수의 경우 함수 내부로 이동
* print(p) : 변수 값 출력
* cont(c) : 프로그램 실행 계속(다음 중단점까지 실행 후 멈춤)

---



### 구성도구 - make

* 프로그램 파일들 간의 종속성 관리

---



### C File I/O

* ##### FILE *infile, *outfile;

  * file을 다루기 위해 file을 가리키는 포인터 필요: 입력 파일용 infile, 출력 파일용 outfile

* ##### infile = fopen("file_name", "r"); outfile = fopen("file_name", "w");

  * 파일을 다루기 위해서는 사용하기 전에 open

* ##### r-fscanf(infile, "%d", &i); fscanf(infile, "lf", &d); fscanf(infile, "%s", string)

  * infile에서 값을 하나 읽어 val에 저장(공백으로 구분됨)
  * int i; double d; char string[32];

* ##### w- fprintf(outfile, "val = %d\n", i); ...

  * outfile에 출력

* ##### fclose(infile); fclose(outfile);

  * file 닫기