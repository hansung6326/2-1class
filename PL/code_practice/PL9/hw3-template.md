# 과제 3: 안태호



---



## Claude Code 결과



1. 코드의 문제점

```script
	main.c 코드에서 다음과 같은 문제점들이 있습니다:

## 주요 문제점

1. **필수 헤더 파일 누락**
   - `#include <stdio.h>` 없음 → `printf()` 사용 불가
   - `#include <string.h>` 없음 → `strcpy()` 사용 불가

2. **main 함수 없음**
   - 프로그램 실행을 위해 `int main()` 함수가 필요합니다
   - 11-20번 줄의 코드가 함수 밖의 전역 범위에 있습니다

3. **정의되지 않은 변수 사용**
   - 11번 줄: `i = A;` → `A`가 정의되지 않음
   - 12번 줄: `d = D;` → `D`가 정의되지 않음

4. **전역 범위에서 실행 문장**
   - 변수 선언은 가능하지만 `i = A;`, `strcpy()` 등은 함수 내에서만 실행 가능
   
```



2. 수정 코드

```c
#include <stdio.h>
#include <string.h>

#define N 100
#define PI 3.14
#define C 'K'
#define STR "HANSUNG"

int main() {
    int i;
    double d;
    char c;
    char str[256];
    
    i = N;        // A 대신 정의된 상수 사용
    d = PI;       // D 대신 정의된 상수 사용
    c = C;
    strcpy(str, STR);
    
    printf("i = %d\n", i);
    printf("d = %lf\n", d);
    printf("c = %c\n", c);
    printf("c = %d\n", c);
    printf("str = %s\n", str);
    printf("안태호\n");
    
    return 0;
}
```





3. 실행 결과

![image-20260503013833000](C:\Users\mcpe1\AppData\Roaming\Typora\typora-user-images\image-20260503013833000.png)



---



## Gemini CLI 결과





1. 코드의 문제점

```script
`main.c` 코드에는 다음과 같은 문제점들이 있습니다.

1.  **`main` 함수 누락**: C 프로그램은 실행 진입점인 `main` 함수가 반드시 필요합니다. 현재 코드에는 `main` 함수가 없습니다.
2.  **필수 헤더 파일 누락**:
    *   `printf` 함수를 사용하려면 `<stdio.h>` 헤더를 포함해야 합니다.
    *   `strcpy` 함수를 사용하려면 `<string.h>` 헤더를 포함해야 합니다.
3.  **정의되지 않은 변수 사용**: `i = A;` 및 `d = D;` 구문에서 `A`와 `D`가 어디에도 정의되어 있지 않아 컴파일 오류가 발생합니다.
4.  **매크로와 변수 이름 중복**: `#define C 'K'` 매크로와 `char c;` 변수가 같은 이름 `C`를 사용하고 있어 혼란을 줄 수 있습니다.
5.  **미사용 매크로**: `N`과 `PI` 매크로가 정의되어 있지만 코드 내에서 사용되지 않고 있습니다. (이는 오류는 아니지만 불필요한 코드일 수 있습니다.)
```



2. 수정 코드

```c
#include <stdio.h>
#include <string.h>

#define N 100
#define PI 3.14
#define C 'K'
#define STR "HANSUNG"

int main() {
    int i;
    double d;
    char c;
    char str[256];

    i = N;
    d = PI;
    c = C;
    strcpy(str, STR);

    printf("i = %d\n", i);
    printf("d = %lf\n", d);
    printf("c = %c\n", c);
    printf("c = %d\n", c);
    printf("str = %s\n",str);
    printf("안태호\n");

    return 0;
}

```





3. 실행 결과

![image-20260503014935467](C:\Users\mcpe1\AppData\Roaming\Typora\typora-user-images\image-20260503014935467.png)

