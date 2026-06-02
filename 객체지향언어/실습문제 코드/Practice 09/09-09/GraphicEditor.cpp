#include <iostream>
using namespace std;

#include "GraphicEditor.h"
#include "Shape.h"
#include "UI.h"
#include "Line.h"
#include "Circle.h"
#include "Rect.h"

GraphicEditor::GraphicEditor() {
	pStart = NULL;
	pLast = NULL;
}

GraphicEditor::~GraphicEditor() { // 소멸자
	// 현재 생성된 모든 객체를 삭제한다.
	Shape* p = pStart;
	while(p != NULL) {
		Shape* q = p->getNext(); // 다음 객체위치를 저장한다.
		delete p; // 현재 객체를 삭제한다.
		p = q; // 다음 객체를 가리킨다.
	}
}

void GraphicEditor::paint() {
	// 현재 생성된 모든 객체를 그린다.
	Shape* p = pStart;
	if(p == NULL) {
		UI::println("그려진 도형이 없습니다.");
		return;
	}
	int i=0;
	// 처음부터 끝까지 루프를 따라 그려진 도형을 그린다.
	while(p != NULL) {
		UI::print(i); // 인덱스 출력
		UI::print(": "); 
		p->paint(); // 도형 그리기
		p = p->getNext(); // 다음 도형을 가리킨다.
		i++;
	}
}

void GraphicEditor::run() { // 그래픽 에디터의 메인 함수
	UI::println("그래픽 에디터입니다.");
	while(true) {
		int menu = UI::getMainMenu();
		switch(menu) {
			case EDIT: // 삽입
				edit(); break;
			case REMOVE: // 삭제
				remove(); break;
			case PAINT: // 다시 그리기
				paint(); break;
			case EXIT: // 끝내기
				return;
			default:
				UI::println("명령 선택 오류");
		}
	}
}

void GraphicEditor::edit() {
	int shapeType = UI::getShapeType();
	switch(shapeType) {
		case LINE: // 라인
			add(new Line()); break;
		case CIRCLE: // 원
			add(new Circle()); break;
		case RECT: // 사각형
			add(new Rect()); break;
		default:
			UI::println("도형 선택 오류");
	}
}

void GraphicEditor::remove() {
	int shapeIndex = UI::getShapeIndex();
	remove(shapeIndex);
}

void GraphicEditor::remove(int shapeIndex) {
	// shapeIndex의 원소를 삭제한다.
	if(pLast == NULL) {
		UI::println("그려진 도형이 없습니다.");
		return;
	}
	int i=0;
	Shape* p = pStart;
	Shape* beforeP = pStart;
	while(i<shapeIndex) {
		i++;
		beforeP = p;
		p = p->getNext(); // 다음 객체를 가리킨다.
		if(p == NULL) { // shapeIndex가 도형의 개수보다 큼
			UI::println("도형의 인덱스가 개수보다 큽니다.");
			return;
		}
	}

	// p는 삭제할 도형에 대한 포인터
	Shape* pNext = beforeP->add(p->getNext());
	delete p;
	if(p == pStart) // 삭제한 도형이 첫 도형인 경우
		pStart = pNext;

	if(p == pLast) { // 삭제한 도형이 마지막 도형인 경우
		if(pStart == NULL) // 삭제한 도형이 처음이자 마지막인 경우
			pLast = NULL;
		else
			pLast = beforeP;	
	}
}

void GraphicEditor::add(Shape* p) {
	if(pStart == NULL) { // 처음으로 도형 객체를 생성하였을 때
		pStart = p;
		pLast = p;
		return;
	}
	else {
		pLast->add(p); // 도형 p를 마지막에 단다.
		pLast = p; // pLast가 마지막 도형으로 조정한다.
	}
}