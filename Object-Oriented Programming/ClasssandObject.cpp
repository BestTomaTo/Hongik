#include <iostream>
#include <string>
using namespace std;

/*
class Rectangle {
public: // ������� �ͼ� ��� ������ �Լ��� ����ؾ� �ϴϱ� public
	int width;
	int height;
	double getArea();
	Rectangle() {}; // �������� ������� ù��° : �ڵ�����
};

double Rectangle::getArea() { // ��� Ŭ������ �Լ����� ����ؾ� �Ѵ�.
	return width * height;
}
int main() {
	Rectangle rect;
	rect.width = 3;
	rect.height = 5;
	
	cout << "�簢���� ������ : " << rect.getArea() << endl;
}*/

/*
class Rectangle {
public:
	int width;
	int height;
	Rectangle(int x, int y);
	int getArea();
};


Rectangle::Rectangle(int x, int y) { // ������
	width = x; height = y;
}

int Rectangle::getArea() {
	return width * height;
}

int main() {
	Rectangle rect(3, 5);
	
	cout << "�簢���� ���̴� : " << rect.getArea() << endl;
}*/

/*Rectangle rect2; �����ڸ� ���� ����ٸ� Rectangle::Rectangle(�̰�ó��)
		���� ������ rect2�� ���� class���� �ְ� �� ����� ��� �Ѵ�.*/

/*
class Point {
private:
	int x, y;
public:
	
	void setXY(int a, int b) {
		x = a, y = b;
	}
	void Print() { cout << "(" << x << "," << y << ")" << endl; }
	
};

int main(void) {
	Point P1;
	P1.setXY(3, 4);
	P1.Print();

	return 0;
}*/

/*
class car {
private:
	int speed;
	string color;
public:
	void setspeed(int speed) { this->speed = speed; }
	void setcolor();
	void speedup();
	void printcar();
};


int main() {
	car localcar;
	globalcar.setcolor("white"); globalcar.setspeed(200);
	globalcar.speedup(); globalcar.printcar();

	localcar.setcolor("red"); localcar.setspeed(200);
	localcar.speeddown();  localcar.printcar();

}*/

//class�� ������ ���� ��������� ����Ʈ�ϵ��� ��������°� ����Լ���. ����Լ� �ȿ��� �ݵ�� ��������� ���� ������ �� �־�� �Ѵ�.
class BankAccount {
private:
	string owner;
	int amount;

public:
	void setOwner(string owner) {	this->owner = owner;	}
	void setBalance(int amount) { this->amount = amount; }
	int getBalance();
	void deposit(int amount) { this->amount += amount; }
	void withdraw(int amount); { this->amount -= amount; }
	void print() { cout << owner << "�� ���� �ܾ��� : " << amount << "�Դϴ�." << endl; }

};

int main() {
	BankAccount account;
	account.setOwner("��ö��");
	account.setBalance(0);
	account.deposit(10000);
	account.print();
	account.withdraw(8000);
	account.print();
}




