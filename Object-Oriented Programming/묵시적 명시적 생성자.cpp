#include <iostream>
#include <string>
using namespace std;
/*
class TV {
	int size;
public:
	TV() { size = 20; }
	TV(int size) { this->size = size; }
	int getSize() { return size; }
};

class WideTV : public TV {
	bool videoin;
public:
	WideTV(int size, bool videoin) : TV(size) {
		this->videoin = videoin;

	}

	bool getVideoin() { return videoin; }
};

class SmartTV : public WideTV {
	string ipAdd;
public:
	SmartTV(string ipAdd, int size) : WideTV(size, true) {
		this->ipAdd = ipAdd;
	}
	string getipAdd() { return ipAdd; }
};

int main() 
	SmartTV htv("123.123.123", 32);
	cout << "size : " << htv.getSize() << endl;
	cout << "videoin : " << htv.getVideoin() << " boolalpha : " << boolalpha << endl;
	cout << "ipAdd : " << htv.getipAdd() << endl;
}*/

/* 상속과 생성자 퀴위즈으*/
/*
class Shape {
	int x, y;
public:
	Shape() { cout << "Shape 생성자()" << endl; }
	Shape(int xloc = 0, int yloc = 0) : x(xloc), y(yloc) {
		cout << "Shape 생성자 ( " << xloc << " , " << yloc << " )" << endl;
	}
	~Shape() {
		cout << "Shape 소멸자() " << endl;
	}

};

class Rectangle : public Shape {
	int width, height;
public:
	Rectangle(int xloc, int yloc, int width = 1, int height = 1) : Shape(xloc, yloc) {
		this->width = width;
		this->height = height;

		cout << "Rectagle 생성자 ( " << xloc << " " << yloc << " " << width << " " << height << " )" << endl;
	}
	~Rectangle() {
		cout << " Rectangle 소멸자() " << endl;
	}

};

int main() {
	Rectangle(4, 6, 100, 100);
}*/

/* 상속 생성자 퀴이즈으2 */
/*
class Circle {
protected:
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }

};

class NamedCircle : public Circle {
	string name;
public:
	NamedCircle(int radius, string name) : Circle(radius) {
		this->name = name;
	}

	void show() {
		cout << "반지름이 " << getRadius() << "인 " << name << endl;
	}
};

int main() {
	NamedCircle waffle(3, "waffle");
	waffle.show();
}*/

int* move(int* start) {
	return start;
}

/*
int main() {
	int* arr = new int[5];
	int* barr;
	int n;
	
	for (int i = 0; i < 5; i++) {
		cin >> n;
		arr[i] = n;
	}

	barr = move(arr);

	for (int i = 0; i < 5; i++) {
		//cout << barr[i];
		cin >> n;
		barr[i] = n;
	}

	for (int i = 0; i < 5; i++) {
		cout << arr[i];
		
	}
}*/