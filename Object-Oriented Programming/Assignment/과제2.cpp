#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
class EvenRandom { 
public:
	EvenRandom(); // seed ����
	int next(); // ���� ¦�� ����
	int nextInRange(int low, int high);
};

EvenRandom::EvenRandom() {
	srand(time(NULL));
}

int EvenRandom::next() {
	int n = rand();

	for (;;) {
		if (n % 2 == 0) {
			return n;
		}
		else {
			n = rand();
		}
	}
	 
}

int EvenRandom::nextInRange(int low, int high) {
	int n = rand() % (high-low+1) + low;

	for (;;) {
		if (n % 2 == 0) {
			return n;
		}
		else {
			n = rand() % (high - low + 1) + low;
		}
	}
}
*/
/*
	����� ���� �������� rand�Լ��� ������ ������ �� �ִ�.
	�Ϲ������� rand() % b�� �ϸ� 0���� b-1���� �������� ���� �� �ִ�.
	rand() % (b-a+1)�� 0���� b-a���� �������� ������ �ǰ� ���⼭ a�� �����ָ�
	rand() % (b-a+1)+a�̰� a���� b������ ���� ������ ������ ������ ������ �ȴ�.
*/

/*
int main() {
	EvenRandom r;
	cout << "-- 0���� " << RAND_MAX << "������ ���� ¦�� ���� 10�� -- " << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next();
		cout << n << ' ';
	}
	
	cout << endl << endl << "-- 2���� " << "10������ ���� ¦�� ���� 10�� -- " << endl;
	
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 10); // 2���� 10������ ������ ����
		cout << n << ' ';
	}
	cout << endl;
}*/
