#include "Histogram.h"

int main() {
	Histogram histo("You fill up my senses, like a night in a forest\n");
	histo.add("Like the mountains in springtime, like a walk in the rain\n");
	histo.addc('-');
	histo.add("Annie's Song by John Denver");
	histo.draw(); // 원문 텍스트와 히스토그램 모두 출력
}