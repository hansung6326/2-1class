# HW-4, 안태호



####  1. main.c

```c
#include <stdio.h>

int readData(int score1[], int score2[], const char* filename);
void calcData(int score1[], int score2[], float average[], int count);
void outputData(int score1[], int score2[], float average[], int count, const char* filename);

int main(void)
{
        int score1[100], score2[100], count;
        float average[100];

        count = readData(score1, score2, "points.txt");

        calcData(score1, score2, average, count);
        outputData(score1, score2, average, count, "grade.txt");

        return 0;
}

```



#### 2. input.c

```c
#include <stdio.h>

int readData(int score1[], int score2[], const char* filename)
{
        int count = 0;

        FILE* fp = fopen(filename, "r");
        if(fp == NULL){
                perror("파일 열기 실패");
                return -1;
        }

        while(fscanf(fp, "%d %d", &score1[count], &score2[count]) == 2){
                count++;
        }

        fclose(fp);
        return count;
}

```



#### 3. calc.c

```c
#include <stdio.h>

void calcData(int score1[], int score2[], float average[], int count){
        for(int i = 0; i < count; i++){
                average[i] = (score1[i] + score2[i]) / 2.0;
        }
}

```



#### 4. output.c

```c
#include <stdio.h>

void outputData(int score1[], int score2[], float average[], int count, const char *filename)
{
        FILE* fp = fopen(filename, "w");
        if(fp == NULL){
                perror("파일 열기 실패");
                return;
        }

        for(int i = 0; i < count; i++){
                printf("%d %d %.1f\n", score1[i], score2[i], average[i]);
                fprintf(fp, "%d %d %.1f\n", score1[i], score2[i], average[i]);
        }
        fclose(fp);
}

```



#### 5. makefile

```c
hw4: main.o input.o calc.o output.o
        gcc -o hw4 main.o input.o calc.o output.o
main.o: main.c
        gcc -c main.c
input.o: input.c
        gcc -c input.c
calc.o: calc.c
        gcc -c calc.c
output.o: output.c
        gcc -c output.c

```



#### 6. LINUX에서의 실행 화면 - 자신의 실행 화면 캡처 !!!

- 폴더 위치: 자신의 폴더 안에서 **hw4 폴더**를 생성하는 것임
- 실행파일 이름: **hw4**
- **명령 실행 순서: clear -> pwd -> ls -l -> ./실행파일이름**

![image-20260530164711890](C:\Users\mcpe1\AppData\Roaming\Typora\typora-user-images\image-20260530164711890.png)



![image-20260530164736386](C:\Users\mcpe1\AppData\Roaming\Typora\typora-user-images\image-20260530164736386.png)











