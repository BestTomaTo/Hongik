#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
class EvenRandom { 
public:
	EvenRandom(); // seed 설정
	int next(); // 랜덤 짝수 리턴
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
	나누어서 나온 나머지로 rand함수의 구간을 지정할 수 있다.
	일반적으로 rand() % b를 하면 0부터 b-1까지 나머지로 나올 수 있다.
	rand() % (b-a+1)은 0부터 b-a까지 나머지가 나오게 되고 여기서 a를 더해주면
	rand() % (b-a+1)+a이고 a부터 b까지의 범위 내에서 랜덤한 수들이 나오게 된다.
*/

/*
int main() {
	EvenRandom r;
	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 짝수 정수 10개 -- " << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next();
		cout << n << ' ';
	}
	
	cout << endl << endl << "-- 2에서 " << "10까지의 랜덤 짝수 정수 10개 -- " << endl;
	
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 10); // 2에서 10까지의 랜덤한 정수
		cout << n << ' ';
	}
	cout << endl;
}*/
