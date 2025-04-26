#include <iostream>
using namespace std;
/* 1. 단항연산자 멤버 함수 */
/*
class Power {
	int kick;
	int punch;

public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;
		this->punch = punch;
	}

	void show() {
		cout << "kick : " << kick << " punch : " << punch << endl;
	}

	Power operator ++ (int x);
};

Power Power::operator ++ (int x) {
	Power tmp = *this; // a값이 들어감.
	kick++;
	punch++;

	return tmp;
}

int main() {
	Power a(4, 6), b;
	a.show();
	b.show();

	b = a++; // b는 리턴값 tmp를 받고, a는 그다음에 1증가니까 a는 따로 증가하고.
	a.show();
	b.show();
}*/

/* 2. 단항 연산자 외부함수 
- 참조변수를 사용해야함. 왜냐, 클래스 멤버함수가 아니까 자기걸 건들 수가 없다.*/
//Power operator++(Power& op1, int x);
//Power operator++(Power& op2);
/*
class Power {
	int kick;
	int punch;

public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;
		this->punch = punch;
	}

	void show() {
		cout << "kick : " << kick << " punch : " << punch << endl;
	}

	friend Power operator++ (Power &op1, int x);
	friend Power operator++(Power& op2);
};

Power operator++ (Power &op1, int x) {
	Power tmp = op1;
	op1.kick++;
	op1.punch++;
	return tmp;
}

Power operator++ (Power &op2) {
	op2.kick++;
	op2.punch++;
	return op2;
}

int main() {
	Power a(4, 6), b;
	a.show();
	b.show();

	b = ++a; // b는 리턴값 tmp를 받고, a는 그다음에 1증가니까 a는 따로 증가하고.
	a.show();
	b.show();
}*/

/* 3. <<, >> 연산자 재정의 */

/*
class Complex {
	friend ostream& operator << (ostream& os, const Complex& v);
private:
	double x, y;
public:
	Complex(double x, double y) {
		this->x = x;
		this->y = y;
	}
	
	Complex operator+(const Complex &v2) const {
		Complex v(0.0, 0.0);
		v.x = this->x + v2.x;
		v.y = this->y + v2.y;
		return v;
	}

	void display() {
		cout << "(" << x << " , " << y << "i" << ")" << endl;
	}
};

ostream& operator << (ostream& os, const Complex& v) {
	os << "(" << v.x << " , " << v.y << ")" << endl;
	return os;
}

int main() {
	Complex v1(1.0, 2.0), v2(3.0, 4.0);
	Complex v3 = v1 + v2;
	cout << v1 << v2 << v3;
	return 0;

}*/