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

    // 기존의 정의되지 않은 A, D를 매크로 정의된 N, PI로 수정
    i = N;
    d = PI;
    c = C;
    strcpy(str, STR);

    printf("i = %d\n", i);
    printf("d = %lf\n", d);
    printf("c = %c\n", c);
    printf("c = %d\n", c); // 문자의 ASCII 코드값 출력
    printf("str = %s\n", str);

    return 0;
}
