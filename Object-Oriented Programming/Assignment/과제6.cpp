#include <iostream>
using namespace std;
/*
class Complex {
	double re, im;

public:
	Complex(double r) { re = r; im = 0; }
	Complex(double r = 0, double i = 0) : re(r), im(i) {}
	void Output() { cout << re << " + " << im << "i" << endl; }

	Complex& operator +=(Complex);
	Complex& operator -();
	friend Complex operator +(Complex&, Complex&);
	friend Complex operator ++(Complex&);
	friend Complex operator ++(Complex&, int);
	friend ostream& operator << (ostream& os, Complex&);


};

Complex& Complex::operator+=(Complex op) {
	this->re = re + op.re;
	this->im = im + op.im;

	return *this;
}

Complex& Complex::operator-() {
	this->re = -re;
	this->im = -im;
	return *this;
}

Complex operator +(Complex& op1, Complex& op2) {
	Complex tmp(op1.re + op2.re, op1.im + op2.im);
	return tmp;
}

Complex operator ++(Complex& op) {
	op.re++;
	op.im++;
	return op;
}

Complex operator ++(Complex& op, int x) {
	Complex tmp(op.re, op.im);
	op.re++;
	op.im++;
	return tmp;
}

ostream& operator<<(ostream& os, Complex& op) {
	os << "(" << op.re << " + " << op.im << "i)" << endl;
	return os;
}

int main() {
	Complex c1(1, 2), c2(3, 4), c(9, 200);
	c1.Output(); c2.Output(); c1 += c2; c1.Output(); //c1 = c1 + c2
	Complex c3 = c1 + c2;
	Complex c4 = c1 += c2, c5, c6; c3.Output();

	c5 = ++c4; c4.Output(); c5.Output();
	c6 = c4++; c4.Output(); c6.Output();
	c2 = -c2;
	cout << c2; cout << c;
	return 0;
}*/