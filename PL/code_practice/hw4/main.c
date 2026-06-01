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

