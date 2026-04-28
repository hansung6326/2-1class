#include <stdio.h>

int calcTriangleArea(int a, int b);
int calcRectangleArea(int a, int b);

int main()
{
	int a, b;
	int triArea, recArea;

	printf("정수 두 개를 입력하세요 ");
	scanf("%d %d", &a, &b);

	triArea = calcTriangleArea(a, b);
	recArea = calcRectangleArea(a, b);
	printf("삼각형 면적 = %d\n", triArea);
	printf("사각형 면적 = %d\n", recArea);

	return 0;
}
