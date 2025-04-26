#include <iostream>
#include <string>
using namespace std;

/*
class Rectangle {
public: // 어느때나 와서 멤버 변수와 함수를 사용해야 하니까 public
	int width;
	int height;
	double getArea();
	Rectangle() {}; // 생성자의 생성방법 첫번째 : 자동생성
};

double Rectangle::getArea() { // 어느 클래스의 함수인지 명시해야 한다.
	return width * height;
}
int main() {
	Rectangle rect;
	rect.width = 3;
	rect.height = 5;
	
	cout << "사각형의 면적은 : " << rect.getArea() << endl;
}*/

/*
class Rectangle {
public:
	int width;
	int height;
	Rectangle(int x, int y);
	int getArea();
};


Rectangle::Rectangle(int x, int y) { // 생성자
	width = x; height = y;
}

int Rectangle::getArea() {
	return width * height;
}

int main() {
	Rectangle rect(3, 5);
	
	cout << "사각형의 넓이는 : " << rect.getArea() << endl;
}*/

/*Rectangle rect2; 생성자를 직접 만든다면 Rectangle::Rectangle(이것처럼)
		직접 생성자 rect2를 따로 class에도 넣고 또 만들어 줘야 한다.*/

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

//class를 정의할 때는 멤버변수를 서포트하도록 만들어지는게 멤버함수다. 멤버함수 안에는 반드시 멤버변수에 대한 내용이 들어가 있어야 한다.
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
	void print() { cout << owner << "의 계좌 잔액은 : " << amount << "입니다." << endl; }

};

int main() {
	BankAccount account;
	account.setOwner("김철수");
	account.setBalance(0);
	account.deposit(10000);
	account.print();
	account.withdraw(8000);
	account.print();
}




