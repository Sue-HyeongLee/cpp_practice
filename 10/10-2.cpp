#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {
	}
	void ShowPosition() const {
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	
	Point& operator+= (const Point & pos) {
		xpos += pos.xpos, ypos += pos.ypos;
		return *this;
	}
	Point& operator-= (const Point& pos) {
		xpos -= pos.xpos, ypos -= pos.ypos;
		return *this;
	}
};




int main(void) {
	Point pos1(3, 4);
	Point pos2(10, 20);

	pos1.ShowPosition();
	pos2.ShowPosition();

	Point& pos3 = pos1 += pos2;
	pos3.ShowPosition();
	pos3 = pos1 -= pos2;
	pos3.ShowPosition();
	return 0;
}