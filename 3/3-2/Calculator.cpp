#define _CRT_SECURE_NO_WARNINGS
#include "Calculator.h"
#include <iostream>
using namespace std;

void Calculator::Init(void) {
	add = 0, sub = 0, mul = 0, div = 0;
}

double Calculator::Add(double x, double y) {
	add++;
	return x + y;
}
double Calculator::Min(double x, double y) {
	sub++;
	return x - y;
}
double Calculator::Mul(double x, double y) {
	mul++;
	return x * y;
}
double Calculator::Div(double x, double y) {
	div++;
	return x / y;
}

void Calculator::ShowOpCount(void) {
	cout << "µ¡¼À: " << add << " ";
	cout << "»¬¼À: " << sub << " ";
	cout << "°ö¼À: " << mul << " ";
	cout << "³ª´°¼À: " << div << " ";
}