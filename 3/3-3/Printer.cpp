#define _CRT_SECURE_NO_WARNINGS
#include "Printer.h"
#include <iostream>
#include <cstring>
using namespace std;
void Printer::SetString(const char* str2) {
	strcpy(str, str2);
}

void Printer::ShowString(void) {
	cout << str << endl;
}