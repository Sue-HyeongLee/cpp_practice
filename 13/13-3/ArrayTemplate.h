#pragma once
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
using namespace std;

template <typename T>

class BoundCheckArray {
private:
	T* arr;
	int arrlen;
	BoundCheckArray(const BoundCheckArray& arr) = delete;
	BoundCheckArray& operator= (const BoundCheckArray & arr) = delete;
public:
	BoundCheckArray(int len);
	T& operator[](int idx);
	T operator[](int idx) const;
	int GetArrLen() const;
	~BoundCheckArray();
};

template <typename T>
BoundCheckArray<T>::BoundCheckArray(int len)
	: arrlen(len)
{
	arr = new T[len];
}

template <typename T>
T& BoundCheckArray<T>::operator[](int idx) {

	if (idx >= arrlen || idx < 0) {
		cout << "Array Index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

template <typename T>
T BoundCheckArray<T>::operator[](int idx) const {

	if (idx >= arrlen || idx < 0) {
		cout << "Array Index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

template <typename T>
int BoundCheckArray<T>::GetArrLen() const {
	return arrlen;
}

template <typename T>
BoundCheckArray<T>::~BoundCheckArray() {
	delete[] arr;
}