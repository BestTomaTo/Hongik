#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
/*
class Player {
	string name;
public:
	Player(string name = "") {
		this->name = name;
	}
	void setName(string name) { this->name = name; }
	string getName() { return name; }
	
	void getEnterkey() { // <Enter> 키가 입력되면 리턴
		char buf[100];
		cin.getline(buf, 99); // wait <Enter> key
	}
};

class GamblingGame {// 갬블링 게임 전체를 다루는 클래스
	Player p[2]; // 2명의 선수
	int num[3]; // 랜덤하게 생성된 3개의 수를 저장하는 배열
	bool matchAll(); // num[] 배열의 수가 모두 일치하면 true 리턴
public:
	GamblingGame(); // num[i] = 0 setting 및 랜덤 seed 값 생성
	void run();
};*/

/* 랜덤함수 seed 값 생성*/
/*
GamblingGame::GamblingGame() {
	for (int i = 0; i < 3; i++) {
		num[i] = 0;
	}

	srand((unsigned)time(0));	
}

// num[] 배열의 수가 모두 일치하면 true 리턴
bool GamblingGame::matchAll() {
	int n;

	while (true) {
		for (int i = 0; i < 3; i++) {
			n = rand() % 3;
			num[i] = n;

			cout << "    " << num[i];
		}

		if (num[0] == num[1] && num[1] == num[2]) {
			return true;
		}
		
		else {
			cout << "     아쉽군요!" << endl;
			return false;			
		}
	}

	
	
}*/

/* 게임을 실행하는 run 멤버함수 */
/*
void GamblingGame::run() {
	string name;
	bool result = false;
	cout << "***** 겜블링 게임을 시작합니다. *****" << endl;
	*/

	/* 사람 이름 입력 */
	/*
	for (int i = 0; i < 2; i++) {
		if (i == 0) { cout << "첫번째 선수 이름>>"; }
		else { cout << "두번째 선수 이름>>"; }

		cin >> name;
		p[i].setName(name);	
		cin.ignore();
	}*/

	/* 수가 같으면 게임 종료 */
	/*
	while (result != true) {
		for (int i = 0; i < 2; i++) {
			cout << p[i].getName() << ":<enter>";
			p->getEnterkey();
			result = matchAll(); // matchall 함수 실행

			if (result == true) { 
				cout << "     " << p[i].getName() << "님 승리!" << endl; 
				break; // 수가 같아 true가 반환되면 게임 종료
			}
		}
	}
}


int main() {
	GamblingGame game;
	game.run();
}*/