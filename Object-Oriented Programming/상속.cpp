#include <iostream>
#include  <string>
using namespace std;

/* �ڽ��� �θ��� private �� ��������� ��� ���� */
/*
class Point {
	int x, y;
public:
	void set(int x, int y) { this->x = x; this->y = y; } // �θ� Ŭ���� private�� ��� ������ ���� �����ϰ� �ϴ� public ��� �Լ�
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
	
	// ��� ���� �ڽ��� �θ� Ŭ������ ��������� ����ϰ� ���� ��, �θ��� ����Լ��� ���Ͽ� ����ؾ� �Ѵ�.
	// private�� �� Ŭ���� ���� ����Լ����� ����� �� �ִ°Ŵ�. ��� ���� Ŭ������ �Ժη� ����� �� ����.
}

int main() {
	Point p;
	ColorPoint cp; //cp(4, 5) �̷��� ���� �ȵ�. �θ� Ŭ������ privat�� ��� �����̾ �ٷ� ���� �Ұ�
	cp.set(3, 4); // �θ� Ŭ������ x y, // ��ü�� ������ �ʰ� �θ��� ����Լ� ���
	cp.setColor("red"); 
	cp.showColorPoint();
}*/