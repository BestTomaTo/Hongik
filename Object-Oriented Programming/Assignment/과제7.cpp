#include <iostream>
using namespace std;
/*
class BaseArray {
private:
	int capacity; // ���� M �뷮
	int* mem;
protected:
	BaseArray(int capacity = 100) : capacity(capacity) { mem = new int[capacity]; }
	//~BaseArray() { delete[]mem; }
	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
	void putCapacity(int newCap) { capacity = newCap; }
	int* getMem(void) { return mem; }
	void putMem(int* start); // mem�� ���ҵ��� �־����!, ���ҵ��� �־��ֱ� ���ؼ� capacity�� �ٲ���ߵ�.
	void deleteMem();
};

void BaseArray::putMem(int * start) { //start = mem (ù��° ���� �ּ�)
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


void Mystack::push(int n) { // n : push�Ǵ� ��
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

	cout << "���ÿ� ������ 5���� ������ �Է��϶�>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mStack.push(n);
	}
	cout << "���� �뷮 : " << mStack.capacity() << " , ���� ũ�� : " << mStack.length() << endl;

	cout << "������ ��� ���Ҹ� ���Ͽ� ����Ѵ� >> ";

	while (mStack.length() > 0) {
		int k = mStack.pop();
		cout << k << ' ';
	}
	
	cout << "\n���� �뷮:" << mStack.capacity() << ", ���� ũ��:" << mStack.length() << endl;
}*/