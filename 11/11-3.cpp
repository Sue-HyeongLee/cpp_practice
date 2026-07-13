#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	friend ostream& operator<<(ostream& os, const Point* pos);

};


ostream& operator<<(ostream& os, const Point* pos) {
	os << '[' << (*pos).xpos << ", " << (*pos).ypos << ']' << endl;
	return os;

} 
//이거 굳이 const POINT_PTR& 하는 것보다 const Point*하는 게 낫네. 왜냐면 원작 코드도
// POINT_PTR값을 수정하지말자!가 아니라 가르키고 있는 걸 수정하지 말자이니...
typedef Point* POINT_PTR;

class BoundCheckPointArray {
private:
	POINT_PTR* arr;
	int arrlen;

	BoundCheckPointArray(const BoundCheckPointArray& arr) {}
	BoundCheckPointArray& operator=(const BoundCheckPointArray& arr) {}
public:
	BoundCheckPointArray(int len) :arrlen(len) {
		arr = new POINT_PTR[len];
	}
	POINT_PTR& operator[] (int idx) {

		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}

		return arr[idx];
	}

	POINT_PTR operator[] (int idx) const {
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}

		return arr[idx];

	}

	int GetArrLen() const { return arrlen; }
	~BoundCheckPointArray() {
		for (int i = 0; i < arrlen; i++) {
			delete arr[i];
		}
		delete[] arr;
	}
	
};

int main(void) {
	BoundCheckPointArray arr(3);
	arr[0] = new Point(3, 4);
	arr[1] = new Point(5, 6);
	arr[2] = new Point(7, 8);

	for (int i = 0; i < arr.GetArrLen(); i++) {
		cout << arr[i];
	}
		
	
}