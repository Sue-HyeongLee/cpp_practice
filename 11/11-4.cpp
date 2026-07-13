#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

/*
 못 푼 문제가 손에 꼽는데 이거 못 풀었음. 새로운 객체에 새로운 객체라는 참신함.
 arr2d[n][m]이면 (arr2d.operator[](n))[m]으로 해석되어야 함.
 어렵긴하네.
*/

class BoundCheckIntArray {
private:
	int* arr;
	int arrlen;
	BoundCheckIntArray(const BoundCheckIntArray& arr){ }
	BoundCheckIntArray& operator=(const BoundCheckIntArray& arr){ }
public:
	BoundCheckIntArray(int len) :arrlen(len) { arr = new int[len]; }
	int& operator[] (int idx) {
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index Out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int operator[] (int idx) const {
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index Out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}

	int GetArrLen() const { return arrlen; }
	~BoundCheckIntArray() { delete[] arr; }
	

};

class BoundCheck2DIntArray {
private:
	BoundCheckIntArray ** arr;
	int row;
	BoundCheck2DIntArray(const BoundCheck2DIntArray& arr) { }
	BoundCheck2DIntArray& operator=(const BoundCheck2DIntArray& arr){}
public:
	BoundCheck2DIntArray(int row, int col) 
		:row(row)
	{
		arr = new BoundCheckIntArray*[row];
		for (int i = 0; i < row; i++) {
			arr[i] = new BoundCheckIntArray(col);
		}
		
	}
	BoundCheckIntArray& operator[](int num) {
		if (num < 0 || num >= row) {
			cout << "Array index Out of bound exception" << endl;
			exit(1);
		}
		return *arr[num];
	
	};
	const BoundCheckIntArray& operator[](int num) const {
		if (num < 0 || num >= row) {
			cout << "Array index Out of bound exception" << endl;
			exit(1);
		}
		return *arr[num];

	};

	int GetRow() const { return row; }
	~BoundCheck2DIntArray() {
		for (int i = 0; i < row; i++) {
			delete arr[i];
			
		}
		delete[] arr;

	}
};


int main(void) {
	BoundCheck2DIntArray arr2d(3, 4);

	for (int n = 0; n < 3; n++)
		for (int m = 0; m < 4; m++)
			arr2d[n][m] = n + m;
	for (int n = 0; n < 3; n++)
	{
		for (int m = 0; m < 4; m++)
			cout << arr2d[n][m] << ' ';
		cout << endl;
	}
		
	return 0;
}