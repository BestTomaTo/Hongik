#include <utility>
#include <vector>
#include <iostream>
#include <list>
using namespace std;

/*STL Pair 사용법*/
/*
int main(void) {
	pair<int, int> p1;
	p1 = make_pair(10, 20);
	pair<int, int> p2(30, 40);
	pair<pair<int, int>, pair<double, double>> pp2;
	pp2 = make_pair(make_pair(100, 200), make_pair(10.2, 34.3));

	printf("p1 = ( %d %d ) \n", p1.first, p1.second);
	printf("p2 = ( %d %d ) \n", p2.first, p2.second);

	printf("pp2.first = ( %d %d ) \n", pp2.first.first, pp2.first.second);
	printf("pp2.second = ( %f %f ) \n", pp2.second.first, pp2.second.second);
	return 0;
}*/

/*STL Vector 사용법*/
/*
int main(void) {
	int i, value;
	vector<int> intV; // vector는 객체다. 객체 안에 배열이 들어 있는거다.

	for (i = 0; i < intV.size(); i++) {
		cout << "값 입력 : ";
		cin >> value;
		//intV[i] = value;
		intV.push_back(value); // 이런 함수를 쓸 수 있는 것은, 멤버함수로 다 구현이 되어있기 때문.
	}

	for (i = 0; i < intV.size(); i++) {
		cout << intV[i] << "\t"; // 이거 가능한 이유는 []연산자 오버로딩 때문
	}

	cout << intV.capacity();
<
}*/

/* 벡터 클래스 사용 예제 문제 */
/*
class CPoint {
	int x, y;
public:
	CPoint(int a = 0, int b = 0) : x(a), y(b) {}
	void Print() { cout << "C" << x << ", " << y << ")" << endl; }
};

int main() {
	unsigned i;
	vector<CPoint> cAry(3);
	for (i = 0; i < cAry.size(); i++) {
		cAry.at(i) = CPoint(i + 1, i + 1);
	}
	for (i = 0; i < cAry.size(); i++) {
		cAry.at(i) = CPoint(i + 1, i + 1);
	}
}*/

/* 퀴이즈으 - 벡터를 매개변수로 전달 */
/*
void printVector(const vector<int> &v) { // 왜 참조변수를 사용했을까 : 사용 안하면 복사하니까, 값이 변하지를 않는다.
	for (int i = 0; i < 5; i++) {
		cout << v[i];
	}
}

double getAverage(const vector<int>& v) { // 여기서도 참조를 사용하지 않으면 일일이 다 복사해야하니까 시간과 저장공간의 낭비가 심하다.
	double sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += v[i];
	}

	return sum / 5;
}

int main() {
	vector<int> v;
	cout << "정수 다섯개 입력 고고링 : ";
	for (int i = 0; i < 5; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	printVector(v);
	cout << "평균 : " << getAverage(v) << endl;
}*/

/* iterator의 등장 */
/*
int main() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	vector<int>::iterator it;

	for (it = v.begin(); it != v.end(); it++) {
		*it *= 2;

		//int n = *it;
		//n *= 2;
		//*it = n;
	}

	for (it = v.begin(); it != v.end(); it++) {
		cout << *it << ' ';
	}
}*/

/* iterator와 list 클래스 */
// 삽입 삭제가 빈번한 자료에 사용한다. 왜냐, 일일이 안 옮겨도 되니까
/*
int main() {
	int i = 0;
	list<int> Mylist(5, 20);
	//list<int>::iterator it;

	for (auto it = Mylist.begin(); it != Mylist.end(); it++) { // for (it = Mylist.begin(); it != Mylist.end(); it++)
		*it = *it * (i + 1);
		i++;
		cout << *it << ' ';
	}

	//auto란 나오는 원소에 따라 자동으로 형을 정해주는 명령어다.

	

	cout << endl;
	cout << Mylist.front() << endl;
	cout << *Mylist.begin() << endl;
	cout << Mylist.back() << endl;
	cout << *(--Mylist.end()) << endl; // iterator end는 빈칸을 가리킨다. 그래서 -1

}*/

/* list 클래스 */
/*
int main() {
	list<int> mylist;
	list<int>::iterator it;

	for (int i = 0; i < 5; i++) { mylist.push_back(i + 1); } // 1 2 3 4 5

	it = mylist.begin(); ++it;
	mylist.insert(it, 10); // 1 10 2 3 4 5
	// insert함수는 자동으로 iterator값을 자료크기만큼 증가시킴.
	mylist.insert(it, 2, 20); // 1 10 20 20 2 3 4 5
	--it;
	vector<int> myvector(2, 30);
	mylist.insert(it, myvector.begin(), myvector.end());

	cout << "mylist contains : ";

	for (it = mylist.begin(); it != mylist.end(); it++) {
		cout << *it << ' ';
	}

	// 뒤로 붙여!

}*/

/* list Quiz */
/*
int main() {
	int i;
	vector<int> intV(5);
	int* pV = &intV[0];

	cout << "정수 5개 입력하라 : ";
	for (i = 0; i < intV.size(); i++) {
		cin >> *pV;
		++pV;
	}

	//초기화
	pV = &intV[0];
	cout << "정수 값 출력 : ";
	for (int i = 0; i < intV.size(); i++) {
		cout << *pV; ++pV;
	}
	
	cout << endl;
}*/

/*iterator로 재사용*/
/*
int main() {
	int i;
	vector<int> intV(5);
	vector<int>::iterator it;
	//int* pV = &intV[0];

	cout << "정수 5개 입력하라 : ";
	for (it = intV.begin(); it != intV.end(); it++) {
		cin >> *it;
	}

	//초기화
	it = intV.begin();
	cout << "정수 값 출력 : ";
	for (it = intV.begin(); it != intV.end(); it++) {
		cout << *it;
	}

	cout << endl;
}*/