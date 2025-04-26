#include <iostream>
using namespace std;

/* 가상 함수 오버라이딩 */
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
	virtual void draw() { // 파생 클래스의 virtual은 생략할 수 있다.
		cout << "Circle::Draw() called" << endl;
	}

};

int main() {
	Shape* pShape = new Circle(); // 업캐스팅 : 기본 클래스 타입의 포인터가 파생 클래스 객체를 가리킴.
	pShape->paint(); // circle이 shape의 상속을 받았기에 멤버함수를 사용할 수 있다. => 가상 함수를 사용했기에 파생 클래스의 draw를 사용한다.
	delete pShape;
}*/

/* 다중 상속을 할때도 가상함수를 이용한 오버라이딩이 가능하다.*/
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

	bp = dp = gp = new GrandDerived(); // = new GrandDerived();는 heap / = &g는 stack에 저장된다. 웬만하면 전자를 사용하자.

	bp->f();
	dp->f(); // 중간에 있는 f()는 어떻게 사용하나. :: 범위 지정 연산자를 이용한다.
	gp->f();
}*/

/* 소멸자와 가상함수 오버라이딩*/

/*
class Base {
public:
	virtual ~Base() { cout << "~base 실행" << endl; }
};

class Derived : public Base { // 상속
public:
	virtual ~Derived() { cout << "~derived 실행" << endl; };
};

int main() {
	Base* pb = new Derived();
	Derived* dp = new Derived(); 

	delete dp;
	delete pb;
}*/

