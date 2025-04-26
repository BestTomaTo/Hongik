/*
	�˰��� : �پ��� �ڷᱸ������ �������� ����� �� �ִ� �Լ���
	���ø� �Լ�, ���� �Լ� iterator�� �Բ� �۵�.

	ex) sort�Լ�
*/

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
int main() {
	vector<int> v;

	cout << "5���� ������ �Է��ϼ��� : ";
	for (int i = 0; i < 5; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}

	//v.begin()���� v.end() ������ ���� ������������ ����, 
	//sort(�̻�, �̸�)�̶� �������� �Ȱ�.
	//����� list�� list�ȿ� �ִ� ����Լ� sort�� ����ؾ� ��.
	sort(v.begin(), v.end());
	vector<int>::iterator it;

	for (it = v.begin(); it != v.end(); i++) {
		cout << *it;
	}
}*/

/* vector�� �˰��� �Լ� sort Ȱ�� - �̿��̴�. �ϼ��ض�! */
/*
void PrintVector(const vector<int>& v, string name) {
	vector<int>::iterator iter;
	cout << ">> " << name << " : ";
	for (iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter << ' ';
	}
}

bool IntCompare(int a, int b) { return (a > b) ? true : false; }
int main() {
	vector<int> intV = { 22, 55, 31, 77, 65, 99 };
	PrintVector(intV, "���� ��");

	sort(intV.begin(), intV.end()); // ��������;

}
*/

/* vector�ȿ� Ŭ���� ��ü ������ ���� ��� �ɱ�? */
/* 
	�� ���������� ����������?
	=> ��ü�� ���� ������ �ڷ����̶� ��ǻ�Ͱ� ���� ū�� ����.
	���� �˷������ ���������� ������ �� �ִ�.

	�� ������ �����ε��� ����Ͽ� ���Ӱ� ������¸� ���������?
	=> ���� ���� ���·� ����� ���� �� �ִ�.
	=> �ؿ� cout << *iter << " ";�ϸ� �ڵ����� ��ȣ���·� ������ִϱ�. 
*/
class CPoint {
	int x, y;
public:
	CPoint(int a = 0, int b = 0) : x(a), y(b) {}
	bool operator < (CPoint& po) {
		return (x + y < po.x + po.y) ? true : false;
	}

	friend ostream& operator <<(ostream& os, CPoint& po);
};

ostream& operator <<(ostream& os, CPoint& po) {
	os << "(" << po.x << " , " << po.y << ")"; 
}

void PrintVector(vector)