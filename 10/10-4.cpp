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
	
	Point operator-() {
		Point pos(-xpos, -ypos);
		return pos;
	}
	friend Point operator~(Point& pos);
};

Point operator~(Point&pos) {
	Point npos(pos.ypos, pos.xpos);
	return npos;
}

int main(void) {
	
	Point pos1(3, 4);
	Point pos2 = -pos1;
	pos2.ShowPosition();

	Point pos3 = ~pos2;
	pos3.ShowPosition();
}