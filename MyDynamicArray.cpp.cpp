//
// Created by Blake on 2/20/2017.
//
#include <iostream>
using namespace std;

class MyDynamicArray {
private:
	int *pa; // points to the array
	int len; // the # elements
	int nextIndex; // the next highest index value
public:
	MyDynamicArray(); // the constructor
	MyDynamicArray(int s); // the constructor with size s
	~MyDynamicArray(); // the destructor
	int& operator[](int index); // the indexing operation
	void add(int v); // add a new value to the end
	void del(); // reduces the size of the array by one
	int length(); // return length
};

MyDynamicArray::MyDynamicArray() {
	pa = new int[2];
	for (int i = 0; i < 2; i++)
		pa[i] = 0;
	len = 2;
	nextIndex = 0;
}
MyDynamicArray::MyDynamicArray(int s) {
	pa = new int[s];
	for (int i = 0; i < s; i++)
		pa[i] = 0;
	len = s;
	nextIndex = 0;
}
MyDynamicArray::~MyDynamicArray() {
	delete [] pa;
}
int& MyDynamicArray::operator[](int index) {
	int *pnewa; // pointer for new array
	if (index >= length) { // is element in the array?
		pnewa = new int[index * 2]; // allocate a bigger array
		for (int i = 0; i < nextIndex; i++) // copy old values
			pnewa[i] = pa[i];
		for (int j = nextIndex; j < index * 2; j++) // initialize remainder
			pnewa[j] = 0;
		length = index * 2; // set length to bigger size
		delete [] pa; // delete the old array
		pa = pnewa; // reassign the new array
	}
	if (index > nextIndex) // set nextIndex past index
		nextIndex = index + 1;
	return * (pa + index); // a reference to the element
}
void MyDynamicArray::add(int val) {
	int *pnewa;
	if (nextIndex == length) {
		length = length + 10;
		pnewa = new int[length];
		for (int i = 0; i < nextIndex; i++)
			pnewa[i] = pa[i];
		for (int j = nextIndex; j < length; j++)
			pnewa[j] = 0;
		delete [] pa;
		pa = pnewa;
	}
	pa[nextIndex++] = val;
}