#include <iostream>
#include  <string>
using namespace std;

/* 자식이 부모의 private 한 멤버변수는 어떻게 쓸까 */
/*
class Point {
	int x, y;
public:
	void set(int x, int y) { this->x = x; this->y = y; } // 부모 클래스 private한 멤버 변수에 접근 가능하게 하는 public 멤버 함수
	void showPoint() {
		cout << "x : " << x << " y : " << y << endl;
	}
};

class ColorPoint : public Point {
	string color;
public:
	void setColor(string color) { this->color = color; }
	void showColorPoint();
};

void ColorPoint::showColorPoint() {
	cout << color << ';';
	cout << "x : " << x << " y : " << y << endl; //showPoint(); 
	
	// 상속 받은 자식은 부모 클래스의 멤버변수를 사용하고 싶을 땐, 부모의 멤버함수를 통하여 사용해야 한다.
	// private은 한 클래스 안의 멤버함수들이 사용할 수 있는거다. 상속 받은 클래스도 함부로 사용할 수 없다.
}

int main() {
	Point p;
	ColorPoint cp; //cp(4, 5) 이렇게 쓰면 안됨. 부모 클래스의 privat한 멤버 변수이어서 바로 접근 불가
	cp.set(3, 4); // 부모 클래스의 x y, // 객체를 만들지 않고 부모의 멤버함수 사용
	cp.setColor("red"); 
	cp.showColorPoint();
}*/