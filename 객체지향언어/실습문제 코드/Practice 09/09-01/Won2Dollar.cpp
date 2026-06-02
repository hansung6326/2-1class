#include <iostream>
#include <string>
using namespace std;

class Converter {
private:
	string srcUnit, destUnit;
protected:
	double ratio;
	virtual double convert(double src) { return 0.0; }
public:
	Converter(string sUnit, string dUnit, double ratio) {
		srcUnit = sUnit; destUnit = dUnit; this->ratio = ratio;
	}
	void run() {
		cout << srcUnit << "을 " << destUnit << "로 바꿉니다. ";
		cout << srcUnit << "을 입력하세요>>";
		double src;
		cin >> src;
		cout << convert(src) << destUnit << "입니다." << endl;
	}
};

class Won2Dollar : public Converter {
public:
	Won2Dollar(string srcUnit, string destUnit, int ratio);
	double convert(double src);
};

Won2Dollar::Won2Dollar(string srcUnit, string destUnit, int ratio)
: Converter(srcUnit, destUnit, ratio) { }

double Won2Dollar::convert(double src) {
	return src * (1.0 / ratio);
}

int main() {
	Won2Dollar w2d("원", "달러", 1450); // 1달러에 1450원
	w2d.run();
}