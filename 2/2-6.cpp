#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(void) {
	
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 5; i++)
		cout << rand() << endl;
}