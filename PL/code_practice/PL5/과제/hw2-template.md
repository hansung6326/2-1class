# 과제 2 - 안태호
---

1. main.c

```c
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
```

2. calcTri.c

```c
#include <stdio.h>

int calcTriangleArea(int a, int b)
{
        return (a*b)/2;
}
```

3. calcRec.c

```c
#include <stdio.h>

int calcRectangleArea(int a, int b)
{
        return a*b;
}
```



4. makefile

```script
calcArea: main.o calcTri.o calcRec.o
        gcc -o calcArea main.o calcTri.o calcRec.o
main.o: main.c
        gcc -c main.c
calcTri.o: calcTri.c
        gcc -c calcTri.c
calcRec.o: calcRec.c
        gcc -c calcRec.c
```



#### 실행 결과

![image-20260406203557087](C:\Users\mcpe1\AppData\Roaming\Typora\typora-user-images\image-20260406203557087.png)
