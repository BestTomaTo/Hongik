#include <iostream>
using namespace std;
/* 1. ���׿����� ��� �Լ� */
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
	Power tmp = *this; // a���� ��.
	kick++;
	punch++;

	return tmp;
}

int main() {
	Power a(4, 6), b;
	a.show();
	b.show();

	b = a++; // b�� ���ϰ� tmp�� �ް�, a�� �״����� 1�����ϱ� a�� ���� �����ϰ�.
	a.show();
	b.show();
}*/

/* 2. ���� ������ �ܺ��Լ� 
- ���������� ����ؾ���. �ֳ�, Ŭ���� ����Լ��� �ƴϱ� �ڱ�� �ǵ� ���� ����.*/
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

	b = ++a; // b�� ���ϰ� tmp�� �ް�, a�� �״����� 1�����ϱ� a�� ���� �����ϰ�.
	a.show();
	b.show();
}*/

/* 3. <<, >> ������ ������ */

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