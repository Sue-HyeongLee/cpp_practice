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
	
	friend bool operator==(Point& pos1, Point& pos2);
};

bool operator==(Point& pos1, Point& pos2) {
	if ((pos1.xpos == pos2.xpos) && (pos1.ypos == pos2.ypos))
		return true;
	else
		return false;
}

bool operator!=(Point& pos1, Point& pos2) {
	return !(pos1 == pos2);
}

int main(void) {
	Point pos1(3, 4);
	Point pos2(10, 20);

	if (pos1 != pos2) {
		cout << "3,4 10,20은 같지 않습니다." << endl;
	}
	
	Point pos3(10, 10);
	Point pos4(10, 10);
	if (pos3 == pos4)
		cout << "10,10은 서로 같습니다." << endl;
	
	return 0;
}