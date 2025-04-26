#include <iostream>
#include <string>
using namespace std;
/*
int main() {
	string song("Falling in love with you"); //문자열 song
	string elvis("Elvis Presley");
	string singer;

	cout << song + "를 부른 가수는"; // + 문자열 연결
	

	cout << "(힌트 : 첫글자는 " << elvis[0] << ")?"; // []연산자 사용
	
	
	getline(cin, singer);

	
	if (singer == elvis) {
		cout << "맞았습니다.";
	}
	else {
		cout << "틀렸습니다. " + elvis + "입니다.";
	}

}*/

/* c에서는 뒤에 \n 이거 찾고 고생을 했었는데, 여기는 파이썬 처럼 + 사용 가능.*/
/* 문자열이다. 열은 곧 배열이라는 뜻이니까, 포인터도 갖다 붙일 수 있나.
		song[0] == F c언어에서 사용하는 배열의 형식을 다 따라감.*/

/* 비교연산자를 사용하려면 c에서는 하나씩 뽑았어야 되었는데 여기는 한꺼번에 사용ㄱㄴ*/