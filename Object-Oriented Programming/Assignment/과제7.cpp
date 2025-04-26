#include <iostream>
using namespace std;
/*
class BaseArray {
private:
	int capacity; // 동적 M 용량
	int* mem;
protected:
	BaseArray(int capacity = 100) : capacity(capacity) { mem = new int[capacity]; }
	//~BaseArray() { delete[]mem; }
	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
	void putCapacity(int newCap) { capacity = newCap; }
	int* getMem(void) { return mem; }
	void putMem(int* start); // mem에 원소들을 넣어줘라!, 원소들을 넣어주기 위해선 capacity를 바꿔줘야됨.
	void deleteMem();
};

void BaseArray::putMem(int * start) { //start = mem (첫번째 원소 주소)
	int *clone_mem = new int[5];
	
	if (capacity == 1) {
		clone_mem[0] = start[0];
	}
	else {
		for (int i = 0; i < capacity; i++) {
			clone_mem[i] = start[i];
		}
	}

	delete[]mem;
	putCapacity(getCapacity() * 2);
	mem = new int[capacity];

	if (capacity == 1) {
		mem[0] = clone_mem[0];
	}
	else {
		for (int i = 0; i < capacity/2; i++) {
			 mem[i] = clone_mem[i];
		}
	}

	delete[]clone_mem;
}

void BaseArray::deleteMem() {
	int cnt = 0;
	
	for (int i = 7; i >= 0; i--) {
		if (mem[i] != NULL) {
			mem[i] = NULL;
			cnt++;
		}

		if ((i + 1) * 4 == capacity) {
			putCapacity(getCapacity() / 2);
		}

		if (cnt) { break; }
	}
}

class Mystack : public BaseArray {
private:
	int tos = -1;
public:
	Mystack(int capacity) : BaseArray(capacity) {}
	void push(int n);
	int pop();
	int capacity() { return getCapacity(); }
	int length(); 
};


void Mystack::push(int n) { // n : push되는 값
	tos++;

	if (tos == getCapacity()) {
		putMem(getMem());
		put(tos, n);
	}
	else {
		put(tos, n);
	}
}

int Mystack::pop() {	
	int m = get(tos);
	deleteMem();
	tos--;

	return m;
}

int Mystack::length() {
	return tos + 1;
}

int main() {
	Mystack mStack(1);
	int n = 0;

	cout << "스택에 삽입할 5개의 정수를 입력하라>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mStack.push(n);
	}
	cout << "스택 용량 : " << mStack.capacity() << " , 스택 크기 : " << mStack.length() << endl;

	cout << "스택의 모든 원소를 팝하여 출력한다 >> ";

	while (mStack.length() > 0) {
		int k = mStack.pop();
		cout << k << ' ';
	}
	
	cout << "\n스택 용량:" << mStack.capacity() << ", 스택 크기:" << mStack.length() << endl;
}*/