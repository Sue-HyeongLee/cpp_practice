#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	void Init(int x, int y) {
		xpos = x;
		ypos = y;
	
	}
	void ShowPointInfo() const {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}

};

class Circle {
private:
	int radius;
	Point center;
public:
	void init(int x, int y, int rad) {
		center.Init(x, y);
		radius = rad;
	}

	void ShowCircleInfo() const {
		cout << "radius: " << radius << endl;
		center.ShowPointInfo();
	}
};

class Ring {
private:
	Circle inner;
	Circle outter;
public:
	void Init(int x, int y, int radius1, int x2, int y2, int radius2) {
		inner.init(x, y, radius1);
		outter.init(x2, y2, radius2);
	}
	void ShowRingInfo(void) {
		cout << "Inner Circle Info..." << endl;
		inner.ShowCircleInfo();
		cout << "Outter Circle Info..." << endl;
		outter.ShowCircleInfo();
	}
};
int main(void) {

	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
	
}