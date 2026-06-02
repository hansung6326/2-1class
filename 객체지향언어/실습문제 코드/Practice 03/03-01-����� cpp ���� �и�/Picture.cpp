#include "Picture.h"

Picture::Picture() {
	width = 5;
	height = 7;
	place = "모름";
}

// 위임 생성자를 사용하는 사례
//Picture::Picture() : Picture(5, 7, "모름") {
	// 위의 생성자 대신 이 생성자 사용할 수 있음
//}

Picture::Picture(int w, int h, string p) {
	width = w;
	height = h;
	place = p;
}