#include <iostream>
using namespace std;
/*
class StaticTest {
	static int count;
	string name;
public: 
	StaticTest(string name) {
		count++;
		this->name = name;
		cout << "��ü���� : " << count << " " << "�̸� : " << name << endl;
	}
};

int StaticTest::count = 0;

int main() {
	StaticTest st1("method 1");
	StaticTest st2("method 2");
	StaticTest st3("method 3");
}*/

/*
class Person {
public:
	double money;
	void addMoney(int money) {
		this->money = money;
	}

	static int sharedMoney;
	static void addShared(int n) {
		sharedMoney += n;
	}
};

//static ���� ���� ���� ������ ����
int Person::sharedMoney = 10;

//main�Լ�
int main() {
	Person han;
	han.money = 100; // han�� ���� ��;
	Person::sharedMoney = 200; // 10���� �ʱ�ȭ

	Person lee;
	lee.money = 150;
	lee.addMoney(200); // lee ���ε� 350
	Person::addShared(200); // static ��� ����, ���� 400

	cout << han.money << ' ' << lee.money << endl;
	cout << han.sharedMoney << ' ' << lee.sharedMoney << endl;
}*/

/*
class Employee {
	string name;
	int money;
public:
	Employee(string name = " ", int n = 100): name(name), money(n) { count++; }
	
	static int count;
	static int getCount() { return count; }

};

int Employee::count = 0;

int main() {
	Employee e1("��ö��");
	Employee e2;
	Employee e3("��öȣ", 20000);

	int n = Employee::getCount();
	cout << "���� ������ : " << n << endl;
}*/
