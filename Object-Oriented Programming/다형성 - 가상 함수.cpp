#include <iostream>
using namespace std;

/* ���� �Լ� �������̵� */
/*
class Shape {
public:
	void paint() {
		draw();
	}

	virtual void draw() {
		cout << "Shape::draw() called" << endl;
	}
};

class Circle :public Shape {
public:
	virtual void draw() { // �Ļ� Ŭ������ virtual�� ������ �� �ִ�.
		cout << "Circle::Draw() called" << endl;
	}

};

int main() {
	Shape* pShape = new Circle(); // ��ĳ���� : �⺻ Ŭ���� Ÿ���� �����Ͱ� �Ļ� Ŭ���� ��ü�� ����Ŵ.
	pShape->paint(); // circle�� shape�� ����� �޾ұ⿡ ����Լ��� ����� �� �ִ�. => ���� �Լ��� ����߱⿡ �Ļ� Ŭ������ draw�� ����Ѵ�.
	delete pShape;
}*/

/* ���� ����� �Ҷ��� �����Լ��� �̿��� �������̵��� �����ϴ�.*/
/*
class Base {
public:
	virtual void f() { cout << "Base::f() called" << endl; }
};

class Derived : public Base {
public:
	void f() { cout << "Derived::f() called" << endl; }

};

class GrandDerived : public Derived {
public:
	void f() { cout << "GrandDerived::f() called" << endl; }
};

int main() {
	GrandDerived g;
	Base* bp;
	Derived* dp;
	GrandDerived* gp;

	bp = dp = gp = new GrandDerived(); // = new GrandDerived();�� heap / = &g�� stack�� ����ȴ�. �����ϸ� ���ڸ� �������.

	bp->f();
	dp->f(); // �߰��� �ִ� f()�� ��� ����ϳ�. :: ���� ���� �����ڸ� �̿��Ѵ�.
	gp->f();
}*/

/* �Ҹ��ڿ� �����Լ� �������̵�*/

/*
class Base {
public:
	virtual ~Base() { cout << "~base ����" << endl; }
};

class Derived : public Base { // ���
public:
	virtual ~Derived() { cout << "~derived ����" << endl; };
};

int main() {
	Base* pb = new Derived();
	Derived* dp = new Derived(); 

	delete dp;
	delete pb;
}*/

