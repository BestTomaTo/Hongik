#include <iostream>
using namespace std;

/*
class Rect; // equals 선언할 때 매개변수의 형태를 모르니까, rect가 미리 클래스라고 선언
bool equals(Rect r, Rect s);

class RectManager {
public:
	bool equals(Rect s, Rect r);
};

class Rect {
	int width, height;
public:
	Rect(int width, int height) { this->width = width; this->height = height; }
	friend bool RectManager::equals(Rect r, Rect s); //math 클래스로 변경가능
};

bool RectManager::equals(Rect r, Rect s) {
	if (r.width == s.width && r.height == s.height) return true;
	else return false;
}

int main() {
	Rect a(3, 4), b(3, 4);
	RectManager man;

	if (man.equals(a, b)) cout << "같음" << endl;
	else cout << "다름" << endl;
}*/

/*
class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) { this->kick = kick; this->punch = punch; }
	void show();
	Power operator+ (Power op2);
};

void Power::show() {
	cout << "kick : " << kick << "punch : " << punch << endl;
}

Power Power::operator+ (Power op2) {
	Power tmp; // 임시 객체 생성
	tmp.kick = this->kick + op2.kick;
	tmp;
	// return (this->kick + op2.kick , this->punch + op2.punch); 
}*/

/* RectManager에 있는 equals함수로 Rect클래스를 비교하라.*/

/*
class Rect;

class RectManager {
public:
	bool Equals(Rect s, Rect c);
};

class Rect {
	int width, height;
public:
	Rect(int width = 1, int height = 1) { this->width = width; this->height = height; }

	friend bool RectManager::Equals(Rect s, Rect c);

};

bool RectManager::Equals(Rect s, Rect c) {
	if (s.width == c.width || s.height == c.height) return true;
	else return false;
}

int main() {
	Rect a, b(2, 2);
	RectManager man; 
	// Equals는 RectManager의 멤버함수임으로, equals를 쓰려면
	// RectMangaer의 객체를 하나 만들어야 함.
	cout << man.Equals(a, b);
}*/