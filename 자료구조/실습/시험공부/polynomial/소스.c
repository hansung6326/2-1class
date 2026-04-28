#include <stdio.h>

typedef struct {
    int degree;
    float coef[100];
}polynomial;

polynomial poly_add1(polynomial A, polynomial B) {
    polynomial C;
    int Apos = 0, Bpos = 0, Cpos = 0;
    int degree_a = A.degree;
    int degree_b = B.degree;

    if (A.degree > B.degree)
        C.degree = A.degree;
    else
        C.degree = B.degree;

    while (Apos <= A.degree || Bpos <= B.degree) {
        if (degree_a > degree_b) {
            C.coef[Cpos++] = A.coef[Apos++];
            degree_a--;
        }
        else if (degree_a == degree_b) {
            C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
            degree_a--;
            degree_b--;
        }
        else {
            C.coef[Cpos++] = B.coef[Bpos++];
            degree_b--;
        }
    }
    return C;
}

void print_poly(polynomial p) {
    for (int i = 0; i < p.degree; i++) {
        printf("%3.1fx^%d + ", p.coef[i], p.degree - i);
    }
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