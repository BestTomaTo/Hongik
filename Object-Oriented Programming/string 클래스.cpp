#include <iostream>
#include <string>
using namespace std;

/*문제 1*/
/*
int main() {
	string str; // 1. str는 string 객체다.
	cout << "문자열 입력 : ";

	getline(cin, str);
	int len = str.size();
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < i; j++) {
			cout << str[j];
		}	
		cout << endl; // 이거 사용하는거 연습하자.
		
	}

	return 0;
}*/

/*
	1. str는 string 객체이다. 따라서 멤버함수와, 멤버변수를 다 사용할 수 있다.
	ex) 객체에서 멤버함수 사용 : str.size()
	str.size() morning => 7 반환
*/

/*문제 2*/
double biggest(double x[], int n) { //double x[] == double * x
	double r;
	r = x[0];

	for (int i = 0; i < n; i++) {
		if (r < x[i]) r = x[i];
	}

	return r;
}
/*
int main() {
	double a[5];
	cout << "5개의 실수를 입력하라 : ";
	for (int i = 0; i < 5; i++) {
		cin >> a[i];
	}
	cout << "가장 큰 실수 : " << biggest(a, 5);
}*/









