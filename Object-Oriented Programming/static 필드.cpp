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
		cout << "객체생성 : " << count << " " << "이름 : " << name << endl;
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

//static 변수 생성 전역 공간에 생성
int Person::sharedMoney = 10;

//main함수
int main() {
	Person han;
	han.money = 100; // han의 개인 돈;
	Person::sharedMoney = 200; // 10으로 초기화

	Person lee;
	lee.money = 150;
	lee.addMoney(200); // lee 개인돈 350
	Person::addShared(200); // static 멤버 접근, 공금 400

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
	Employee e1("김철수");
	Employee e2;
	Employee e3("김철호", 20000);

	int n = Employee::getCount();
	cout << "현재 직원수 : " << n << endl;
}*/
