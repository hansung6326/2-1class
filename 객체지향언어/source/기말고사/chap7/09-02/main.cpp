#include <iostream>
using namespace std;

class Converter {
private:
	string srcUnit, destUnit;
protected:
	double ratio;
	virtual double convert(double src) {
		return 0.0;
	}
public:
	Converter(string sUnit, string dUnit, double ratio) {
		srcUnit = sUnit;
		destUnit = dUnit;
		this->ratio = ratio;
	}
	void run() {
		cout << srcUnit << "을  " << destUnit << "로 바꿉니다. ";
		cout << srcUnit << "을 입력하세요>>";
		double src;
		cin >> src;
		cout << convert(src) << destUnit << "입니다." << endl;
	}
};

class Inch2Centimeter : public Converter {
public:
	Inch2Centimeter(string sUnit, string dUnit, double ratio) : Converter(sUnit, dUnit, ratio) {

	}
	double convert(double src) {
		return src * (int)ratio;
	}
};

int main() {
	Inch2Centimeter i2m("inch", "cm", 2.54);
	i2m.run();
}