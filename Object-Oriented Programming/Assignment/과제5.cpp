#include <iostream>
#include <cstring>
using namespace std;
//복사 생성자, 소멸자 구현하라.
/*
class Mystring {
private:
	char* pBuf;
public:
	Mystring(const char* s = NULL);
	Mystring(Mystring& s);
	~Mystring();
	void print();
	size_t getSize();
};

Mystring::Mystring(const char* s) {
	if (s = NULL) {
		pBuf = new char[1];
		pBuf[0] = NULL;
	}
	else {
		pBuf = new char[strlen(s) + 1];
		strcpy_s(pBuf, strlen(s) + 1, s);
	}
}

Mystring::Mystring(Mystring& s) {
	this->pBuf = s.pBuf;
}

void Mystring::print() {
	cout << pBuf << endl;
}

size_t Mystring::getSize() {
	return strlen(pBuf);
}

int main() {
	Mystring str1;
	Mystring str2("Hello");
	Mystring str3 = "World";
	Mystring str4(str3);

	str1.print();
	str2.print();
	str3.print();
	str4.print();
}*/