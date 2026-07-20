#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x=0, int y =0) :xpos(x), ypos(y){}
	void ShowPosition() const {
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}

};

template <class t1>
void SwapData(t1& data1, t1& data2) {
	t1 temp = data1;
	data1 = data2;
	data2 = temp;
}

int main(void) {
	Point point1(3, 4);
	Point point2(7, 2);

	SwapData(point1, point2);

	point1.ShowPosition();
	point2.ShowPosition();

}