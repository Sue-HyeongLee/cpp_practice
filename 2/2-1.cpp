#include <iostream>
using namespace std;

void Increase(int& num) {
	num += 1;
}
void Change(int& num) {
	num = -num;
}
int main(void) {
	int num = 3;
	Increase(num);
	cout << num << endl;
	Change(num);
	cout << num << endl;
	
}