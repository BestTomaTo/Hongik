#include <iostream>
using namespace std;

/* 1. ������ �ߺ� �Ű����� ���� */
/*
class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick; this->punch = punch;
	}
	void show();
	friend Power operator+ (Power op1, Power op2);

};

void Power::show() {
	cout << "kick : " << kick << "punch : " << punch << endl;
}

Power operator+ (Power op1, Power op2) {
	Power tmp;
	tmp.kick = op1.kick + op2.kick;
	tmp.punch = op1.punch + op2.punch;

	return tmp;
}

int main() {
	Power a(3, 6); 
	Power b(4.6);
	Power c;

	c = a + b;
	c.show();
}*/

/* 2. ������ �ߺ� �Ű����� ����x */
/*
class CPoint {
	int x, y;
public:
	
	CPoint(int a = 0, int b = 0) : x(a), y(b) {

	}

	 CPoint operator-() {
		 CPoint tmp;
		 tmp.x = -x;
		 tmp.y = -y;

		 return tmp;
		
	}

	
	//CPoint operator-() { return CPoint(-x, -y); } ���ο� ��ü ����? 
	

	void Print() {
		cout << "(" << x << " , " << y <<  ")" << endl;
	}
};

int main(void) {
	CPoint P1(2, 2);
	CPoint P2 = -P1;
	CPoint P3 = -(-P1);

	P1.Print(); P2.Print(); P3.Print();

	return 0;

}*/

/* 3. �ܺ��Լ��� ���۷����Ͱ� �ִ� ��� */
/*
class CPoint {
	int x, y;
public:

	CPoint(int a = 0, int b = 0) : x(a), y(b) {};
	friend CPoint operator-(CPoint);

	void Print() {
		cout << "(" << x << " , " << y << ")" << endl;
	}
};

CPoint operator-(CPoint op) {
	CPoint tmp;
	tmp.x = -(op.x);
	tmp.y = -(op.y);

	return tmp;
}

// CPoint operator-(CPoint a) { return CPoint(-a.x, -a.y) }

int main(void) {
	CPoint P1(2, 2);
	CPoint P2 = -P1;
	CPoint P3 = -(-P1);

	P1.Print(); P2.Print(); P3.Print();

	return 0;
}*/

/* 4. += �����ڰ� ����Լ��� �ִ� ��� */

/*class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;
		this->punch = punch;
	}
	void show();
	Power operator += (Power op2);
};

void Power::show() {
	cout << "kick : " << kick << "punch : " << punch << endl;
}

Power Power::operator +=(Power op2) {
	kick = kick + op2.kick;
	punch = punch + op2.punch;

	return *this;
}

int main() {
	Power a(4, 5); Power b(7, 8);
	Power c;
	a.show();
	c.show();
	
	c = a += b;
	a.show();
	c.show();
}*/

/* 5. += �����ڰ� �ܺ��Լ��� �ִ� ���*/
/* ������ ������ �����϶�. */
/*
class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;
		this->punch = punch;
	}
	void show();
	friend Power operator += (Power op1, Power op2);
};

void Power::show() {
	cout << "kick : " << kick << " punch : " << punch << endl;
}

Power operator += (Power op1, Power op2) {
	op1.kick = op1.kick + op2.kick;
	op1.punch = op1.punch + op2.punch;

	return op1;
}

int main() {
	Power a(4, 5); Power b(7, 8);
	Power c;
	a.show();
	c.show();

	c = a += b;
	a.show(); // ������ �������ٸ�, a�� ������ �ʰ� a�� b���� �� c�� ���Ѵ�.
	c.show();
}*/








