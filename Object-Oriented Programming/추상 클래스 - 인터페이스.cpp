#include <iostream>
using namespace std;

/* 인터페이스를 만든다. 일종의 명세서 */
/*
class Calculator {
public: 
	virtual int add(int a, int b) = 0;
	virtual int sub(int a, int b) = 0;
	virtual double average(int* a, int size) = 0;

};

class GoodCalc : public Calculator {
	int add(int a, int b) { return a + b; }
	int sub(int a, int b) { return a - b; }
	double average(int* a, int size) {
		double sum = 0;
		for (int i = 0; i < size; i++) {
			sum += a[i];
		}

		return sum / size;
	}
};

int main() {
	int a[] = { 1,2,3,4,5 };
	Calculator* cp = new GoodCalc();
	cout << cp->add(2, 3) << endl;
	cout << cp->sub(5, 6) << endl;
	cout << cp->average(a, 5) << endl;
}*/

/*
class Calculator {
	void input() {
		cout << "정수 2개를 입력하세요 : ";
		cin >> a >> b;
	}

protected:
	int a, b;
	virtual int calc(int a, int b) = 0;
public:
	void run() {
		input();
		cout << "계산된 값은 : " << calc(a, b) << endl;
	}
};

class Adder : public Calculator {
public:
	int calc(int a, int b) { return a + b; }
};

class Subtractor : public Calculator {
public:
	int calc(int a, int b) { return a - b; }
};

int main() {
	Adder adder;
	Subtractor subtractor;
	
	adder.run();
	subtractor.run();
}*/

/*
#include <iostream>
using namespace std;

class Calculator {
protected:
	virtual void input() = 0;
	virtual int calc(int a, int b) = 0;
public:
	virtual void run() = 0;
};

class Adder :public Calculator {
protected:
	int a, b;
	void input() {		
		cout << "더할 정수 2개를 입력하세요 : ";
		cin >> a >> b;

	}
	int calc(int a, int b) { return a + b; }
public:		
	void run() {
		input();
		cout << "계산된 값은 : " << calc(a, b) << endl;
	}
};

class Subtractor : public Calculator {
protected:
	int a, b;
	void input() {
		cout << "정수에서 뺄 정수 2개를 입력하세요 : ";
		cin >> a >> b;
	}
	int calc(int a, int b) { return a - b; }
public:
	
	void run() {
		input();
		cout << "계산된 값은 : " << calc(a, b) << endl;
	}
};

int main() {
	Calculator* ap = new Adder(); // 업캐스팅
	Calculator* sp = new Subtractor();

	ap->run();
	sp->run();
}*/

/*
#include <string>
class Converter {
protected:
	double ratio;
	virtual double convert(double src) = 0;
	virtual string getSourceString() = 0; // 원
	virtual string getDestString() = 0;	// 달러
public:
	Converter(double ratio) { this->ratio = ratio; }
};

class WonToDollar : public Converter {
protected:
	WonToDollar(double ratio) : Converter(ratio);
	
public:
	void run() {
		double src;
		cout << " 을 로 바꿉니다. 을 입력하세요 : ";
		cin >> src;
	}
};

int main() {
	
}*/
