#include <iostream>
#include <string>
using namespace std;

/*���� 1*/
/*
int main() {
	string str; // 1. str�� string ��ü��.
	cout << "���ڿ� �Է� : ";

	getline(cin, str);
	int len = str.size();
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < i; j++) {
			cout << str[j];
		}	
		cout << endl; // �̰� ����ϴ°� ��������.
		
	}

	return 0;
}*/

/*
	1. str�� string ��ü�̴�. ���� ����Լ���, ��������� �� ����� �� �ִ�.
	ex) ��ü���� ����Լ� ��� : str.size()
	str.size() morning => 7 ��ȯ
*/

/*���� 2*/
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
	cout << "5���� �Ǽ��� �Է��϶� : ";
	for (int i = 0; i < 5; i++) {
		cin >> a[i];
	}
	cout << "���� ū �Ǽ� : " << biggest(a, 5);
}*/









