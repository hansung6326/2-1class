#include <stdio.h>

#define MAX_DEGREE 101
// 1. MAX 매크로 함수 추가 (두 수 중 큰 값을 반환)
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

typedef struct {
    int degree;               // 다항식의 최고 차수
    float coef[MAX_DEGREE];   // 각 차수의 계수를 저장하는 배열
} polynomial;

// 두 다항식 A와 B를 더해 새로운 다항식 C를 반환하는 함수
polynomial poly_add1(polynomial A, polynomial B) {
    polynomial C;
    int Apos = 0, Bpos = 0, Cpos = 0;
    int degree_a = A.degree;  // A의 현재 비교 차수
    int degree_b = B.degree;  // B의 현재 비교 차수

    // 결과 다항식 C의 차수는 A와 B 중 큰 차수를 따름
    C.degree = MAX(A.degree, B.degree);

    // 두 다항식 중 하나라도 항이 남아있는 동안 반복
    while (Apos <= A.degree || Bpos <= B.degree) {
        if (degree_a > degree_b) {          // A의 차수가 더 높을 때
            C.coef[Cpos++] = A.coef[Apos++];
            degree_a--;
        }
        else if (degree_a == degree_b) {     // 두 차수가 같을 때 (계수 합산)
            C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
            degree_a--;
            degree_b--;
        }
        else {                              // B의 차수가 더 높을 때
            C.coef[Cpos++] = B.coef[Bpos++];
            degree_b--;
        }
    }
    return C;
}

// 다항식을 예쁘게 출력하는 함수
void print_poly(polynomial p) {
    // 최고 차수부터 1차항까지 출력
    for (int i = 0; i < p.degree; i++) {
        printf("%3.1fx^%d + ", p.coef[i], p.degree - i);
    }
    // 마지막 상수항 출력
    printf("%3.1f \n", p.coef[p.degree]);
}

int main(void) {
    // a = 3x^5 + 6x^4 + 0x^3 + 0x^2 + 0x^1 + 10
    polynomial a = { 5, {3, 6, 0, 0, 0, 10} };
    // b = 7x^4 + 0x^3 + 5x^2 + 0x^1 + 1
    polynomial b = { 4, {7, 0, 5, 0, 1} };
    polynomial c;

    printf("다항식 A: ");
    print_poly(a);
    printf("다항식 B: ");
    print_poly(b);

    c = poly_add1(a, b);

    printf("--------------------------------------\n");
    printf("결과 다항식 C: ");
    print_poly(c);

    return 0;
}