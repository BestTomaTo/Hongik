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
	
	void getEnterkey() { // <Enter> Ű�� �ԷµǸ� ����
		char buf[100];
		cin.getline(buf, 99); // wait <Enter> key
	}
};

class GamblingGame {// ���� ���� ��ü�� �ٷ�� Ŭ����
	Player p[2]; // 2���� ����
	int num[3]; // �����ϰ� ������ 3���� ���� �����ϴ� �迭
	bool matchAll(); // num[] �迭�� ���� ��� ��ġ�ϸ� true ����
public:
	GamblingGame(); // num[i] = 0 setting �� ���� seed �� ����
	void run();
};*/

/* �����Լ� seed �� ����*/
/*
GamblingGame::GamblingGame() {
	for (int i = 0; i < 3; i++) {
		num[i] = 0;
	}

	srand((unsigned)time(0));	
}

// num[] �迭�� ���� ��� ��ġ�ϸ� true ����
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
			cout << "     �ƽ�����!" << endl;
			return false;			
		}
	}

	
	
}*/

/* ������ �����ϴ� run ����Լ� */
/*
void GamblingGame::run() {
	string name;
	bool result = false;
	cout << "***** �׺� ������ �����մϴ�. *****" << endl;
	*/

	/* ��� �̸� �Է� */
	/*
	for (int i = 0; i < 2; i++) {
		if (i == 0) { cout << "ù��° ���� �̸�>>"; }
		else { cout << "�ι�° ���� �̸�>>"; }

		cin >> name;
		p[i].setName(name);	
		cin.ignore();
	}*/

	/* ���� ������ ���� ���� */
	/*
	while (result != true) {
		for (int i = 0; i < 2; i++) {
			cout << p[i].getName() << ":<enter>";
			p->getEnterkey();
			result = matchAll(); // matchall �Լ� ����

			if (result == true) { 
				cout << "     " << p[i].getName() << "�� �¸�!" << endl; 
				break; // ���� ���� true�� ��ȯ�Ǹ� ���� ����
			}
		}
	}
}


int main() {
	GamblingGame game;
	game.run();
}*/