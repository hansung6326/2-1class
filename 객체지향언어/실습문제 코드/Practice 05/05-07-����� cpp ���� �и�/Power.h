#ifndef POWER_H
#define POWER_H

class Power {
	int kick, punch;
public:
	Power(int kick, int punch); // 생성자
	Power& add(Power p); // 현재 파워에 매개변수 p의 파워를 더한다.
	void show(); // kick과 punch를 출력한다.
};

#endif
