#include <iostream>
using namespace std;

/*
class Rect; // equals ������ �� �Ű������� ���¸� �𸣴ϱ�, rect�� �̸� Ŭ������� ����
bool equals(Rect r, Rect s);

class RectManager {
public:
	bool equals(Rect s, Rect r);
};

class Rect {
	int width, height;
public:
	Rect(int width, int height) { this->width = width; this->height = height; }
	friend bool RectManager::equals(Rect r, Rect s); //math Ŭ������ ���氡��
};

bool RectManager::equals(Rect r, Rect s) {
	if (r.width == s.width && r.height == s.height) return true;
	else return false;
}

int main() {
	Rect a(3, 4), b(3, 4);
	RectManager man;

	if (man.equals(a, b)) cout << "����" << endl;
	else cout << "�ٸ�" << endl;
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
	Power tmp; // �ӽ� ��ü ����
	tmp.kick = this->kick + op2.kick;
	tmp;
	// return (this->kick + op2.kick , this->punch + op2.punch); 
}*/

/* RectManager�� �ִ� equals�Լ��� RectŬ������ ���϶�.*/

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
	// Equals�� RectManager�� ����Լ�������, equals�� ������
	// RectMangaer�� ��ü�� �ϳ� ������ ��.
	cout << man.Equals(a, b);
}*/