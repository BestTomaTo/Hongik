#include <utility>
#include <vector>
#include <iostream>
#include <list>
using namespace std;

/*STL Pair ����*/
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

/*STL Vector ����*/
/*
int main(void) {
	int i, value;
	vector<int> intV; // vector�� ��ü��. ��ü �ȿ� �迭�� ��� �ִ°Ŵ�.

	for (i = 0; i < intV.size(); i++) {
		cout << "�� �Է� : ";
		cin >> value;
		//intV[i] = value;
		intV.push_back(value); // �̷� �Լ��� �� �� �ִ� ����, ����Լ��� �� ������ �Ǿ��ֱ� ����.
	}

	for (i = 0; i < intV.size(); i++) {
		cout << intV[i] << "\t"; // �̰� ������ ������ []������ �����ε� ����
	}

	cout << intV.capacity();
<
}*/

/* ���� Ŭ���� ��� ���� ���� */
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

/* �������� - ���͸� �Ű������� ���� */
/*
void printVector(const vector<int> &v) { // �� ���������� ��������� : ��� ���ϸ� �����ϴϱ�, ���� �������� �ʴ´�.
	for (int i = 0; i < 5; i++) {
		cout << v[i];
	}
}

double getAverage(const vector<int>& v) { // ���⼭�� ������ ������� ������ ������ �� �����ؾ��ϴϱ� �ð��� ��������� ���� ���ϴ�.
	double sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += v[i];
	}

	return sum / 5;
}

int main() {
	vector<int> v;
	cout << "���� �ټ��� �Է� ��� : ";
	for (int i = 0; i < 5; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	printVector(v);
	cout << "��� : " << getAverage(v) << endl;
}*/

/* iterator�� ���� */
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

/* iterator�� list Ŭ���� */
// ���� ������ ����� �ڷῡ ����Ѵ�. �ֳ�, ������ �� �Űܵ� �Ǵϱ�
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

	//auto�� ������ ���ҿ� ���� �ڵ����� ���� �����ִ� ��ɾ��.

	

	cout << endl;
	cout << Mylist.front() << endl;
	cout << *Mylist.begin() << endl;
	cout << Mylist.back() << endl;
	cout << *(--Mylist.end()) << endl; // iterator end�� ��ĭ�� ����Ų��. �׷��� -1

}*/

/* list Ŭ���� */
/*
int main() {
	list<int> mylist;
	list<int>::iterator it;

	for (int i = 0; i < 5; i++) { mylist.push_back(i + 1); } // 1 2 3 4 5

	it = mylist.begin(); ++it;
	mylist.insert(it, 10); // 1 10 2 3 4 5
	// insert�Լ��� �ڵ����� iterator���� �ڷ�ũ�⸸ŭ ������Ŵ.
	mylist.insert(it, 2, 20); // 1 10 20 20 2 3 4 5
	--it;
	vector<int> myvector(2, 30);
	mylist.insert(it, myvector.begin(), myvector.end());

	cout << "mylist contains : ";

	for (it = mylist.begin(); it != mylist.end(); it++) {
		cout << *it << ' ';
	}

	// �ڷ� �ٿ�!

}*/

/* list Quiz */
/*
int main() {
	int i;
	vector<int> intV(5);
	int* pV = &intV[0];

	cout << "���� 5�� �Է��϶� : ";
	for (i = 0; i < intV.size(); i++) {
		cin >> *pV;
		++pV;
	}

	//�ʱ�ȭ
	pV = &intV[0];
	cout << "���� �� ��� : ";
	for (int i = 0; i < intV.size(); i++) {
		cout << *pV; ++pV;
	}
	
	cout << endl;
}*/

/*iterator�� ����*/
/*
int main() {
	int i;
	vector<int> intV(5);
	vector<int>::iterator it;
	//int* pV = &intV[0];

	cout << "���� 5�� �Է��϶� : ";
	for (it = intV.begin(); it != intV.end(); it++) {
		cin >> *it;
	}

	//�ʱ�ȭ
	it = intV.begin();
	cout << "���� �� ��� : ";
	for (it = intV.begin(); it != intV.end(); it++) {
		cout << *it;
	}

	cout << endl;
}*/