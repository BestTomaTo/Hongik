#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Circle {
	string name;
	int radius;
public:
	Circle(int radius = 1, string name = "") :radius(radius), name(name) {}
	double getArea() { return 3.14 * radius * radius; }
	string getName() { return name; }
	bool operator < (Circle b);
	friend ostream& operator << (ostream& os, vector<Circle>& b);
};

bool Circle::operator<(Circle b) {
	return (radius < b.radius) ? true : false;
}

ostream& operator << (ostream& os, vector<Circle>& v) {
	vector<Circle>::iterator it;

	cout << "모든 원소를 출력한다 >> ";
	for (it = v.begin(); it != v.end(); it++) {
		
		os << it->getName() << ' ';
	}

	cout << endl;

	return os;
}

void printVector(vector<Circle>& v) {
	vector<Circle>::iterator it;

	cout << "모든 원소를 출력한다 >> ";
	for (it = v.begin(); it != v.end(); it++) {
		cout << it->getName() << ' ';
	}

	cout << endl;
}

int main() {
	vector<Circle> v;
	v.push_back(Circle(2, "waffle"));
	v.push_back(Circle(3, "pizza"));
	v.push_back(Circle(1, "dotnet"));
	v.push_back(Circle(5, "pizzsLarge"));
	printVector(v);

	int it = v.size() - 1;
	sort(&v[0], &v[it]);
	printVector(v);
	cout << endl << "프렌드 함수 operator <<로 출력하는 경우 : " << endl;
	cout << v << endl;
}