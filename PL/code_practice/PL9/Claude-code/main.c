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
