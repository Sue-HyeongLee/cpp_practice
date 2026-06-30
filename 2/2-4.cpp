#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

typedef struct __Point {
	int xpos;
	int ypos;
} Point;

Point& PntAdder(const Point& p1, const Point& p2) {
	Point* point = new Point;
	point->xpos = p1.xpos + p2.xpos;
	point->ypos = p1.ypos + p2.ypos;

	return *point;
}

int main(void) {
	
	Point* point1 = new Point;
	point1->xpos = 2, point1->ypos = 3;

	Point* point2 = new Point;
	point2->xpos = 5, point2->ypos = 2;
	
	Point &point = PntAdder(*point1, *point2);
	cout << point.xpos << endl;
	cout << point.ypos << endl;

	delete point1;
	delete point2;
	delete &point; // delete는 pointer여야만 함.

}