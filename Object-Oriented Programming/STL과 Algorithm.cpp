/*
	알고리즘 : 다양한 자료구조에서 공통으로 사용할 수 있는 함수들
	템플릿 함수, 전역 함수 iterator와 함께 작동.

	ex) sort함수
*/

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
int main() {
	vector<int> v;

	cout << "5개의 정수를 입력하세요 : ";
	for (int i = 0; i < 5; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}

	//v.begin()에서 v.end() 사이의 값을 오름차순으로 정렬, 
	//sort(이상, 미만)이라 끝까지는 안감.
	//참고로 list는 list안에 있는 멤버함수 sort를 사용해야 함.
	sort(v.begin(), v.end());
	vector<int>::iterator it;

	for (it = v.begin(); it != v.end(); i++) {
		cout << *it;
	}
}*/

/* vector와 알고리즘 함수 sort 활용 - 미완이다. 완성해라! */
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
	PrintVector(intV, "정렬 전");

	sort(intV.begin(), intV.end()); // 오름차순;

}
*/

/* vector안에 클래스 객체 변수가 들어가면 어떻게 될까? */
/* 
	왜 오름차순을 정의했을까?
	=> 객체는 내가 정의한 자료형이라 컴퓨터가 뭐가 큰지 몰라.
	직접 알려줘야지 오름차순을 정의할 수 있다.

	왜 연산자 오버로딩을 사용하여 새롭게 출력형태를 만들었을까?
	=> 내가 만든 형태로 출력을 만들 수 있다.
	=> 밑에 cout << *iter << " ";하면 자동으로 괄호형태로 출력해주니까. 
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