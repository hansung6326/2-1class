#include <stdio.h>

void calcData(int score1[], int score2[], float average[], int count){
	for(int i = 0; i < count; i++){
		average[i] = (score1[i] + score2[i]) / 2.0;
	}
}
