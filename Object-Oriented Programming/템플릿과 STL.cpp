#include <iostream>
#include <string>
using namespace std;
/*
class Circle {
	int radius;
public:
	Circle(int radius = 1) { this->radius = radius; }
	int getRadius() { return radius; }
};

template <class T>
void myswap(T& a, T& b) {
	T tmp;
	tmp = a;
	a = b;
	b = tmp; // 디폴트 대입 연산자 사용
}

int main() {
	Circle a(4), b(5);

	myswap(a, b);
	cout << "a : " << a.getRadius() << "b : " << b.getRadius() << endl; // 클래스

	double c = 2.3, d = 5.3;
	myswap(c, d);
	cout << "c : " << c << "d : " << d << endl;



}*/

/*
template <class K>
K Sum(K a, K b) {
	K c;
	c = a + b;
	return c;
}

int main(void) {
	
	cout << Sum(1, 2) << endl;
	cout << Sum(1.1, 2.2) << endl;
	cout << Sum('2', '4') << endl;
}*/

/*
template <class t1, class t2, class t3>
void Print(t1 a, t2 b, t3 c) {
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}

int main() {
	Print(1, 2.5, 'c');
	Print("i want", "go", "home");
}*/

/*
template <class s1, class s2> 
bool search(s1 compare, s2 *arr, int k) {
	
	for (int i = 0; i < k; i++) {
		if (compare == arr[i]) return true;
	}
	
	return false;
}

int main() {
	int x[] = { 1, 10, 100, 5, 4 };
	if (search(100, x, sizeof(x) / 4)) 
		cout << "있다." << endl;
	else
		cout << "없다." << endl;
	


}*/

/*
class Point {
	int x, y;
public:
	Point(int x = 0, int y = 0) { this->x = x; this->y = y; }
	void show() { cout << "(" << x << ';' << y << ')' << endl; }
};

template <class T>
class MyStack {
	int tos;
	T data[100]; 
public:
	MyStack();
	void push(T element);
	T pop();
};

template <class T>
MyStack<T>::MyStack() {
	tos = -1;
}

template <class T>
void MyStack<T>::push(T element) {
	if (tos == 99) {
		cout << "stack full"; return;
	}
	tos++;
	data[tos] = element;
}

template <class T>
T MyStack<T>::pop() {
	T retData;
	if (tos == -1) {
		cout << "Stack Empty!";
		return 0;
	}

	redData = data[tos--]; return retData; // 후위 증감 연산자
}

int main() {
	MyStack<int*> ipStack;
	int* p = new int[3];
	for (int i = 0; i < 3; i++) p[i] *= 10;
	ipStack.push(p);
	int* q = ipStack.pop();
	for (int i = 0; i < 3; i++) cout << q[i] << ' ';
	cout << endl;
	delete[]p;

	MyStack<Point> pointStack;
	Point a(2, 3), b;
	pointStack.push(a);
	b = pointStack.pop();
	b.show();

	MyStack<Point*> pStack;
	pStack.push(new Point(10, 20));
	Point* pPoint = pStack.pop();
	pPoint->show();

	MyStack<string> stringStack;

}*/

/* 퀴즈 */
/*
template <typename T>
class Point {
	T x, y;
public:
	Point(T a = 0, T b = 0) : x(a), y(b) {}
	template <typename T>  // 특별히 friend 함수 위에도 typename t를 만들어야 함.
	friend ostream& operator<<(ostream& out, Point<T>& Po);
}; 

template <class T>
ostream& operator<<(ostream& out, Point<T>& Po) {
	out << "(" << Po.x << "," << Po.y << ")";
	return out;
}

int main() {
	Point<int> a(3, 5);
	cout << a << endl;
	Point<double> b(3, 4);
	cout << b << endl;
}*/

/* 두개의 제너릭 타입을 가진 클래스 만들기 */
/*
template <class T1, class T2>
class GClass {
	T1 data1; 
	T2 data2;
public:
	GClass();
	void set(T1 a, T2 b);
	void get(T1& A, T2& B);
};

template <class T1, class T2>
GClass<T1, T2>::GClass() {
	data1 = 0;
	data2 = 0;
}

template <class T1, class T2>
void GClass<T1, T2>::set(T1 a, T2 b) {
	data1 = a;
	data2 = b;
}

template <class T1, class T2>
void GClass<T1, T2>::get(T1& A, T2& B) {
	A = data1;
	B = data2;
}

int main() {
	int a;
	double b;
	GClass<int, double> x;
	x.set(2, 0.5);
	x.get(a, b);
	cout << "a : " << a << "b : " << b << endl;
}*/

